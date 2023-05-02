/*
 * DIO_interface.h
 *
 * Created: 9/17/2022 11:41:45 AM
 *  Author:D
 */ 


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"



typedef enum {DIO_PORTA,DIO_PORTB,DIO_PORTC,DIO_PORTD} PORT_TYPE;
typedef enum {PIN0,PIN1,PIN2,PIN3,PIN4,PIN5,PIN6,PIN7} PIN_TYPE;
typedef enum {LOW,HIGH,INPUT,OUTPUT,INPUT_PULLUP} MODE_TYPE;


void DIO_SetPinMode (PORT_TYPE,PIN_TYPE,MODE_TYPE );
void DIO_SetPinValue(PORT_TYPE,PIN_TYPE,MODE_TYPE );

u8 DIO_GetPinValue(PORT_TYPE,PIN_TYPE);
   





#endif /* DIO_INTERFACE_H_ */