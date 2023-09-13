/*
 * file_name  : MCU_2.c
 *
 * Author:		Mohamed Shaban
 *
 *
 * Description: Temperature Control System using Atmega32 (MCU2)
 * Main Features:
 * - Receives control commands from MCU1 over UART communication.
 * - Controls LEDs to indicate system status.
 * - Controls a servo motor for specific actions.
 * - Reads temperature-related data from an ADC sensor.
 * - Implements safety measures and responses based on received commands.
 *
 * Components Used:
 * - Atmega32 Microcontroller.
 * - LEDs for status indication.
 * - Servo Motor for specific actions.
 * - ADC for reading temperature-related data.
 * - UART communication for command exchange with MCU1.
 *
 * Software Driver:
 * - Port_Driver
 * - Dio_Driver
 * - ADC_Driver
 * - Timer_Driver
 * - UASRT_Driver
 *
 */


/*******************	include section begin	**********************/
#include "libr/STD_types.h"
#include "libr/BIT_math.h"
#include "libr/map.h"

#include "1-mcal/1-DIO/DIO_interface.h"
#include "1-mcal/2-PORT/PORT_interface.h"
#include "1-mcal/5-ADC/ADC_interface.h"
#include "1-mcal/6-TIMER/Timer_interface.h"
#include "1-mcal/7-USART/Uasrt_inteface.h"
#include "2-hal/servo/Servo_inteface.h"
#include "2-hal/CLCD/CLCD_interface.h"


#include <util/delay.h>

/*******************	include section end		**********************/
/*******************	Mecros section start 	**********************/
#define GREEN_LED		1
#define YELLOW_LED		2
#define RED_LED			4
#define BUZZER			12


/*******************	Mecros section end	 	**********************/
/*******************	Vareable section start 	**********************/

u8  Uart_data=0;
u16 ADC_u16Reading;
u8  shutting_falg=0;

/*******************	Vareable section end 	**********************/
/*******************	Function section start 	**********************/



/*******************	Function section end 	**********************/



void main(void)
{
	Timer_config item={Timer0,fast_PWM,0,divid_1024};
	PORT_voidInti();
	Uart_voidInti();
	Timer_Inti(&item);
	Timer1_voidInt();
	ADC_voidinti();



	while(1)
	{

		Uart_u8recive(&Uart_data);

		switch(Uart_data)
		{
		case 1:
			//lighten green led.
			setportvalue(DIO_u8PORTA, GREEN_LED);
			shutting_falg=0;
			break;
		case 2:
			//lighten yellow led.
			setportvalue(DIO_u8PORTA, YELLOW_LED);
			shutting_falg=0;
			break;
		case 3:
			//lighten red led.
			setportvalue(DIO_u8PORTA, RED_LED);
			shutting_falg=1;
			break;
		case 4:
			//lightens red LED and runs buzzer.
			setportvalue(DIO_u8PORTA, BUZZER);
			shutting_falg=0;
			break;
		case 5:
			//
			setportvalue(DIO_u8PORTA,BUZZER);
			Servo_u8Angle(90);
			shutting_falg=0;
			Timer0_voidSetCompareMatch(shutting_falg);
			_delay_ms(5000);
			break;

		default:
			if(1==shutting_falg&&Uart_data==0)
			{
				ADC_voidDein();
				ADC_u16Reading=0;
			}
			break;
		}

		ADC_u8startconversionsync(ADC4, &ADC_u16Reading);
		Timer0_voidSetCompareMatch(ADC_u16Reading);




	}
}
