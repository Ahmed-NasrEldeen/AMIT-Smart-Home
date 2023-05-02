/*
* EEPROM_prog.c
*
* Created: 12/16/2022 9:06:37 PM
*  Author:D
*/
#include "EEPROM_interface.h"

void EEPROM_Write(char c ,u8 address){ /*used to register the user (char type)*/ 
	
	while(EECR&(1<<EEWE));
	EEAR = address;
	EEDR = c;
	EECR |= 1 << EEMWE;
	EECR |= 1 << EEWE;
	
}

void EEPROM_Write_String(char *data ,u8 address){ /*used to register the user (string type)*/ 
	
	while(1){
		EEPROM_Write(*data,address);
		data++;
		address++;
		if(*data == 0x0 ) {
			EEPROM_Write(*data,address);		
			break;		
		 }
	}
}

void EEPROM_Write_String_auto(char *data){ /*used to register the user (String type) after searching for the last available free memory*/  
	
	int i = 0;
	
	while(1){
		char c = EEPROM_Read(i);
		if(c==0xFF)
		break;
		i++;
	}
	
	u8 address = i;
	
	if(EEPROM_Read(i-1)== 0x0){
		EEPROM_Write(' ',i-1);
	}
	
	while(1){
		EEPROM_Write(*data,address);
		data++;
		address++;
		if(*data == 0x0 ) {
			EEPROM_Write(*data,address);
			break;
		}
	}
}

u8 EEPROM_Read(u8 address){ /*used to read the char stored in the address*/ 
	while(EECR&(1<EEWE));
	EEAR= address;
	EECR |= (1<<EERE);
	return EEDR;
}

char* EEPROM_Read_All(){ /*used to read all chars stored in the memory*/ 
	int i = 0;
	static char str [150];
	while(1){
		char c = EEPROM_Read(i);
		str[i] = c;
		if(c==0xFF)
		break;
		i++;
	}
	return str;
}
