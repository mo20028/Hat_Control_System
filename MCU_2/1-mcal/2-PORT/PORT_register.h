/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************        SWC : PORT          *************************/
/************************************************************************/
/************************************************************************/

#ifndef PORT_INTERFACE_H_
#define PORT_INTERFACE_H_


#define PORTA 	*((volatile u8*) 0x3b)
#define DDRA 	*((volatile u8*) 0x3a)

#define PORTB   *((volatile u8*) 0x38)
#define DDRB 	*((volatile u8*) 0x37)

#define PORTC	*((volatile u8*) 0x35)
#define DDRC 	*((volatile u8*) 0x34)

#define PORTD 	*((volatile u8*) 0x32)
#define DDRD	*((volatile u8*) 0x31)






#endif