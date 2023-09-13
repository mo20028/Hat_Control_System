/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : TIMER             *************************/
/************************************************************************/
/************************************************************************/

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include  "Timer_config.h"
#include  "Timer_interface.h"
#include  "Timer_private.h"
#include  "Timer_register.h"



static void(*Timer_pv_SetCallBack[8])(void)={NULL};

void 	Timer_Inti(const Timer_config *copy_config)
{
	u8 local_errorstate=OK;

	if(copy_config->Timer_chennel==Timer0){
		TCCR0 &=0b11111000;
		TCCR0 |=copy_config->Timer_clock;
		if(copy_config->Timer_mode==Normal_mode)
		{
			/*set timer0 in normal mode*/
			CLR_BIT(TCCR0,TCCR0_WGM00);
			CLR_BIT(TCCR0,TCCR0_WGM01);
			/*enable interrupt*/
			SET_BIT(TIMSK,TIMSK_OCIE0);
			/*disable com*/
			CLR_BIT(TCCR0,TCCR0_COM00);
			CLR_BIT(TCCR0,TCCR0_COM01);
		}
		else if(copy_config->Timer_mode==PWM_phasecorect)
		{
			/*set timer0 in normal mode*/
			SET_BIT(TCCR0,TCCR0_WGM00);
			CLR_BIT(TCCR0,TCCR0_WGM01);
			/*clear on match set on top*/
			CLR_BIT(TCCR0,TCCR0_COM00);
			SET_BIT(TCCR0,TCCR0_COM01);
			/*set ocr0 value*/
			OCR0=copy_config->Timer_compare;
		}
		else if(copy_config->Timer_mode==CTC_mode)
		{

			/*set timer0 in normal mode*/
			CLR_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01);
			/*enable interrupt*/
			SET_BIT(TIMSK,TIMSK_OCIE0);
			/*set ocr0 value*/
			OCR0=copy_config->Timer_compare;
		}
		else if(copy_config->Timer_mode==fast_PWM)
		{
			/*set timer0 in normal mode*/
			SET_BIT(TCCR0,TCCR0_WGM00);
			SET_BIT(TCCR0,TCCR0_WGM01);
			/*clear on match set on top*/
			CLR_BIT(TCCR0,TCCR0_COM00);
			SET_BIT(TCCR0,TCCR0_COM01);
			/*set ocr0 value*/
			OCR0=copy_config->Timer_compare;
		}
		else
		{
			local_errorstate=NOK;
		}

	}


	else if(copy_config->Timer_chennel==Timer2){
		TCCR2 &=0b11111000;
		TCCR2 |=copy_config->Timer_clock;

		if(copy_config->Timer_mode==Normal_mode){
			CLR_BIT(TCCR2,TCCR2_WGM20);
			CLR_BIT(TCCR2,TCCR2_WGM21);
			/*enable interrup timer2*/
			SET_BIT(TIMSK,TIMSK_OCIE2);
			/*disable compare*/
			CLR_BIT(TCCR2,TCCR2_COM20);
			CLR_BIT(TCCR2,TCCR2_COM21);

		}
		else if(copy_config->Timer_mode==PWM_phasecorect){
			SET_BIT(TCCR2,TCCR2_WGM20);
			CLR_BIT(TCCR2,TCCR2_WGM21);

			/*clear on match set on top*/
			CLR_BIT(TCCR2,TCCR2_COM20);
			SET_BIT(TCCR2,TCCR2_COM21);
			/*set compare value*/
			OCR2=copy_config->Timer_compare;

		}
		else if(copy_config->Timer_mode==CTC_mode){
			CLR_BIT(TCCR2,TCCR2_WGM20);
			SET_BIT(TCCR2,TCCR2_WGM21);
			/*enable interrup timer2*/
			SET_BIT(TIMSK,TIMSK_OCIE2);
			/*set compare value*/
			OCR2=copy_config->Timer_compare;

		}
		else if(copy_config->Timer_mode==fast_PWM){
			SET_BIT(TCCR2,TCCR2_WGM20);
			SET_BIT(TCCR2,TCCR2_WGM21);
			/*clear on match set on top*/
			CLR_BIT(TCCR2,TCCR2_COM20);
			SET_BIT(TCCR2,TCCR2_COM21);
			/*set compare value*/
			OCR2=copy_config->Timer_compare;

		}
		else
		{

		}


	}



}



void Timer0_voidSetCompareMatch(u8 copy_u8value)
{
	OCR0=copy_u8value;

}
void Timer2_voidSetCompareMatch(u8 copy_u8value)
{
	OCR2=copy_u8value;
}


