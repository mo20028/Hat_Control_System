/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal           *************************/
/*******************     Version : 1.00         *************************/
/*******************        SWC : DIO           *************************/
/************************************************************************/
/************************************************************************/



#define DIO_u8PIN_HIGH      1
#define DIO_u8PIN_LOW       0



#define DIO_u8PORT_HIGH     0xff
#define DIO_u8PORT_LOW      0

#define DIO_u8PORTA         0
#define DIO_u8PORTB         1
#define DIO_u8PORTC         2
#define DIO_u8PORTD         3

#define DIO_u8PIN0          0
#define DIO_u8PIN1          1
#define DIO_u8PIN2          2
#define DIO_u8PIN3          3
#define DIO_u8PIN4          4
#define DIO_u8PIN5          5
#define DIO_u8PIN6          6
#define DIO_u8PIN7          7

#define source    1
#define sink      0

#define active_high 1
#define active_low  0

#ifndef _DIO_INTERFACE_h
#define _DIO_INTERFACE_h



u8 setbitvalue(u8 copy_U8port,u8 copy_u8pin,u8 copy_u8value);
u8 setportvalue (u8 copy_u8port,u8 copy_u8value);

u8 getbit (u8 copy_port ,u8 copy_pin,u8* copy_value);




#endif
