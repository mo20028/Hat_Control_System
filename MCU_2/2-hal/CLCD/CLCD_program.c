/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************        SWC : CLCD          *************************/
/************************************************************************/
/************************************************************************/

#include "util/delay.h"

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include "../../1-mcal/2-PORT/PORT_interface.h"
#include "../../1-mcal/1-DIO/DIO_interface.h"

#include  "CLCD_config.h"
#include  "CLCD_interface.h"
#include  "CLCD_pravite.h"

void CLCD_voidSendCommand(u8 copy_u8command)
{
	/*set rs low for command*/
	setbitvalue(CLCD_CLR_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);
	/* set rw PIN to write*/
	setbitvalue(CLCD_CLR_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
#if mode==0

	/*set data value*/
	setportvalue(CLCD_DATA_PORT, copy_u8command);
	/*set the enable pulse..*/
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
#elif mode==1

	/*set data value*/
	/*GPIO_writePin(LCD_DATA_PORT_ID,LCD_DB4_PIN_ID,GET_BIT(command,4));*/
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin4, GET_BIT(copy_u8command,4));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin5, GET_BIT(copy_u8command,5));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin6, GET_BIT(copy_u8command,6));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin7, GET_BIT(copy_u8command,7));


	/*setportvalue(CLCD_DATA_PORT, copy_u8command& 0xf0);*/
	/*set the enable pulse..*/
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(1);
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
	_delay_ms(1);

	/*set low for bits in data value*/
	/*setportvalue(CLCD_DATA_PORT, (copy_u8command<<4)&0xf0);*/
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin4, GET_BIT(copy_u8command,0));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin5, GET_BIT(copy_u8command,1));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin6, GET_BIT(copy_u8command,2));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin7, GET_BIT(copy_u8command,3));

	/*set the enable pulse..*/
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(1);
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
	_delay_ms(1);


#endif
}
void CLCD_voidSendData(u8 copy_u8Data)
{
	/*set rs high for data*/
	setbitvalue(CLCD_CLR_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);
	/* set rw PIN to write*/
	setbitvalue(CLCD_CLR_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);
#if mode==0
	/*set data value*/
	setportvalue(CLCD_DATA_PORT, copy_u8Data);
	/*set the enable pulse..*/
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(2);
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
#elif mode==1


	/*set high 4 bits*/
	/*setportvalue(CLCD_DATA_PORT, copy_u8Data & 0xf0);*/
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin4, GET_BIT(copy_u8Data,4));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin5, GET_BIT(copy_u8Data,5));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin6, GET_BIT(copy_u8Data,6));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin7, GET_BIT(copy_u8Data,7));
	/*set the enable pulse..*/
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(1);
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
	_delay_us(100);

	/*set low 4 bits*/
	/*setportvalue(CLCD_DATA_PORT, (copy_u8Data<<4)& 0xf0);*/
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin4, GET_BIT(copy_u8Data,0));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin5, GET_BIT(copy_u8Data,1));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin6, GET_BIT(copy_u8Data,2));
	setbitvalue(CLCD_DATA_PORT, CLCD_DATA_pin7, GET_BIT(copy_u8Data,3));
	/*set the enable pulse..*/
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_HIGH);
	_delay_ms(1);
	setbitvalue(CLCD_CLR_PORT, CLCD_E_PIN, DIO_u8PIN_LOW);
	_delay_ms(1);
#endif
}
void CLCD_voidInit(void)
{
#if mode==0
	{
		/*wait for more than 40 ms*/
		_delay_ms(41);

		/*function set command : 2line ,5*8 front size*/
		CLCD_voidSendCommand(0b00111000);

		/*diplaly on off control,display enable,cursor enable,blink enable*/
		CLCD_voidSendCommand(0b00001100);

		/*clear display*/
		CLCD_voidSendCommand(1);
	}
#elif mode ==1
	{
		/*wait for more than 40 ms*/
		_delay_ms(41);

		CLCD_voidSendCommand(0x33);
		CLCD_voidSendCommand(0x32);


		/*function set command : 2line ,5*8 front size*/
		CLCD_voidSendCommand(0x28);

		/*diplaly on off control,display enable,cursor enable,blink enable*/
		CLCD_voidSendCommand(0b00001100);

		/*clear display*/
		CLCD_voidSendCommand(1);
	}
#endif

}
void CLCD_voidSendString(const char* copy_string)
{
	while(*copy_string !='\0')
	{
		CLCD_voidSendData(*copy_string);
		copy_string++;

	}

}
void CLCD_voidGOTOXY(u8 copy_u8xpostion,u8 copy_u8ypostion)
{
	u8 Local_u8Address;
	if(copy_u8xpostion==0)
	{
		/*the location at the frist line */
		Local_u8Address=copy_u8ypostion;
	}
	else if(copy_u8xpostion==1)
	{
		/*the location at the second line*/
		Local_u8Address=0x40+copy_u8ypostion;
	}
	/*set bit 7 in DDRAM address and send command*/
	CLCD_voidSendCommand(Local_u8Address+128);
}

void CLCD_voidWrite_SpacialC(u8* copy_pu8Arr,u8 copy_u8Blocknum,u8 copy_u8xpos,u8 copy_u8ypos)
{
	/* write into the CGRAM*/
	u8 address=8*copy_u8Blocknum;
	CLCD_voidSendCommand(address+64);
	for(u8 i=0;i<8;i++)
	{
		CLCD_voidSendData(copy_pu8Arr[i]);
	}
	/*return to dd ram*/
	CLCD_voidGOTOXY(copy_u8xpos	, copy_u8ypos);

	CLCD_voidSendData(copy_u8Blocknum);

}
void CLCD_voidNumber(u32 copy_u32Number)
{

	/*create arr of char from 11 element*/
	char buf[12];  // max 10 digits + null terminator
	uint8_t i = 10;
	buf[i--] = '\0';
	do {
		buf[i--] = copy_u32Number % 10 + '0';
		copy_u32Number /= 10;
	} while (copy_u32Number > 0 && i > 0);
	CLCD_voidSendString(&buf[i+1]);
}
void CLCD_voidWritename(u8* copy_pu8Name,u8 copy_numberofchar)
{

	for( u8 Local_u8var=0 ; Local_u8var<copy_numberofchar;Local_u8var++)
	{
		CLCD_voidWrite_SpacialC(copy_pu8Name[Local_u8var], Local_u8var, 0, Local_u8var);
	}
}




void CLCD_ClearScreen(void)
{
	CLCD_voidSendCommand(CLEAR_COMMAND);
}


void CLCD_voidCursorShift(u8 dircation)
{
	if(dircation==Right)
		CLCD_voidSendCommand(0x14);
	else if(dircation==Left)
		CLCD_voidSendCommand(0x10);
}

void CLCD_voidDataShift(u8 dircation)
{
	if(dircation==Right)
		CLCD_voidSendCommand(0x1c);
	else if(dircation==Left)
		CLCD_voidSendCommand(0x18);

}




