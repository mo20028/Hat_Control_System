/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : SERVO_MOTOR      *************************/
/************************************************************************/
/************************************************************************/

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"
#include "../../libr/map.h"


#include "Servo_config.h"
#include "Servo_inteface.h"
#include "Servo_private.h"

#include "../../1-mcal/2-PORT/PORT_interface.h"
#include "../../1-mcal/1-DIO/DIO_interface.h"
#include "../../1-mcal/6-TIMER/Timer_interface.h"

u8 Servo_u8Angle(u16 copy_u16angle)
{
	u8 localerrorstate=OK;
	u16 comparevalue;
	if(copy_u16angle>=0&&copy_u16angle<=180)
	{
		comparevalue=map(0, 180, 125, 250, copy_u16angle);
		Timer1_setICR(20000);
		Timer1_chennelACompare(comparevalue);
	}
	else
	{
		localerrorstate=NOK;
	}

	return localerrorstate;
}
