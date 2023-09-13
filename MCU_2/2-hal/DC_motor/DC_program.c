/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : DC_MOTOR         *************************/
/************************************************************************/
/************************************************************************/

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"


#include "DC_config.h"
#include  "DC_interface.h"
#include  "DC_private.h"

#include "../../1-mcal/2-PORT/PORT_interface.h"
#include "../../1-mcal/1-DIO/DIO_interface.h"

static void clockwise();
static void unclockwise();

static void clockwise()
{
	setbitvalue(DC_motor_port, DC_MOTOR_pin1, DIO_u8PIN_LOW);
	setbitvalue(DC_motor_port, DC_MOTOR_pin0, DIO_u8PIN_HIGH);
}
static void unclockwise()
{
	setbitvalue(DC_motor_port, DC_MOTOR_pin0, DIO_u8PIN_LOW);
	setbitvalue(DC_motor_port, DC_MOTOR_pin1, DIO_u8PIN_HIGH);
}
void stop_DC()
{
	setbitvalue(DC_motor_port, DC_MOTOR_pin0, DIO_u8PIN_LOW);
	setbitvalue(DC_motor_port, DC_MOTOR_pin1, DIO_u8PIN_LOW);
}
u8   DC_u8dircotrol(u8 copy_u8direction)
{
	u8 local_errorstate=OK;
	if(copy_u8direction==CW)
	{
		clockwise();
	}
	else if(copy_u8direction==CCW)
	{
		unclockwise();
	}
	else
	{
		local_errorstate=NOK;
	}

	return	local_errorstate;
}
