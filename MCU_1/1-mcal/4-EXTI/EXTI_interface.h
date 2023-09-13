/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : EXTI             *************************/
/************************************************************************/
/************************************************************************/


#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_
/*choose mode:
 * 				1: for rising edge
 * 				2: for falling edge
 * 				3: for any_logic
 * 				4: for level_low
 * 				*/
#define level_low 		1
#define any_logic 		2
#define falling_edge 	3
#define rising_edge 	4

/* choose int_num :
 * 				1: for INT0
 * 				2: for INT1
 * 				3: for INT2
 * 								*/
#define	INT0		5
#define INT1		6
#define INT2		7

#define INT0_ID 	0
#define INT1_ID 	1
#define INT2_ID 	2



u8 	 EXTI_u8Int0_Pos(u8 copy_u8mode);
void EXTI_voidInt0_pre(void);

u8   EXTI_u8Int1_pos(u8 copy_u8mode);
void EXTI_voidInt1_pre(void);

u8 EXTI_u8Int2_pos(u8 copy_u8mode);
void EXTI_voidINT2_pre(void);

u8 EXTI_u8sense(u8 copy_u8mode,u8 copy_u8int_num);

void EXTI_voidclearflag(u8 copy_u8num);
u8 EXTI_u8ReadFlag(u8 copy_u8num);

u8 EXTI_u8Set_Callback(void (*copy_pvInt0)(void),u8 copy_int_id);



#endif
