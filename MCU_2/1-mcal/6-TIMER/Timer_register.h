/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : TIMER             *************************/
/************************************************************************/
/************************************************************************/

#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_
/******************************** Timer0 registers ********************************/

#define TCCR0    		*((volatile u8*)0x53)		/*timer0 control rigster*/
#define TCCR0_WGM00		6							/*Wave generatoin mode 0*/
#define TCCR0_WGM01		3							/*Wave generatoin mode 0*/
#define TCCR0_CS02		2							/*parescale bit 2*/
#define TCCR0_CS01		1						    /*parescale bit 1*/
#define TCCR0_CS00		0							/*parescale bit 0*/
#define TCCR0_COM00		4
#define TCCR0_COM01		5


#define TCNT0 			*((volatile u8*)0x52)
#define OCR0			*((volatile u8*)0x5c)

#define TIMSK			*((volatile u8*)0x59)
#define TIMSK_OCIE0		1
#define TIMSK_OCIE2		7
#define TIMSK_TICIE1	5
/******************************** Timer1 registers ********************************/
#define TCCR1A			*((volatile u8*)0x4f)
#define TCCR1A_WGM10	0
#define TCCR1A_WGM11	1

#define TCCR1A_COM1A0	6
#define TCCR1A_COM1A1	7



#define TCCR1B			*((volatile u8*)0x4e)

#define TCCR1B_ICIS1	6
#define TCCR1B_WGM12	3
#define TCCR1B_WGM13	4


#define ICR1			*((volatile u16*)0x46)
#define OCR1A			*((volatile u16*)0x4a)

#define TCNT1			*((volatile u16*)0x4c)
/******************************** Timer2 registers ********************************/
#define TCCR2    		*((volatile u8*)0x45)		/*timer0 control rigster*/
#define TCCR2_WGM20		6							/*Wave generatoin mode 0*/
#define TCCR2_WGM21		3							/*Wave generatoin mode 0*/
#define TCCR2_CS22		2							/*parescale bit 2*/
#define TCCR2_CS21		1						    /*parescale bit 1*/
#define TCCR2_CS20		0							/*parescale bit 0*/
#define TCCR2_COM20		4
#define TCCR2_COM21		5


#define TCNT2 			*((volatile u8*)0x44)
#define OCR2			*((volatile u8*)0x43)



#endif
