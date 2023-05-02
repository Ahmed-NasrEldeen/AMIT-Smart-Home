/*
 * EEPROM_interface.h
 *
 * Created: 12/16/2022 9:01:36 PM
 *  Author:D
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "EEPROM_private.h"

void EEPROM_Write(char c,u8 address);
u8 EEPROM_Read(u8 address);
void EEPROM_Write_String(char *data ,u8 address);
char* EEPROM_Read_All();
void EEPROM_Write_String_auto(char *data);

//u16 ADC_Read( u8 ADC_CHANNEL  ) ;





#endif /* EEPROM_INTERFACE_H_ */