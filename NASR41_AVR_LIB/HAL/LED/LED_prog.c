/*
* LED_prog.c
*
* Created: 9/23/2022 7:28:33 PM
*  Author:D
*/
#include "LED_interface.h"


void LED_INIT(){
	
	DIO_SetPinMode(LED0_PORT,LED0_PIN,OUTPUT);	   //led0
	
	DIO_SetPinMode(LED1_PORT,LED1_PIN,OUTPUT);	  // led1
	
	DIO_SetPinMode(LED2_PORT,LED2_PIN,OUTPUT);	 //led2
	
	DIO_SetPinMode(LED3_PORT,LED3_PIN,OUTPUT);	 //led3
	
	DIO_SetPinMode(LED4_PORT,LED4_PIN,OUTPUT);	 //led4
	
	DIO_SetPinMode(LED5_PORT,LED5_PIN,OUTPUT);	 //led5
	

}




void LED_MODE(u8 LEDx ,u8 mode ){
if (mode !=TOGGLE)
{
	
switch (LEDx){
	
	case LED0 :   DIO_SetPinValue(LED0_PORT,LED0_PIN,mode);     break;
	case LED1 :    DIO_SetPinValue(LED1_PORT,LED1_PIN,mode);    break;
	case LED2 :    DIO_SetPinValue(LED2_PORT,LED2_PIN,mode);    break;
	case LED3 :    DIO_SetPinValue(LED3_PORT,LED3_PIN,mode);    break;
	case LED4 :    DIO_SetPinValue(LED4_PORT,LED4_PIN,mode);    break;
	case LED5 :    DIO_SetPinValue(LED5_PORT,LED5_PIN,mode);    break;

		 
}	
}

else if ( mode ==TOGGLE   )
{
//switch (LEDx){
	//
	//case LED0 :   DIO_TogglePinValue(LED0_PORT,LED0_PIN);    break;
	//case LED1 :    DIO_TogglePinValue(LED1_PORT,LED1_PIN);    break;
	//case LED2 :    DIO_TogglePinValue(LED2_PORT,LED2_PIN);    break;
	//
//}	
	
}


}


	
