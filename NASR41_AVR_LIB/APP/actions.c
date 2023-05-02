/*
* actions.c
*
* Created: 1/6/2023 9:25:28 PM
*  Author:D
*/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../APP/auth.h"
#include "../MCAL/UART/UART.h"
u8 doorState = 0;
	
u8 takeAction(char *actionStr,u8 isAdmin){
	LCD_Clear();
	LCD_Write_CHAR('#');
	char action = *actionStr;
	LCD_Write_CHAR(action);

	actionStr++;
	char onOff =  *actionStr;
	LCD_Write_CHAR(onOff);

	LCD_Write_CHAR('#');

	switch (action)
	{
		case 'Y':
		return 50;
		case 'N':
		return 20;
		case 'R':
		return 83;
		break;
		case '0':
		if(onOff == '1'){
		LED_MODE(LED0,ON);
		if(is_Remote_User_Logged()){
		char messsage [] = "LED0 ON\n";
		UART_SendString(messsage);
		}
		}
		else{
		LED_MODE(LED0,OFF);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED0 OFF\n";
			UART_SendString(messsage);
		}
		}
		break;
		case '1':
		if(onOff == '1'){
		LED_MODE(LED1,ON);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED1 ON\n";
			UART_SendString(messsage);
		}
		}
		else{
		LED_MODE(LED1,OFF);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED1 OFF\n";
			UART_SendString(messsage);
		}
		}
		break;
		case '2':
		if(onOff == '1'){
		LED_MODE(LED2,ON);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED2 ON\n";
			UART_SendString(messsage);
		}
		}
		else{
		LED_MODE(LED2,OFF);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED2 OFF\n";
			UART_SendString(messsage);
		}
		}
		break;
		case '3':
		if(onOff == '1'){
		LED_MODE(LED3,ON);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED3 ON\n";
			UART_SendString(messsage);
		}
		}
		else{
		LED_MODE(LED3,OFF);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED3 OFF\n";
			UART_SendString(messsage);
		}
		}
		break;
		case '4':
		if(onOff == '1'){
		LED_MODE(LED4,ON);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED4 ON\n";
			UART_SendString(messsage);
		}
		}
		else{
		LED_MODE(LED4,OFF);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED4 OFF\n";
			UART_SendString(messsage);
		}
		}
		break;
		case '5':
		if(onOff == '1'){
		LED_MODE(LED5,ON);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED5 ON\n";
			UART_SendString(messsage);
		}
		}
		else{
		LED_MODE(LED5,OFF);
		if(is_Remote_User_Logged()){
			char messsage [] = "LED5 OFF\n";
			UART_SendString(messsage);
		}
		}
		break;
		case '6':
		if(!isAdmin){
			LCD_Clear();
			LCD_Write_String("Action denied\n");
			if(is_Remote_User_Logged()){
				char messsage [] = "Action denied\n";
				UART_SendString(messsage);
			}
			_delay_ms(1000);
			break;
		}
		if(onOff == '1'){
		TIMER1_OCR1(187);
		doorState=1;
		if(is_Remote_User_Logged()){
			char messsage [] = "DOOR OPENED\n";
			UART_SendString(messsage);
		}
		}
		else{
		TIMER1_OCR1(0);
		doorState=0;
		if(is_Remote_User_Logged()){
			char messsage [] = "DOOR CLOSED\n";
			UART_SendString(messsage);
		}
		}
		break;
	}
}

u8 getDoorState(){
	 return doorState;
}