/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************     layer : mcal            *************************/
/*******************     Version : 1.00         *************************/
/*******************     SWC : USART            *************************/
/************************************************************************/
/************************************************************************/

#ifndef UASRT_INTERFACE_H_
#define UASRT_INTERFACE_H_

void Uart_voidInti(void);
u8 	 UART_u8TX(u8 copy_u8data);
u8 	 Uart_u8recive(u8 *copy_pvRecive_Data);
u8 	 UART_u8SendString(const char *copy_string);
u8	 UART_voidRecivestring( u8 *copy_string,u8 copy_u8Size);
/* Uart function with interrupt*/
u8 Uart_u8Send_Asyn(u8 copy_u8data);
u8 Uart_u8SendStr_Asyn(char *copy_string, void(*copy_pvNotif)(void));
u8 Uart_u8recive_Asyn(u8 *copy_pvdata);
u8 Uart_u8recive_StringA(char *copy_string,u8 copy_u8size,void(*copy_Pvnotif)(void));
u8 uart_u8setcallback(void(*fun_pv)(void));




#endif
