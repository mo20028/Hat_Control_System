/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************  layer  : Mcal           	*************************/
/*******************  Version: 1.00         	*************************/
/*******************  SWC 	 : EEPROM          	*************************/
/************************************************************************/
/************************************************************************/
#ifndef EEPROM_REGISTER_H_
#define EEPROM_REGISTER_H_

#define EEARH   		*((volatile u8*)0x3f)
#define EEARL   		*((volatile u8*)0x3e)
#define EEAR			*((volatile u16*)0x3e)

#define EEDR			*((volatile u8*)0x3d)
#define EECR			*((volatile u8*)0x3c)
#define EECR_EERE		0
#define EECR_EEWE		1
#define EECR_EEMWE		2
#define EECR_EERIE		3

#define SPMCR			*((volatile u8*)0x57)
#define SPMCR_SPMEN		0



#endif
