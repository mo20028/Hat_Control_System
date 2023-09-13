/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************        SWC : CLCD          *************************/
/************************************************************************/
/************************************************************************/

#ifndef  CLCD_CONFIG_H_
#define  CLCD_CONFIG_H_

#define CLCD_DATA_PORT     DIO_u8PORTC
#define CLCD_DATA_pin4     DIO_u8PIN4
#define CLCD_DATA_pin5     DIO_u8PIN5
#define CLCD_DATA_pin6     DIO_u8PIN6
#define CLCD_DATA_pin7     DIO_u8PIN7

#define CLCD_CLR_PORT     DIO_u8PORTC
#define CLCD_RS_PIN   	DIO_u8PIN0
#define CLCD_RW_PIN   	DIO_u8PIN1
#define CLCD_E_PIN   	DIO_u8PIN2

#define Right			0
#define Left			1

#define mode			1		/* 0 for eight bit mode
								/	1 for four bit mode*/


#define CLEAR_COMMAND 0x01





#endif
