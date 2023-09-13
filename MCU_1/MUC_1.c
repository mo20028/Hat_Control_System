/*
 * file_name  : MCU1.c
 *
 * Author: 		Mohamed Shaban
 *
 * Description: Temperature Control System using Atmega32 (MCU1)
 *
 * States:
 * - Normal State: Temperature control within safe limits.
 * - Emergency State: Activated when the temperature exceeds a critical threshold.
 * - Abnormal State: Indicates an issue with temperature control.
 *
 * Main Features:
 * - Reads temperature from a sensor.
 * - Controls the speed of a fan (DC motor) based on temperature.
 * - Communicates with MCU2 using UART to exchange control commands.
 * - Implements various safety measures based on temperature and user input.
 *
 * Components Used:
 * - Atmega32 Microcontroller.
 * - Temperature Sensor.
 * - DC Motor (used as a fan).
 * - Push Button for user input.
 * - EEPROM for state storage.
 *
 * Software Driver:
 * - Port_Driver
 * - Dio_Driver
 * - GIE_Driver
 * - Exti_Driver
 * - ADC_Driver
 * - Timer_Driver
 * - UASRT_Driver
 * - internal_EEPROM
 * - Watch_Dog
 *
 */
/*******************	include section begin	**********************/
#include "libr/STD_types.h"
#include "libr/BIT_math.h"
#include "libr/map.h"

#include "1-mcal/1-DIO/DIO_interface.h"
#include "1-mcal/2-PORT/PORT_interface.h"
#include "1-mcal/3-GIE/GIE_interface.h"
#include "1-mcal/4-EXTI/EXTI_interface.h"
#include "1-mcal/5-ADC/ADC_interface.h"
#include "1-mcal/6-TIMER/Timer_interface.h"
#include "1-mcal/7-USART/Uasrt_inteface.h"
#include "2-hal/CLCD/CLCD_interface.h"
#include "1-mcal/10-internal_EEPROM/EEPROM_interface.h"
#include "1-mcal/11-WTDOG/WTDOG_interface.h"


#include <util/delay.h>

/*******************	include section end		**********************/
/*******************	Mecros section start 	**********************/

/* states:
 * 		1:normal state
 * 		2:emergncey state
 * 		3:abnormal state
 */
#define NORMAL_STATE		1
#define EMERGNCEY_STATE		2
#define ABNORMAL_STATE		3
#define STATE_LOC			0x10	//location for state in EEPROM

#define MIN_SPEED			0
#define MAX_SPEED			255

#define Temp_one   			20
#define Temp_two		    40
#define Temp_three		    50


// the messages that send by UART
#define MES_ONE				1	// lighten green  led.
#define MES_TWO				2	// lighten yellow led.
#define MES_THREE			3	// lighten red    led.
#define MES_FOUR			4	// enter emergncey state
#define MES_FIVE			5	// enter Abnormal  state

#define SHUTTING_DOWN		0

#define SLEEP_TIME			0	// timer for Watch dog

/*******************	Mecros section end	 	**********************/
/*******************	Vareable section start 	**********************/
u8 Machine_State;
u16 temperature=0;
Timer_config item2={Timer2,CTC_mode,160,t2_divid_1024};
Timer_config item3={Timer2,CTC_mode,160,t2_noPara};



/*******************	Vareable section end 	**********************/
/*******************	Function section start 	**********************/
void setup(void);
u16  temp_u16Read(void);
void Button(void);
void move_voidDC(u16 copy_u16temp);
void Timer2_callback(void);





/*******************	Function section end 	**********************/










void main(void)
{
	setup();




	while(1)
	{

		EEPROM_voidRead_Byte(&Machine_State, STATE_LOC);
		switch(Machine_State)
		{
		case NORMAL_STATE:
			// Normal state
			//first Read Temp
			temp_u16Read();
			//start move the DC motor(fan)
			move_voidDC(temperature);

			break;
		case EMERGNCEY_STATE:
			/************  Emergency state  ******************/

			// moves the fan with max speed.
			Timer0_voidSetCompareMatch(MAX_SPEED);
			// enable Timer2
			Timer_Inti(&item2);

			break;
		case ABNORMAL_STATE:
			/************  Abnormal state  ******************/
			// send mes for MCU2
			UART_u8TX(MES_FIVE);
			// moves the fan with max speed.
			Timer0_voidSetCompareMatch(MAX_SPEED);
			// activates the watchdog timer
			WTDOG_voidEnable();
			WTDOG_voidSleep(SLEEP_TIME);
			break;
		default:
			/* do nothing*/
			break;

		}

	}
}
/*******************	Function section definations 	**********************/
void setup(void)
{
	PORT_voidInti();
	ADC_voidinti();
	Timer_config item={Timer0,fast_PWM,0,divid_1024};
	Timer_Inti(&item);
	Uart_voidInti();
	EXTI_voidInt0_pre();
	EXTI_u8Set_Callback(&Button, INT0_ID);
	EEPROM_voidWrite_Byte(NORMAL_STATE, STATE_LOC);
	Timer_u8SetCallBack(&Timer2_callback, T2_compare);
	GIE_voidEnable();

}
u16  temp_u16Read(void)
{
	u16 local_u16;
	ADC_u8startconversionsync(ADC0, &local_u16);
	temperature= ((u32)local_u16*5000)/2560UL;

	return temperature;
}
void Button(void)
{
	if((temperature>=Temp_two)&&(temperature<=Temp_three))
	{
		setbitvalue(DIO_u8PORTB, DIO_u8PIN0, 1);
		UART_u8TX(SHUTTING_DOWN);
	}
	else
	{
		// do nothing

	}
}
void move_voidDC(u16 copy_u16temp)
{
	u8 fan_speed=0;
	if(copy_u16temp<Temp_one)
	{
		Timer0_voidSetCompareMatch(MIN_SPEED);
		UART_u8TX(MES_ONE);
		_delay_ms(1000);

	}
	else if((copy_u16temp>=Temp_one)&&(copy_u16temp<=Temp_two))
	{
		fan_speed=map(20, 40, 1, 255, copy_u16temp);
		Timer0_voidSetCompareMatch(fan_speed);
		UART_u8TX(MES_TWO);
		_delay_ms(1000);
	}
	else if((copy_u16temp>=Temp_two)&&(copy_u16temp<=Temp_three))
	{
		Timer0_voidSetCompareMatch(MAX_SPEED);
		UART_u8TX(MES_THREE);
		_delay_ms(1000);
	}
	else
	{
		EEPROM_voidWrite_Byte(EMERGNCEY_STATE, STATE_LOC);
		UART_u8TX(MES_FOUR);
		_delay_ms(1000);
	}
}
void Timer2_callback(void)
{
	static u8 counter=0;
	static u8 iter=0;
	iter++;
	if(25==iter){
		counter++;
		temp_u16Read();
		if(temperature<50)
		{
			EEPROM_voidWrite_Byte(NORMAL_STATE, STATE_LOC);
		}
		else
		{
			// do nothing
		}
		if(14==counter)
		{
			EEPROM_voidWrite_Byte(ABNORMAL_STATE, STATE_LOC);
			counter=0;

			// disable Timer_2


		}
		else
		{
			// do nothing
		}

		iter=0;
	}


}



