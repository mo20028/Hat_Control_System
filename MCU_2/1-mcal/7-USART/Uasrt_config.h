/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : USART            *************************/
/************************************************************************/
/************************************************************************/

#ifndef UASRT_CONFIG_H_
#define UASRT_CONFIG_H_
/* Uart_mode choose between:
 * 							1:Asynchronous
 * 							2:Synchronous	*/
#define Uart_mode	Asynchronous
/* Char_Size choose :
 * 						1:_5_bit
 * 						2:_6_bit
 * 						3:_7_bit
 * 						4:_8_bit
 *
 */
#define Char_Size		_8_bit
/* Stop_bit choose between:
 * 							_1_bit
 *							_2_bit
 * 							*/
#define Stop_Bit		_1_bit
/* Char_Size choose :
 * 						1:disable
 * 						2:Even
 * 						3:Odd
 */
#define Parity			disable
/* write number for Boadrate  :
 * 						1:103 -> B_4.8k
 * 						2:51  -> B_9.6k
 * 						3:25  -> B_19.2k
 * 						4:12  -> B_38.4k
 *                      5:8   -> B_57.6k
 */
#define Boadrate				51
#define Uart_u32Time_out		5000000


#endif
