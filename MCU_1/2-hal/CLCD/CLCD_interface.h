/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : hal            *************************/
/*******************     Version : 1.00         *************************/
/*******************        SWC : CLCD          *************************/
/************************************************************************/
/************************************************************************/

#define Right 0
#define lift  1

#ifndef  CLCD_INtERfACE_H_
#define  CLCD_INtERfACE_H_

	void CLCD_voidSendCommand(u8 command);
	void CLCD_voidSendData(u8 DATA);
	void CLCD_voidSendString(const char* copy_string);
	void CLCD_voidInit(void);
	void CLCD_voidGOTOXY(u8 copy_u8xpostion,u8 copy_u8ypostion);
	void CLCD_voidWrite_SpacialC(u8* copy_pu8Arr,u8 copy_u8Blocknum,u8 copy_xpos,u8 copy_u8ypos);
	void CLCD_voidNumber(u32 copy_u32Number);
	void CLCD_voidWritename(u8* copy_pu8Name,u8 copy_numberofchar);
	void CLCD_voidCursorShift(u8 dircation);
	void CLCD_voidDataShift(u8 dircation);
	void CLCD_ClearScreen(void);



#endif
