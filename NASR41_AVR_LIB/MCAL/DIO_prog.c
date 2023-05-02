/*
* DIO_prog.c
*
* Created: 9/17/2022 11:42:04 AM
*  Author:D
*/


#include "DIO_interface.h"


void  DIO_SetPinMode( PORT_TYPE port , PIN_TYPE pin  , MODE_TYPE mode ) {
	
	if (port==DIO_PORTA)
	{
		switch(mode){
			
			case INPUT:  CLR_BIT(DDRA,pin) ; break;
			
			case INPUT_PULLUP:
					CLR_BIT(DDRA,pin);
					SET_BIT(PORTA,pin);
					  break;
			
			
			case OUTPUT :	SET_BIT(DDRA,pin); break;
			
		}
		
		
		
	}
	else if (port==DIO_PORTB)
	{
		
		
		   switch(mode){
			   
			   case INPUT:  CLR_BIT(DDRB,pin) ; break;
			   
			   case INPUT_PULLUP:
			   CLR_BIT(DDRB,pin);
			   SET_BIT(PORTB,pin);
			   break;
			   
			   
			   case OUTPUT :	SET_BIT(DDRB,pin); break;
			   
		   }
		
		
		
	}
	else if (port==DIO_PORTC)
	{
		
		
		switch(mode){
			
			case INPUT:  CLR_BIT(DDRC,pin) ; break;
			
			case INPUT_PULLUP:
			CLR_BIT(DDRC,pin);
			SET_BIT(PORTC,pin);
			break;
			
			
			case OUTPUT :	SET_BIT(DDRC,pin); break;
			
		}
		
		
		
	}
	else if (port==DIO_PORTD)
	{
		switch(mode){
			
			case INPUT:  CLR_BIT(DDRD,pin); break;
			case INPUT_PULLUP:	CLR_BIT(DDRD,pin); SET_BIT(PORTD,pin); break;
			case OUTPUT :	SET_BIT(DDRD,pin); break;
			
		}
	}
	
	
}

void  DIO_SetPinValue( PORT_TYPE port , PIN_TYPE pin  , MODE_TYPE mode ) {
	
	switch(port){
		
		case  DIO_PORTA:
		SET_BIT_Value(PORTA,pin,mode);
		break;
		
		case  DIO_PORTB:
		SET_BIT_Value(PORTB,pin,mode);
		break;
		
		case  DIO_PORTC: {
			SET_BIT_Value(PORTC,pin,mode);
			break;
		}
		
		case  DIO_PORTD: {
			SET_BIT_Value(PORTD,pin,mode);
		break;	}
		
		default: break;
		
	}

}



u8  DIO_GetPinValue( PORT_TYPE port , PIN_TYPE pin  ) {

	switch(port){
		
		case  DIO_PORTA:
		return	GET_BIT(PINA,pin);
		break;
		
		case  DIO_PORTB:
		return GET_BIT(PINB,pin);
		break;
		
		case  DIO_PORTC:
		return GET_BIT(PINC,pin);
		break;
		
		
		case  DIO_PORTD:
		return GET_BIT(PIND,pin);
		break;
		
		default: break;
		
	}

}
