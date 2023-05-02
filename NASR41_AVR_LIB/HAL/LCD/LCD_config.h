/*
 * LCD_config.h
 *
 * Created: 10/7/2022 10:43:58 AM
 *  Author:D
 */ 


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "LCD_private.h"

 #define CONTROL_PORT   DIO_PORTB
 #define RS_PIN          PIN1
 #define RW_PIN         PIN2
 #define E_PIN          PIN3
 
 #define DATA_PORT  DIO_PORTA
 #define D4_PIN		PIN4
 #define D5_PIN     PIN5
 #define D6_PIN     PIN6
 #define D7_PIN     PIN7
 
 
 #define FUNCTION_SET    CMD_LCD_4Bit_Mode_2_Line_5X8_FONT  //initialized one time only 
 



#endif /* LCD_CONFIG_H_ */