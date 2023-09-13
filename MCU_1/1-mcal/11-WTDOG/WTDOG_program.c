/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************  layer  : Mcal           	*************************/
/*******************  Version: 1.00         	*************************/
/*******************  SWC 	 : WTDOG          	*************************/
/************************************************************************/
/************************************************************************/


#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include "../../1-mcal/2-PORT/PORT_interface.h"

#include "WTDOG_config.h"
#include "WTDOG_interface.h"
#include "WTDOG_register.h"

void WTDOG_voidEnable(void)
{
	SET_BIT(WDTCR, WDTCR_WDE);
}
void WTDOG_voidDisable(void)
{
	WDTCR = 0b00011000;
	WDTCR = 0;

}
void WTDOG_voidSleep(u8 copy_u8SleepTime)
{
	if(copy_u8SleepTime < 8)
	{
		// Bit masking Sequence:
		// 1. clear the desired bits
		// 2. Put the required value in it
		WDTCR &= 0b01111000;
		WDTCR |= copy_u8SleepTime;
	}
}

