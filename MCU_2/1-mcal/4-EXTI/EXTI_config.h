/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : EXTI             *************************/
/************************************************************************/
/************************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONGIG_H_

/*modes choose:
 * 				0 for rasing edge
 * 				*/
/*#define  level_low		3
#define  any_logic		2
#define  rising_edge    0
#define  falling_edge   1*/

/*choose
			1.level_low
			2.any_logic
			3.falling_edge
			4.rising_edge 
			*/

#define INT0_sense	falling_edge
#define INT0_intiva	enabled

#define INT1_sense  falling_edge
#define INT1_intive enabled

#define INT2_sense  falling_edge
#define INT2_intive enabled



#endif
