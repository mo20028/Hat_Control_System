/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : TIMER             *************************/
/************************************************************************/
/************************************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/*choose for Timer_chennel*/
#define Timer0			0
#define Timer1			1
#define Timer2			2

/*choose for Timer_mode */
#define Normal_mode		0
#define PWM_phasecorect 1
#define CTC_mode		2
#define fast_PWM		3

/*choose for parascale */
typedef enum
{
	no_clk,no_para,divid_8,divid_64,divid_256,divid_1024,ex_falling_edg,ex_rasing_edg
	,t2_no_clk=0,t2_noPara,t2_divid_8,t2_divid_32,t2_divid_64,t2_divid_128,
	t2_divid_256,t2_divid_1024
}Timer_clk;
typedef struct
{
	u8  Timer_chennel;
	u8  Timer_mode;
	u16 Timer_compare;
	Timer_clk Timer_clock;

}Timer_config;

/* enum used for choose source of interrut*/
typedef enum{
	T2_compare,T2_overflow,ICU_capture,T1_compare_A,
	T1_compar_B,T1_overflow,T0_compare,T0_overflow

}Timer_INT_ID;



#define ICU_rissing_edge	1
#define ICU_falling_edge	0


void 	Timer1_voidInt					(void);
void 	Timer1_setICR					(u16 copy_u16TOP);
void 	Timer1_chennelACompare			(u16 copy_u16compare);
u8 Timer_u8SetCallBack(void (*copy_pvCallBackfun)(void),u8 copy_u8INT_ID);

void 	timer1_voidsetvalue				(u16 copy_u16value);
u16 	timer1_u16readvalue				(void);
void 	ICU_inti						(void);
u8 		ICU_voidsetTirgrededge			(u8 copy_u8edge);
void 	ICU_voidDisableinterrupt		(void);
void 	ICU_voidenableinterrupt			(void);
u16 	ICU_u16ReadingTimer				(void);

/* this function is inti for timer0 and timer2 only for now */
void 	Timer_Inti(const Timer_config *copy_config);
void Timer0_voidSetCompareMatch(u8 copy_u8value);
void Timer2_voidSetCompareMatch(u8 copy_u8value);






#endif
