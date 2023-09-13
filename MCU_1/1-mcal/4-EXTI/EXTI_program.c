/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : EXTI             *************************/
/************************************************************************/
/************************************************************************/
#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include  "EXTI_config.h"
#include  "EXTI_interface.h"
#include  "EXTI_private.h"
#include  "EXTI_register.h"

void(*EXTI_pvISR_int0)(void) = NULL;
void(*EXTI_pvISR_int1)(void) = NULL;
void(*EXTI_pvISR_int2)(void) = NULL;
void(*EXTI_pv_int[3])(void)={NULL};


u8 EXTI_u8Int0_Pos(u8 copy_u8mode)
{
	u8 Local_u8error=OK;
	switch(copy_u8mode)
	{
	case level_low:
		CLR_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		break;
	case any_logic:
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		break;
	case rising_edge:
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
		break;
	case falling_edge:
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
		break;
	default:
		Local_u8error=NOK;
		break;
	}
	SET_BIT(GICR,GICR_INT0);
	return Local_u8error;
}
void EXTI_voidInt0_pre(void)
{
#if INT0_sense ==level_low
	CLR_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_sense == any_logic
	SET_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);
#elif INT0_sense == falling_edge
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
#elif INT0_sense == rising_edge
	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);
#el
#error "worng int0_sence cong";
#endif

#if INT0_intive==enabled
	SET_BIT(GICR,GICR_INT0);
#elif INT1_intive==disabled
	CLR_BIT(GICR,GICR_INT0);
#el
#error "worng INT0_inti_value"
#endif

}


u8   EXTI_u8Int1_pos(u8 copy_u8mode)
{
	u8 local_u8erorr=OK;
	switch(copy_u8mode)
	{
	case level_low:
		CLR_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);
		break;
	case any_logic:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
	case rising_edge:
		SET_BIT(MCUCR,MCUCR_ISC11);
		SET_BIT(MCUCR,MCUCR_ISC10);
		break;
	case falling_edge:
		SET_BIT(MCUCR,MCUCR_ISC11);
		CLR_BIT(MCUCR,MCUCR_ISC10);
		break;
	default:
		local_u8erorr=NOK;
		break;
	}

	/*SIE for int1 */
	SET_BIT(GICR,GICR_INT1);
	return local_u8erorr;

}
void EXTI_voidInt1_pre(void)
{
#if INT1_sense ==level_low
	CLR_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
#elif INT0_sense == any_logic
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
#elif INT0_sense == falling_edge
	SET_BIT(MCUCR,MCUCR_ISC11);
	CLR_BIT(MCUCR,MCUCR_ISC10);
#elif INT0_sense == rising_edge
	SET_BIT(MCUCR,MCUCR_ISC11);
	SET_BIT(MCUCR,MCUCR_ISC10);
#el
#error "worng int1_sence cong";
#endif

#if INT1_intive==enabled
	SET_BIT(GICR,GICR_INT1);
#elif INT1_intive==disabled
	CLR_BIT(GICR,GICR_INT1);
#el
#error "worng INT1_inti_value"
#endif


}


u8 EXTI_u8Int2_pos(u8 copy_u8mode)
{
	u8 local_u8error=OK;
	switch(copy_u8mode)
	{
	case falling_edge: CLR_BIT(MCUCSR,MCUCSR_INT2); break;
	case rising_edge:  SET_BIT(MCUCSR,MCUCSR_INT2); break;
	default: local_u8error=NOK;
	}

	/* active SIE for int2 */
	SET_BIT(GICR,GICR_INT2);
	return local_u8error;
}
void EXTI_voidINT2_pre(void)
{
#if INT2_sense==falling_edge
	CLR_BIT(MCUCSR,MCUCSR_INT2);
#elif	INT2_sense==rising_edge
	SET_BIT(MCUCSR,MCUCSR_INT2);
#el
#error "worng in INTI2_sense"
#endif

#if INT2_intive==enabled
	SET_BIT(GICR,GICR_INT2);
#elif INT2_intive==disabled
	CLR_BIT(GICR,GICR_INT2);
#el
#error "worng in INT2_intivalue "
#endif

}