u8 Timer_u8SetCallBack(void (*copy_pvCallBackfun)(void),u8 copy_u8INT_ID)
{
	u8 local_errorstate=OK;
	if(copy_pvCallBackfun!= NULL)
	{
		Timer_pv_SetCallBack[copy_u8INT_ID]=copy_pvCallBackfun;
	}
	else
	{
		local_errorstate=NULL_POINTER;
	}



	return local_errorstate;

}
void Timer1_voidInt(void)
{
	/* set intervting mode*/
	SET_BIT(TCCR1A,TCCR1A_COM1A1);
	CLR_BIT(TCCR1A,TCCR1A_COM1A0);
	/*set wave form on fast PWm*/
	CLR_BIT(TCCR1A,TCCR1A_WGM10);
	SET_BIT(TCCR1A,TCCR1A_WGM11);
	SET_BIT(TCCR1B,TCCR1B_WGM12);
	SET_BIT(TCCR1B,TCCR1B_WGM13);

	/*set prescale*/
	TCCR1B &= 0b11111000;
	TCCR1B |=3;



}
void timer1_voidsetvalue(u16 copy_u16value)
{
	TCNT1=copy_u16value;
}
u16 timer1_u16readvalue(void)
{
	return TCNT1;
}
void Timer1_setICR(u16 copy_u16TOP)
{
	ICR1=copy_u16TOP;
}
void Timer1_chennelACompare(u16 copy_u16compare)
{
	OCR1A=copy_u16compare;
}
void ICU_inti(void)
{
	/*trigred source rising edge*/
	SET_BIT(TCCR1B,TCCR1B_ICIS1);

	SET_BIT(TIMSK,TIMSK_TICIE1);

}
u8 ICU_voidsetTirgrededge(u8 copy_u8edge)
{
	u8 local_errorstate=OK;
	if(copy_u8edge==ICU_rissing_edge)
	{
		SET_BIT(TCCR1B,TCCR1B_ICIS1);
	}
	else if(copy_u8edge==ICU_falling_edge)
	{
		CLR_BIT(TCCR1B,TCCR1B_ICIS1);
	}
	else
	{
		local_errorstate=NOK;
	}
	return local_errorstate;

}
void ICU_voidenableinterrupt(void)
{
	SET_BIT(TIMSK,TIMSK_TICIE1);
}
void ICU_voidDisableinterrupt(void)
{
	CLR_BIT(TIMSK,TIMSK_TICIE1);
}
u16 ICU_u16ReadingTimer(void)
{
	return ICR1;
}

/**************************** ISR for all interrupt in Timer peripheral **********************/
/*Timer/Counter2 Compare Match*/
void __vector_4 (void)		__attribute__ ((signal));
void __vector_4 (void)
{
	if(Timer_pv_SetCallBack[0]!=NULL)
	{
		Timer_pv_SetCallBack[0]();
	}
}
/*Timer/Counter2 Overflow*/
void __vector_5 (void)		__attribute__ ((signal));
void __vector_5 (void)
{
	if(Timer_pv_SetCallBack[1]!=NULL)
	{
		Timer_pv_SetCallBack[1]();
	}
}
/*Timer/Counter1 Capture Event*/
void __vector_6 (void)		__attribute__ ((signal));
void __vector_6 (void)
{
	if(Timer_pv_SetCallBack[2]!=NULL)
	{
		Timer_pv_SetCallBack[2]();
	}
}
/*Timer/Counter1 Compare Match A*/
void __vector_7 (void)		__attribute__ ((signal));
void __vector_7 (void)
{
	if(Timer_pv_SetCallBack[3]!=NULL)
	{
		Timer_pv_SetCallBack[3]();
	}
}
/*Timer/Counter1 Compare Match B*/
void __vector_8 (void)		__attribute__ ((signal));
void __vector_8 (void)
{
	if(Timer_pv_SetCallBack[4]!=NULL)
	{
		Timer_pv_SetCallBack[4]();
	}
}
/*Timer/Counter1 Overflow*/
void __vector_9 (void)		__attribute__ ((signal));
void __vector_9 (void)
{
	if(Timer_pv_SetCallBack[5]!=NULL)
	{
		Timer_pv_SetCallBack[5]();
	}
}
/*Timer/Counter0 Compare Match*/
void __vector_10 (void)		__attribute__ ((signal));
void __vector_10 (void)
{
	if(Timer_pv_SetCallBack[6]!= NULL)
	{
		Timer_pv_SetCallBack[6]();
	}
}
/*Timer/Counter0 Overflow*/
void __vector_11 (void)		__attribute__ ((signal));
void __vector_11 (void)
{
	if(Timer_pv_SetCallBack[7]!=NULL)
	{
		Timer_pv_SetCallBack[7]();
	}
}

