/*
* auth.c
*
* Created: 1/1/2023 7:42:05 PM
*  Author:D
*/
#include "../STD_TYPES.h"
#include "MCAL/EEPROM/EEPROM_interface.h"
#include <string.h>
#include "avr/delay.h"

u8 remoteLoged=0;
u8 remoteUserAdmin=0;
u8 offlineLoged=0;
u8 loginFaliureCount =0;
u8 systemAlarm =0;
u8 adminAllowUser=0;
u8 adminSetAutherization=0;
u8 askedAdmin=0;

u8 isSystemlocked(){
	return systemAlarm;
}
u8 is_Remote_User_Logged(){
	return remoteLoged;
}
u8 is_Remote_User_Admin(){
	return remoteUserAdmin;
}
u8 is_Offline_User_Logged(){
	return offlineLoged;
}
u8 login(char *usernamePassword,u8 remote){

	char  usernamePasswordCopy[30] ="";
	strcpy(usernamePasswordCopy, usernamePassword);
	u8 count = 0;
	unsigned int found = 0;
	unsigned int skipToNext = 0;
	unsigned int possibeMatch = 1;
	unsigned int counter = 0;
	char* strp = EEPROM_Read_All();
	char* strc = EEPROM_Read_All();
	while (*strc != 'ÿ' && !found)
	{
		counter = 0;
		possibeMatch = 1;
		while (usernamePasswordCopy[counter] !='\0')
		{
			if (usernamePasswordCopy[counter] != *strc) {
			
				
				possibeMatch = 0;
				break;
			}
			counter++;
			strc++;
			
		}
		if (possibeMatch == 1) {

			found=1;
			break;
		}
		int spaceCount = 0;
		while (*strc != 'ÿ'&& spaceCount != 3 )
		{
			if (*strc == ' ') {
				spaceCount++;
			}
			strc++;

		}
	}

	if (found) {
		if(remote){
			if(*strc=='1'){
				remoteUserAdmin =1;
			}
			remoteLoged = 1;
		}
		else{
			offlineLoged = 1;
		}
		return 1;
		
	}
	else
	{
		loginFaliureCount++;
		if(loginFaliureCount>2){
			systemAlarm=1;
		}
		return 0;
	}
	
}

u8 register_User(char *usernamePassword){
	u8 count = 0;
	//LCD_Clear();
	char userDetailsCopy [30] = "";
	strcpy(userDetailsCopy, usernamePassword);
	char *strp = EEPROM_Read_All();
	if (strstr(strp, userDetailsCopy) != NULL) {
		return 2;
		}else{
		LCD_Clear();
		count=0;
		while( userDetailsCopy[count]!='\0'){
			LCD_Write_CHAR(userDetailsCopy[count]);
			count++;
		}
		EEPROM_Write_String_auto(userDetailsCopy);
		return 1;

	}
	
}

u8 ask_Admin_To_Allow_User(){
	askedAdmin=1;
	if(!adminSetAutherization){
		char message[45] = "Allow user to do actions Y for yes N for no";
		UART_SendString(message);
		return 2;
	}
	return adminAllowUser;
}

u8 set_Admin_Allow_User(u8 val){
	adminAllowUser =val;
	adminSetAutherization=1;
}

u8 get_Asked_Admin(){
	return askedAdmin;
}
u8 get_Admin_Set_Autherization(){
	return adminSetAutherization;
}
u8 get_Admin_Allow_User(){
	return adminAllowUser;
}