u8 EXTI_u8sense(u8 copy_u8mode,u8 copy_u8int_num)
{
	u8 local_u8error=OK;

	if(copy_u8int_num==INT0)
	{
		switch(copy_u8mode)
		{
		case level_low:    CLR_BIT(MCUCR,MCUCR_ISC01); CLR_BIT(MCUCR,MCUCR_ISC00); break;
		case any_logic:    SET_BIT(MCUCR,MCUCR_ISC00); CLR_BIT(MCUCR,MCUCR_ISC01); break;
		case rising_edge:  SET_BIT(MCUCR,MCUCR_ISC01); SET_BIT(MCUCR,MCUCR_ISC00); break;
		case falling_edge: SET_BIT(MCUCR,MCUCR_ISC01); CLR_BIT(MCUCR,MCUCR_ISC00); break;
		default:           local_u8error=NOK;   break;
		}
		/*SIE for int0 */
		SET_BIT(GICR,GICR_INT0);
	}
	else if(copy_u8int_num==INT1)
	{
		switch(copy_u8mode)
		{
		case level_low:    CLR_BIT(MCUCR,MCUCR_ISC11); CLR_BIT(MCUCR,MCUCR_ISC10); break;
		case any_logic:    SET_BIT(MCUCR,MCUCR_ISC10); CLR_BIT(MCUCR,MCUCR_ISC11); break;
		case rising_edge:  SET_BIT(MCUCR,MCUCR_ISC11); SET_BIT(MCUCR,MCUCR_ISC10); break;
		case falling_edge: SET_BIT(MCUCR,MCUCR_ISC11); CLR_BIT(MCUCR,MCUCR_ISC10); break;
		default:           local_u8error=NOK;		break;
		}

		/*SIE for int1 */
		SET_BIT(GICR,GICR_INT1);
	}
	else if(copy_u8int_num==INT2)
	{
		switch(copy_u8mode)
		{
		case falling_edge: CLR_BIT(MCUCSR,MCUCSR_INT2); break;
		case rising_edge:  SET_BIT(MCUCSR,MCUCSR_INT2); break;
		default: local_u8error=NOK;
		}

		/* active SIE for int2 */
		SET_BIT(GICR,GICR_INT2);

	}
	else
	{
		local_u8error=NOK;
	}

	return local_u8error;
}

void EXTI_voidclearflag(u8 copy_u8num)
{
	if(copy_u8num==0){
		CLR_BIT(GIFR,GICR_INT0);
	}
	else if(copy_u8num==1){
		CLR_BIT(GIFR,GICR_INT1);
	}
	else{
		CLR_BIT(GIFR,GICR_INT2);
	}

}
u8 EXTI_voidReadFlag(u8 copy_u8num)
{
	u8 flag;
	if(copy_u8num==0){
		flag=GET_BIT(GIFR,GICR_INT0);
	}
	else if(copy_u8num==1){
		flag=GET_BIT(GIFR,GICR_INT1);
	}
	else{
		flag=GET_BIT(GIFR,GICR_INT2);
	}
	return flag;
}


u8 EXTI_u8Set_Callback(void (*copy_pvInt0)(void),u8 copy_int_id)
{
	u8 Local_u8error=OK;
	if(copy_pvInt0 != NULL)
	{
		EXTI_pv_int[copy_int_id]=copy_pvInt0;
	}
	else
	{
		Local_u8error=NULL_POINTER;
	}


	return Local_u8error;
}


void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pv_int[0]!=NULL)
	{
		EXTI_pv_int[0]();
	}
	else{
		/* DO nothing */
	}

}
void __vector_2 (void) __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pv_int[1]!=NULL)
	{
		EXTI_pv_int[1]();
	}
}
void __vector_3 (void) __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pv_int[2]!=NULL)
	{
		EXTI_pv_int[2]();
	}
}






