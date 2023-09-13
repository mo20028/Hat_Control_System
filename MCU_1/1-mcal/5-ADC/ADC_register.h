/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : ADC             *************************/
/************************************************************************/
/************************************************************************/

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define  ADCL				*((volatile u8*)0x24)	   // ADC low  register
#define  ADCH				*((volatile u8*)0x25) 	   // ADC high register

#define  ADC				*((volatile u16*)0x24)	   //ADC register both high and low


#define  ADCSRA				*((volatile u8*)0x26)	   // ADC control and status register a
#define  ADCSRA_ADEN		7                          // ADC enable
#define  ADCSRA_ADSC		6                          // start convertion
#define  ADCSRA_ADATE		5                          // auto trigger enable
#define  ADCSRA_ADIF		4                          // ADC interrupt flag
#define  ADCSRA_ADIE		3                          // ADC interrupt enable
#define  ADCSRA_ADPS2		2                          // prescaler bit2
#define  ADCSRA_ADPS1		1                          // prescaler bit1
#define  ADCSRA_ADPS0		0                          // prescaler bit0


#define  ADMUX				*((volatile u8*)0x27)  	   //ADC mux register selection
#define  ADMUX_REFS1		7						   //reference selection bit1
#define  ADMUX_REFS0		6						   //reference selection bit0
#define  ADMUX_ADLAR		5						   //ADC left adjacent result


#define  ACSR				*((volatile u8*)0x28)




#endif
