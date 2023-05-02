/*
* LCD_interface.h
*
* Created: 10/7/2022 10:43:38 AM
*  Author:D
*/


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_


#include "LCD_config.h"
#include "DIO_interface.h"

#define F_CPU 16000000UL
#include "avr/delay.h"

void LCD_init();
void LCD_Write_CMD(u8 CMD);
void LCD_Write_CHAR(u8 CMD);
void LCD_Write_String(const u8 * str);
void LCD_Clear();







#endif /* LCD_INTERFACE_H_ */