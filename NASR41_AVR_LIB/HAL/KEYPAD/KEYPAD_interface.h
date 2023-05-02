/*
 * KEYPAD_interface.h
 *
 * Created: 10/1/2022 9:58:50 AM
 *  Author:D
 */ 


#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

 #include "DIO_interface.h"
 #define  F_CPU 16000000UL
 #include "util/delay.h"
 #include "KEYPAD_config.h"



#define  NO_KEY  '$'
u8 KEYPAD_GetKey();
void KEYPAD_init();

#endif /* KEYPAD_INTERFACE_H_ */