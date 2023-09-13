/************************************************************************/
/************************************************************************/
/*******************  Author : Mohamed shaban   *************************/
/*******************  layer  : Mcal           	*************************/
/*******************  Version: 1.00         	*************************/
/*******************  SWC 	 : DIO          	*************************/
/************************************************************************/
/************************************************************************/

#include "../../libr/STD_types.h"
#include "../../libr/BIT_math.h"

#include "DIO_interface.h"
#include "DIO_praviate.h"
#include "DIO_register.h"
#include "DIO_config.h"




u8 setbitvalue(u8 copy_u8port,u8 copy_u8pin,u8 copy_u8value)
{
     u8 Local_u8ErrorState=0;
     if(copy_u8pin<=DIO_u8PIN7)
    {
        if(copy_u8value==DIO_u8PIN_LOW)
        {
            switch(copy_u8port)
            {
                case DIO_u8PORTA : CLR_BIT(PORTA,copy_u8pin); break;
                case DIO_u8PORTB : CLR_BIT(PORTB,copy_u8pin); break;
                case DIO_u8PORTC : CLR_BIT(PORTC,copy_u8pin); break;
                case DIO_u8PORTD : CLR_BIT(PORTD,copy_u8pin); break;
                default: Local_u8ErrorState=1; break;
            }
        }
        else if(copy_u8value ==DIO_u8PIN_HIGH)
        {
            switch(copy_u8port)
            {
                case DIO_u8PORTA : SET_BIT(PORTA,copy_u8pin); break;
                case DIO_u8PORTB : SET_BIT(PORTB,copy_u8pin); break;
                case DIO_u8PORTC : SET_BIT(PORTC,copy_u8pin); break;
                case DIO_u8PORTD : SET_BIT(PORTD,copy_u8pin); break;
                default: Local_u8ErrorState=1; break;
            }
        }
        else
        {
            Local_u8ErrorState=1;
        }
    }
    else
    {
        Local_u8ErrorState=1;
    }
        
    return Local_u8ErrorState;
}
u8 setportvalue (u8 copy_u8port,u8 copy_u8value)
{
     u8 Local_u8ErrorState=0;
      switch(copy_u8port)
    {
        case DIO_u8PORTA: PORTA=copy_u8value; break; 
        case DIO_u8PORTB: PORTB=copy_u8value; break; 
        case DIO_u8PORTC: PORTC=copy_u8value; break; 
        case DIO_u8PORTD: PORTD=copy_u8value; break; 
        default: Local_u8ErrorState=1;
          
    }
    
     return Local_u8ErrorState;
}

u8 getbit (u8 copy_port ,u8 copy_pin,u8* copy_value)
{
     u8 Local_u8ErrorState=0;
     if((copy_value!=NULL )  &&(copy_pin<=DIO_u8PIN7))
     {
         switch(copy_port)
         {
             case DIO_u8PORTA: *copy_value=GET_BIT(PINA,copy_pin);  break;
             case DIO_u8PORTB: *copy_value=GET_BIT(PINB,copy_pin);  break;
             case DIO_u8PORTC: *copy_value=GET_BIT(PINC,copy_pin);  break;
             case DIO_u8PORTD: *copy_value=GET_BIT(PIND,copy_pin);  break;
             
             default: Local_u8ErrorState=1;
             
         }
     }
     else
     {
         Local_u8ErrorState=1;
     }
     
    
     return Local_u8ErrorState;
}


