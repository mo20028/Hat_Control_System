/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************        SWC : PORT          *************************/
/************************************************************************/
/************************************************************************/

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include "PORT_config.h"
#include "PORT_private.h"
#include "PORT_register.h"
#include "PORT_interface.h"

void PORT_voidInti(void)
{

	DDRA=PORTA_drive;
	DDRB=PORTB_drive;
	DDRC=PORTC_drive;
	DDRD=PORTD_drive;
	
	PORTA=PORTA_INTI_VALUE;
	PORTB=PORTB_INTI_VALUE;
	PORTC=PORTC_INTI_VALUE;
	PORTD=PORTD_INTI_VALUE;

}
