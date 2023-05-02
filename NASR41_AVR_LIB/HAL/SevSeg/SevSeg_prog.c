/*
* SevSeg_prog.c
*
* Created: 9/30/2022 9:22:11 AM
*  Author:D
*/

#include "SevSeg_interface.h"

void SevSeg_init(void ){
	
	DIO_SetPinMode(SevSeg_PORT,SevSeg_pinA,OUTPUT);
	
	DIO_SetPinMode(SevSeg_PORT,SevSeg_pinB,OUTPUT);
	
	DIO_SetPinMode(SevSeg_PORT,SevSeg_pinC,OUTPUT);
	
	DIO_SetPinMode(SevSeg_PORT,SevSeg_pinD,OUTPUT);
	
	DIO_SetPinMode(SevSeg_En_Port ,SevSeg_En1_Pin,OUTPUT);
	DIO_SetPinMode(SevSeg_En_Port ,SevSeg_En2_Pin,OUTPUT);
}


void SevSeg_Write( u8 val){

		DIO_SetPinValue(SevSeg_En_Port,SevSeg_En2_Pin,HIGH);
		DIO_SetPinValue(SevSeg_En_Port,SevSeg_En1_Pin,LOW);
		
		#if(SevSeg_PORT==DIO_PORTA)
		PORTA=  ((val%10)<<4)| (PORTA &0x0f )      ;
		#elif(SevSeg_PORT==DIO_PORTB)
		PORTB=  ((val%10)<<4)| (PORTB &0x0f )   ;
		#elif(SevSeg_PORT==DIO_PORTC)
		PORTC=  ((val%10)<<4)| (PORTC &0x0f )   ;
		#else
		PORTD=((val%10)<<4)| (PORTD &0x0f ) ;
		#endif
		
		_delay_ms(1);
		DIO_SetPinValue(SevSeg_En_Port,SevSeg_En2_Pin,LOW);
		DIO_SetPinValue(SevSeg_En_Port,SevSeg_En1_Pin,HIGH);
		
		#if(SevSeg_PORT==DIO_PORTA)
		PORTA=((val/10)<<4)| (PORTA &0x0f ) ;
		#elif(SevSeg_PORT==DIO_PORTB)
		PORTB=((val/10)<<4)| (PORTB &0x0f );
		#elif(SevSeg_PORT==DIO_PORTC)
		PORTC=((val/10)<<4)| (PORTC &0x0f );
		#else
		PORTD=((val/10)<<4)| (PORTD &0x0f );
		#endif
		
		_delay_ms(1);
	/*
		DIO_SetPinValue(SevSeg_En_Port,SevSeg_En2_Pin,LOW);
		DIO_SetPinValue(SevSeg_En_Port,SevSeg_En1_Pin,LOW);*/
}