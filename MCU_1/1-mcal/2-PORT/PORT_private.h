/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************        SWC : PORT          *************************/
/************************************************************************/
/************************************************************************/

#ifndef PORT_PRIVATE_h_
#define PORT_PRIVATE_h_


#define CONC(b7,b6,b5,b4,b3,b2,b1,b0)       		CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)
#define CONC_HELPER(b7,b6,b5,b4,b3,b2,b1,b0)		0b##b7##b6##b5##b4##b3##b2##b1##b0

#define PORTA_drive						CONC(PORTA_PIN7_dir,PORTA_PIN6_dir,PORTA_PIN5_dir,PORTA_PIN4_dir,PORTA_PIN3_dir,PORTA_PIN2_dir,PORTA_PIN1_dir,PORTA_PIN0_dir)
#define PORTB_drive						CONC(PORTB_PIN7_dir,PORTB_PIN6_dir,PORTB_PIN5_dir,PORTB_PIN4_dir,PORTB_PIN3_dir,PORTB_PIN2_dir,PORTB_PIN1_dir,PORTB_PIN0_dir)
#define PORTC_drive						CONC(PORTC_PIN7_dir,PORTC_PIN6_dir,PORTC_PIN5_dir,PORTC_PIN4_dir,PORTC_PIN3_dir,PORTC_PIN2_dir,PORTC_PIN1_dir,PORTC_PIN0_dir)
#define PORTD_drive						CONC(PORTD_PIN7_dir,PORTD_PIN6_dir,PORTD_PIN5_dir,PORTD_PIN4_dir,PORTD_PIN3_dir,PORTD_PIN2_dir,PORTD_PIN1_dir,PORTD_PIN0_dir)

#define PORTA_INTI_VALUE				CONC(PORTA_PIN7_INTI_VALUE,PORTA_PIN6_INTI_VALUE,PORTA_PIN5_INTI_VALUE,PORTA_PIN4_INTI_VALUE,PORTA_PIN3_INTI_VALUE,PORTA_PIN2_INTI_VALUE,PORTA_PIN1_INTI_VALUE,PORTA_PIN0_INTI_VALUE)
#define PORTB_INTI_VALUE				CONC(PORTB_PIN7_INTI_VALUE,PORTB_PIN6_INTI_VALUE,PORTB_PIN5_INTI_VALUE,PORTB_PIN4_INTI_VALUE,PORTB_PIN3_INTI_VALUE,PORTB_PIN2_INTI_VALUE,PORTB_PIN1_INTI_VALUE,PORTB_PIN0_INTI_VALUE)
#define PORTC_INTI_VALUE				CONC(PORTC_PIN7_INTI_VALUE,PORTC_PIN6_INTI_VALUE,PORTC_PIN5_INTI_VALUE,PORTC_PIN4_INTI_VALUE,PORTC_PIN3_INTI_VALUE,PORTC_PIN2_INTI_VALUE,PORTC_PIN1_INTI_VALUE,PORTC_PIN0_INTI_VALUE)
#define PORTD_INTI_VALUE				CONC(PORTD_PIN7_INTI_VALUE,PORTD_PIN6_INTI_VALUE,PORTD_PIN5_INTI_VALUE,PORTD_PIN4_INTI_VALUE,PORTD_PIN3_INTI_VALUE,PORTD_PIN2_INTI_VALUE,PORTD_PIN1_INTI_VALUE,PORTD_PIN0_INTI_VALUE)



#endif
