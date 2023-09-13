/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : ADC             *************************/
/************************************************************************/
/************************************************************************/


#ifndef   ADC_INTERFACE_H_
#define   ADC_INTERFACE_H_

#define ADC0				0
#define ADC1				1
#define ADC2				2
#define ADC3				3
#define ADC4				4
#define ADC5				5
#define ADC6				6
#define ADC7				7
#define ADC8				8


typedef struct
{
	u8* chennels;
	u16* result;
	u8 size;
	void (*notification_fun)(void);

}chain_t;
void  ADC_voidinti(void);

/* function: put chennel reading after complete conversion
 * input :Channel and Gain Selections
 * 		  choose :
 * 		     > Single Ended Input
 * 		     		 1:ADC0 / 2:ADC1 / 3:ADC2 / 4:ADC3
 	 	 	 	 	 5:ADC4 / 6:ADC5 / 7:ADC6 / 8:ADC7
 	 	 	 > Differential
 * 		     		*/
u16   ADC_u8startconversionsync(u8 copy_u8chennel, u16* copy_pu8Reading);
u8   ADC_u8startcoversionAsync(u8 copy_u8chennel, u8* copy_pu8Reading,void (*copy_pv_not)(void));
u8 	ADC_u8startchainAsync(chain_t *copy_chain);



#endif
