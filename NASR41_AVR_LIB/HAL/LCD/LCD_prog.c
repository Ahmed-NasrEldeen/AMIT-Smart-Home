/*
* LCD_prog.c
*
* Created: 10/7/2022 10:44:34 AM
*  Author:D
*/

#include "LCD_interface.h"

void LCD_init(){
	
	DIO_SetPinMode(CONTROL_PORT,RS_PIN,OUTPUT);
	DIO_SetPinMode(CONTROL_PORT,RW_PIN,OUTPUT);
	DIO_SetPinMode(CONTROL_PORT,E_PIN,OUTPUT);

	DIO_SetPinMode(DATA_PORT,D4_PIN,OUTPUT);
	DIO_SetPinMode(DATA_PORT,D5_PIN,OUTPUT);
	DIO_SetPinMode(DATA_PORT,D6_PIN,OUTPUT);
	DIO_SetPinMode(DATA_PORT,D7_PIN,OUTPUT);

	_delay_ms(15);
	LCD_Write_CMD(0x33);   //function set 1
	_delay_ms(1);
	LCD_Write_CMD(0x32);
	_delay_ms(1);
	LCD_Write_CMD(FUNCTION_SET);
	_delay_ms(1);
	LCD_Write_CMD(CMD_Display_Cursor_ON_Blink_OFF);
	_delay_ms(1);

	LCD_Write_CMD(CMD_Shift_Cursor_Right_Per_Read_Write);
	_delay_ms(1);
	
	LCD_Write_CMD(CMD_Clear_Display);
	_delay_ms(2);
	LCD_Write_CMD(CMD_Return_Home);
	_delay_ms(2);
	
}
void LCD_Write_CMD(u8 CMD){
	DIO_SetPinValue(CONTROL_PORT,RS_PIN,LOW);
	DIO_SetPinValue(CONTROL_PORT,RW_PIN,LOW);
	
	
	DIO_SetPinValue(CONTROL_PORT,E_PIN,LOW);
	
	_delay_ms(1);
	
	DIO_SetPinValue(CONTROL_PORT,E_PIN,HIGH);
	
	#if (DATA_PORT == DIO_PORTA)
	PORTA=(CMD & 0xF0)|(PORTA & 0x0F);
	
	#elif (DATA_PORT == DIO_PORTB)
	PORTB=(CMD & 0xF0)|(PORTB & 0x0F);
	
	#elif (DATA_PORT == DIO_PORTC)
	PORTC=(CMD & 0xF0)|(PORTC & 0x0F);
	
	#elif (DATA_PORT == DIO_PORTD)
	PORTD=(CMD & 0xF0)|(PORTD & 0x0F);
	#endif
	DIO_SetPinValue(CONTROL_PORT,E_PIN,LOW);

	
	_delay_ms(2);
	
	DIO_SetPinValue(CONTROL_PORT,E_PIN,HIGH);

	
	#if (DATA_PORT == DIO_PORTA)
	PORTA=(CMD <<4)|(PORTA & 0x0F);
	
	#elif (DATA_PORT == DIO_PORTB)
	PORTB=(CMD <<4)|(PORTB & 0x0F);
	
	#elif (DATA_PORT == DIO_PORTC)
	PORTC=(CMD <<4)|(PORTC & 0x0F);
	
	#elif (DATA_PORT == DIO_PORTD)
	PORTD=(CMD <<4)|(PORTD & 0x0F);
	#endif


	DIO_SetPinValue(CONTROL_PORT,E_PIN,LOW);

	_delay_ms(1);
	
	
}


void LCD_Write_CHAR(u8 CHR){
	DIO_SetPinValue(CONTROL_PORT,RS_PIN,HIGH); //SELECT DATA REG
	DIO_SetPinValue(CONTROL_PORT,RW_PIN,LOW);
	DIO_SetPinValue(CONTROL_PORT,E_PIN,LOW);
	_delay_ms(1);
	DIO_SetPinValue(CONTROL_PORT,E_PIN,HIGH);
	
	#if (DATA_PORT == DIO_PORTA)
	PORTA=(CHR & 0xF0)|(PORTA & 0x0F);
	#elif (DATA_PORT == DIO_PORTB)
	PORTB=(CHR & 0xF0)|(PORTB & 0x0F);
	#elif (DATA_PORT == DIO_PORTC)
	PORTC=(CHR & 0xF0)|(PORTC & 0x0F);
	#elif (DATA_PORT == DIO_PORTD)
	PORTD=(CHR & 0xF0)|(PORTD & 0x0F);
	#endif
	
	DIO_SetPinValue(CONTROL_PORT,E_PIN,LOW);
	
	_delay_ms(2);
	
	DIO_SetPinValue(CONTROL_PORT,E_PIN,HIGH);
	#if (DATA_PORT == DIO_PORTA)
	PORTA=(CHR <<4)|(PORTA & 0x0F);
	#elif (DATA_PORT == DIO_PORTB)
	PORTB=(CHR <<4)|(PORTB & 0x0F);
	#elif (DATA_PORT == DIO_PORTC)
	PORTC=(CHR <<4)|(PORTC & 0x0F);
	#elif (DATA_PORT == DIO_PORTD)
	PORTD=(CHR <<4)|(PORTD & 0x0F);
	#endif
	
	DIO_SetPinValue(CONTROL_PORT,E_PIN,LOW);
	_delay_ms(1);
}

void LCD_Write_String(const u8 *  str){
	
	while(*str != '\0'){
		if(*str == '\0'){
			break;
		}
		LCD_Write_CHAR(*str);
		str++;

	}
}


void LCD_GOTO(u8 row,u8 col){
	
	u8 DDRAM_ADDRESSES[2]={LCD_Line1_1stAddress ,LCD_Line2_1stAddress };
	
	 	LCD_Write_CMD(DDRAM_ADDRESSES[row]+col);	
	
	
	
	
}
void LCD_Clear(){
	LCD_Write_CMD(CMD_Clear_Display);	
}
