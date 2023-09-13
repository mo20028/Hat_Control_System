/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************  layer  : Mcal           	*************************/
/*******************  Version: 1.00         	*************************/
/*******************  SWC 	 : EEPROM          	*************************/
/************************************************************************/
/************************************************************************/

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include "EEPROM_config.h"
#include "EEPROM_interface.h"
#include "EEPROM_private.h"
#include "EEPROM_register.h"


void EEPROM_voidWrite_Byte(u8 copy_u8Data, u16 copy_u16Address)
{

	/* Wait for completion of previous write */
	while(EECR & (1<<EECR_EEWE))
	;
	/* Set up address and data registers */
	EEAR = copy_u16Address;
	EEDR = copy_u8Data;
	/* Write logical one to EEMWE */
	EECR =EEMWE;
	//asm("SBI 0x1C,2");
	/* Start eeprom write by setting EEWE */
	EECR =EEWE;
	//asm("SBI 0x1C,1");
}

void EEPROM_voidRead_Byte(u8 *copy_pvData, u16 copy_u16Address)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EECR_EEWE));
	while(SPMCR & (1<<SPMCR_SPMEN));
	/* Set up address and data registers */
	EEAR = copy_u16Address;
	/* Start eeprom read by writing EERE */
	EECR |= (1<<EECR_EERE);
	*copy_pvData=EEDR;


}
