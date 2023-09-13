/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : USART            *************************/
/************************************************************************/
/************************************************************************/
#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include "Uasrt_config.h"
#include "Uasrt_inteface.h"
#include "Uasrt_private.h"
#include "Uasrt_register.h"

/*********************** Variable declaration ************************************/
static u8 Uart_u8Data;
static char *Uart_string;
static u8 *Uart_pvRecivedata;
static u8 Size_Recive_String;
static u8 BUSY_flag=idle;
static u8 Uart_Send_flag;
static u8 Uart_Recive_flag;
static void(*Uart_pvfun)(void)=NULL;

void Uart_voidInti(void)
{
	u8 local_val=0;
	/* SET URSEL bit to access UCSRC rigster*/
	SET_BIT(local_val,UCSRC_URSEL);
	/*	config the char size  */
#if Char_Size == _5_bit
	CLR_BIT(local_val,UCSRC_UCSZ0);
	CLR_BIT(local_val,UCSRC_UCSZ1);
#elif Char_Size == _6_bit
	SET_BIT(local_val,UCSRC_UCSZ0);
	CLR_BIT(local_val,UCSRC_UCSZ1);
#elif Char_Size== _7_bit
	CLR_BIT(local_val,UCSRC_UCSZ0);
	SET_BIT(local_val,UCSRC_UCSZ1);
#elif Char_Size== _8_bit
	SET_BIT(local_val,UCSRC_UCSZ0);
	SET_BIT(local_val,UCSRC_UCSZ1);
#else
#error "wrong config for char size"

#endif
	/* the three bit in char size bits*/
	CLR_BIT(UCSRB,UCSRB_UCSZ2);

	/*config stop bit */
#if Stop_Bit==_1_bit
	CLR_BIT(local_val,UCSRC_USBS);
#elif Stop_Bit==_2_bit
	SET_BIT(local_val,UCSRC_USBS);
#else
#error "Wrong config for stop bit "
#endif

	/*config parity */
#if Parity==disable
	CLR_BIT(local_val,UCSRC_UPM0);
	CLR_BIT(local_val,UCSRC_UPM1);
#elif Parity==Even
	CLR_BIT(local_val,UCSRC_UPM0);
	SET_BIT(local_val,UCSRC_UPM1);
#elif Parity==Odd
	SET_BIT(local_val,UCSRC_UPM0);
	SET_BIT(local_val,UCSRC_UPM1);
#else
#error "wrong config for Parity"
#endif

	/*set mode of Uart synch or Asynch*/
#if Uart_mode==Asynchronous
	CLR_BIT(local_val,UCSRC_URSEL);
#elif Uart_mode== Synchronous
	SET_BIT(local_val,UCSRC_URSEL);
#endif


	/*config boadrate*/
	UCSRL= (u8)(Boadrate) ;
	UCSRH=( (Boadrate)  >> 8);

	/*enable TX and RX*/
	SET_BIT(UCSRB,UCSRB_TXEN);
	SET_BIT(UCSRB,UCSRB_RXEN);
}
u8 	 UART_u8TX(u8 copy_u8data)
{
	u32 local_counter=0;
	u8 local_error=OK;
	while((GET_BIT(UCSRA,UCSRA_UDRE)==0)&&(local_counter!=Uart_u32Time_out))
	{
		local_counter++;
	}
	if(local_counter==Uart_u32Time_out){
		local_error=NOK;
	}
	else{

		UDR=copy_u8data;
	}

	return local_error;
}
u8 Uart_u8recive(u8 *copy_pvRecive_Data)
{
	u32 local_counter=0;
	u8 local_error=OK;

	while((GET_BIT(UCSRA,UCSRA_RXC)==0)&&(local_counter!=Uart_u32Time_out))
	{
		local_counter++;
	}
	if(local_counter==Uart_u32Time_out){
		local_error=NOK;
	}
	else{
		*copy_pvRecive_Data=UDR;
	}
	return local_error;
}
u8 UART_u8SendString(const char *copy_string){
	u8 local_error=OK;
	while(*copy_string!='\0')
	{
		local_error=UART_u8TX(*copy_string);
		if(local_error==NOK){
			break;
		}
		copy_string++;
	}
	return local_error;
}
u8 UART_voidRecivestring( u8 *copy_string,u8 copy_u8Size)
{
	u8 local_iterator;
	u8 local_error=OK;
	for(local_iterator=0;local_iterator<copy_u8Size;local_iterator++){

		local_error=Uart_u8recive(copy_string);
		copy_string++;
	}
	return local_error;
}
u8 Uart_u8Send_Asyn(u8 copy_u8data){
	u8 local_errorstate=OK;
	if(BUSY_flag==idle){
		BUSY_flag=busy;
		Uart_Send_flag=Send_Singal;
		Uart_u8Data=copy_u8data;
		SET_BIT(UCSRB,UCSRB_UDRIE);

	}
	else{
		local_errorstate=busy_function;
	}
	return local_errorstate;

}
u8 Uart_u8SendStr_Asyn(char *copy_string, void(*copy_pvNotif)(void))
{
	u8 local_errorstate=OK;
	if(copy_string!=NULL)
	{
		if(BUSY_flag==idle){
			BUSY_flag=busy;
			Uart_Send_flag=Send_String;
			Uart_string=copy_string;
			Uart_pvfun=copy_pvNotif;
			SET_BIT(UCSRB,UCSRB_UDRIE);

		}
		else{
			local_errorstate=busy_function;
		}
	}
	else
	{
		local_errorstate=NULL_POINTER;
	}

	return local_errorstate;
}
u8 Uart_u8recive_Asyn(u8* copy_pvdata)
{
	u8 local_errorstat=OK;


	if(BUSY_flag==idle)
	{
		BUSY_flag=busy;
		Uart_Recive_flag=Recive_Singal;
		Uart_pvRecivedata=copy_pvdata;
		SET_BIT(UCSRB,UCSRB_RXCIE);
	}
	else
	{
		local_errorstat=busy_function;
	}



	return local_errorstat;
}
u8 Uart_u8recive_StringA(char *copy_string,u8 copy_u8size,void(*copy_Pvnotif)(void))
{
	u8 local_errorstate=OK;
	if(BUSY_flag==idle)
	{
		/* set busy flag as busy*/
		BUSY_flag=busy;

		Uart_Recive_flag=Recive_String;
		/* intilization argument globally*/
		Uart_string=copy_string;
		Size_Recive_String=copy_u8size;
		Uart_pvfun=copy_Pvnotif;
		SET_BIT(UCSRB,UCSRB_RXCIE);
	}
	else
	{
		local_errorstate=busy_function;
	}
	return local_errorstate;
}
u8 uart_u8setcallback(void(*fun_pv)(void))
{
	u8 local_errorstate=OK;
	if(fun_pv!=NULL)
	{
		Uart_pvfun=fun_pv;
	}
	else
	{
		local_errorstate=NOK;
	}
	return local_errorstate;
}
void __vector_14 (void)		__attribute__ ((signal));
void __vector_14 (void)
{
	/*come form send string*/
	if(Uart_Send_flag==Send_String){
		UDR=*Uart_string;
		Uart_string++;
		if(*Uart_string=='\0'){

			BUSY_flag=idle;
			CLR_BIT(UCSRB,UCSRB_UDRIE);
			Uart_pvfun();
		}
		else
		{
			UDR=*Uart_string;
		}
	}
	/*come form send char*/
	else
	{

		BUSY_flag=idle;
		UDR=Uart_u8Data;
		CLR_BIT(UCSRB,UCSRB_UDRIE);

	}

}
void __vector_13 (void)		__attribute__ ((signal));
void __vector_13 (void)
{

	if(Uart_Recive_flag==Recive_Singal){
		BUSY_flag=idle;
		*Uart_pvRecivedata=UDR;
		CLR_BIT(UCSRB,UCSRB_RXCIE);
	}
	else if(Uart_Recive_flag==Recive_String)
	{

		*Uart_string=UDR;
		static u8 counter=1;

		 Uart_string++;
		if(counter==Size_Recive_String){
			BUSY_flag=idle;
			CLR_BIT(UCSRB,UCSRB_UDRIE);
			Uart_pvfun();
		}
		else
		{
			counter++;
			*Uart_string=UDR;
		}
	}
}
