/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : ADC             *************************/
/************************************************************************/
/************************************************************************/

#ifndef ACD_CONFIG_H_
#define ACD_CONFIG_H_


/*	choose :
 * 			1: Aref_pin
 * 			2: AVcc_pin
 * 			3: internal_volage
 * 			*/
#define voltage_ref		Aref_pin

/*	choose :
 * 			 1: _8_bit
 * 			 2: _10_bit
 * 			 			*/
#define Resluation		_8_bit

/*	choose
 * 			1:divide_by_2
 * 			2:divide_by_4
 * 			3:divide_by_8
 * 			4:divide_by_16
 * 			5:divide_by_32
 * 			6:divide_by_64
 * 			7:divide_by_128
 * 								*/
#define prescaler_val	divide_by_128

#define ADC_u32timeout	50000



#endif
