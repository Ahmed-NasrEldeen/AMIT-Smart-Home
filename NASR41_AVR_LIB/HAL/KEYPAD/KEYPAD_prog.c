/*
* KEYPAD_prog.c
*
* Created: 10/1/2022 9:59:06 AM
*  Author:D
*/
#include "KEYPAD_interface.h"

u8 Keys [4][4]=	{
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};

void KEYPAD_init(){

	DIO_SetPinMode(KP_COL_PORT,KP_C0_PIN,OUTPUT);
	DIO_SetPinMode(KP_COL_PORT,KP_C1_PIN,OUTPUT);
	DIO_SetPinMode(KP_COL_PORT,KP_C2_PIN,OUTPUT);
	DIO_SetPinMode(KP_COL_PORT,KP_C3_PIN,OUTPUT);

	DIO_SetPinMode(KP_ROW_PORT,KP_R0_PIN,INPUT_PULLUP);
	DIO_SetPinMode(KP_ROW_PORT,KP_R1_PIN,INPUT_PULLUP);
	DIO_SetPinMode(KP_ROW_PORT,KP_R2_PIN,INPUT_PULLUP);
	DIO_SetPinMode(KP_ROW_PORT,KP_R3_PIN,INPUT_PULLUP);

	DIO_SetPinValue(KP_COL_PORT,KP_C0_PIN,HIGH);
	DIO_SetPinValue(KP_COL_PORT,KP_C1_PIN,HIGH);
	DIO_SetPinValue(KP_COL_PORT,KP_C2_PIN,HIGH);
	DIO_SetPinValue(KP_COL_PORT,KP_C3_PIN,HIGH);
	
}

u8 KEYPAD_GetKey(){
	
	u8 val= NO_KEY;
	
	for(u8 i=KP_C0_PIN;i<=KP_C3_PIN;i++){
		

		DIO_SetPinValue(KP_COL_PORT, i ,LOW)  ;
		
		for (u8 j=KP_R0_PIN;j<=KP_R3_PIN;j++)
		{

			if(!DIO_GetPinValue(KP_ROW_PORT,j))
			{
				_delay_ms(30);
				if(!DIO_GetPinValue(KP_ROW_PORT,j))
				{
					
					val= Keys[j-KP_R0_PIN][i-KP_C0_PIN];
					break;
					
				}
				
			}
		}
		
		DIO_SetPinValue(KP_COL_PORT, i ,HIGH)  ;
		
	}
	
	
	
	return val ;
	
	
}