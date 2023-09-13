/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : ADC             *************************/
/************************************************************************/
/************************************************************************/


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define Aref_pin				   1
#define AVcc_pin			       2
#define internal_volage			   3


#define _8_bit					   4
#define _10_bit					   5

#define clear_prescaler_mask       0b11111000
#define clear_mux_mask		       0b11100000

#define divide_by_2  		       0x1
#define divide_by_4  		       0x2
#define divide_by_8  		       0x3
#define divide_by_16 		       0x4
#define divide_by_32 		       0x5
#define divide_by_64 		       0x6
#define divide_by_128		       0x7

#define ADC0				       0
#define ADC1				       1
#define ADC2				       2
#define ADC3				       3
#define ADC4				       4
#define ADC5				       5
#define ADC6				       6
#define ADC7				       7
#define ADC8				       8

#define idle				       1
#define busy				       2

#define ADC_u8SingalChennel        1
#define ADC_u8chainChennel         2

#endif
