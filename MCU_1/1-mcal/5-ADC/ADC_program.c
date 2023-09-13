/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : ADC             *************************/
/************************************************************************/
/************************************************************************/


#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include  "ADC_config.h"
#include  "ADC_interface.h"
#include  "ADC_private.h"
#include  "ADC_register.h"

static u8* 			ADC_pu16_Reading=NULL;
static void   		(*ADC_pv_not)(void)=NULL;
u8 					ADC_u8busy_state=idle;
static u8*			ADC_pu8chainchennel_arr=NULL;
static u8 			ADC_u8chainsize;
static u16* 		ADC_p16chainresultarr=NULL;
static u8 			ADC_u8chainIndex;
static u8 			ADC_u8ISRsource;


void   ADC_voidinti(void)
{
	/* set reference voltage */
#if voltage_ref == Aref_pin		    	/* Aref as reference voltage */
	CLR_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif voltage_ref == AVcc_pin			/* AVcc as reference voltage */
	SET_BIT(ADMUX,ADMUX_REFS0);
	CLR_BIT(ADMUX,ADMUX_REFS1);
#elif voltage_ref == internal_volage 	/* 2.56 as reference voltage */
	SET_BIT(ADMUX,ADMUX_REFS0);
	SET_BIT(ADMUX,ADMUX_REFS1);
#el
#error " wrong voltage_reg value "
#endif

	/*SET resulation 8_bit or 10_bit result */
#if Resluation == _8_bit
	SET_BIT(ADMUX,ADMUX_ADLAR);
#elif Resluation == _10_bit
	CLR_BIT(ADMUX,ADMUX_ADLAR);
#else
#error "wrong adjacent value "
#endif

	/* SET  ADC Prescaler Selections  */
	ADCSRA &=clear_prescaler_mask;
	ADCSRA |=prescaler_val;

	/* enable ADC*/
	SET_BIT(ADCSRA,ADCSRA_ADEN);

}


u16   ADC_u8startconversionsync(u8 copy_u8chennel, u16* copy_pu8Reading)
{
	u32 local_conuter=0;
	u8 error_state=OK;
	if(ADC_u8busy_state==idle){
		/*make busy state busy */
		ADC_u8busy_state=busy;
		/* clear the mux bit in ADMUX register */
		ADMUX &= clear_mux_mask;

		/* set requie chennel in the Mux bits */
		ADMUX |= copy_u8chennel;

		/* start conversion */
		SET_BIT(ADCSRA,ADCSRA_ADSC);

		/*polling utile complete flag is set */
		while(((GET_BIT(ADCSRA,ADCSRA_ADIF))==0) && local_conuter!=ADC_u32timeout)
		{
			local_conuter++;
		}
		if(local_conuter==ADC_u32timeout)
		{
			/* loop breaking as timeout*/
			error_state=NOK;
		}
		else
		{
			/* clear the conversion complete flag */
			SET_BIT(ADCSRA,ADCSRA_ADIF);
			if(Resluation==_10_bit)
			{
			   *copy_pu8Reading=ADC;
			}
			else
			{
				 *copy_pu8Reading=ADCH;
			}
			/*make ADC busy state idle*/
			ADC_u8busy_state=idle;
		}
	}
	else
	{
		local_conuter=busy_function;
	}


	return error_state;


}
u8   ADC_u8startcoversionAsync(u8 copy_u8chennel, u8* copy_pu8Reading,void (*copy_pv_not)(void))
{

	u8 local_errorstate=OK;
	if(ADC_u8busy_state==idle){
		if(copy_pu8Reading==NULL ||copy_pv_not==NULL)
		{
			local_errorstate=NULL_POINTER;
		}
		else
		{
			/* change ADC_u8busystate*/
			ADC_u8busy_state=busy;
			/*make ADC singalchennel */
			ADC_u8ISRsource=ADC_u8SingalChennel;
			/* intialization Reading varibale*/
			ADC_pu16_Reading=copy_pu8Reading;

			/* intialization notafication function */
			ADC_pv_not=copy_pv_not;
			/* clear the mux bit in ADMUX register */
			ADMUX &= clear_mux_mask;

			/* set requie chennel in the Mux bits */
			ADMUX |= copy_u8chennel;

			/* start conversion */
			SET_BIT(ADCSRA,ADCSRA_ADSC);
			/*enable ADC interrupt*/
			SET_BIT(ADCSRA,ADCSRA_ADIE);
		}
	}
	else
	{
		local_errorstate=busy_function;
	}
	return local_errorstate;
}



u8 	ADC_u8startchainAsync(chain_t *copy_chain)
{
	u8 local_errorstate=OK;
	if(copy_chain!=NULL)
	{
		if(ADC_u8busy_state==idle)
		{
			/* Make ADC Busy*/
			ADC_u8busy_state=busy;
			/*make ADC_isr source chain*/
			ADC_u8ISRsource=ADC_u8chainChennel;
			/*inti chennel arr*/
			ADC_pu8chainchennel_arr=copy_chain->chennels;

			/*inti reuslt arr*/
			ADC_p16chainresultarr=copy_chain->result;
			/*inti size of the chain*/
			ADC_u8chainsize=copy_chain->size;
			/*inti notification function */
			ADC_pv_not=copy_chain->notification_fun;
			/* inti Chainidex*/
			ADC_u8chainIndex=0;
			/*set required channel*/
			ADMUX &=clear_mux_mask;
			ADMUX =ADC_pu8chainchennel_arr[ADC_u8chainIndex];

			/*statr conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);

			/*enable ADC interrupt */
			SET_BIT(ADCSRA,ADCSRA_ADIE);

		}
		else
		{
			local_errorstate=busy_function;
		}

	}
	else
	{
		local_errorstate==NULL_POINTER;
	}


	return local_errorstate;

}
void __vector_16 (void) __attribute__((signal));
void __vector_16 (void)
{
	if(ADC_u8ISRsource==ADC_u8SingalChennel){
		/*read ADC result */
		*ADC_pu16_Reading=ADCH;

		/* invoke the notificantion funcation */
		ADC_pv_not();
		/* make ADC state idle */
		ADC_u8busy_state=idle;
		/*disable ADC conversion commpelet interrupt*/
		CLR_BIT(ADCSRA,ADCSRA_ADIE);
	}
	else if(ADC_u8ISRsource==ADC_u8chainChennel)
	{
		/*read the current chennel*/
		ADC_p16chainresultarr[ADC_u8chainIndex]=ADC;
		/*increament chain index*/
		ADC_u8chainIndex++;
		if(ADC_u8chainIndex==ADC_u8chainsize)
		{
			/*make ADC idle*/
			ADC_u8busy_state=idle;
			/* invoke the notificantion funcation */
			ADC_pv_not();
			/* disable the ADC interrupt */
			CLR_BIT(ADCSRA,ADCSRA_ADIE);

		}
		else
		{
			/*chain not finished */
			ADMUX &= clear_mux_mask;
			ADMUX =ADC_pu8chainchennel_arr[ADC_u8chainIndex];

			/*start new conversion*/
			SET_BIT(ADCSRA,ADCSRA_ADSC);
		}




	}
}
