/*
 * SevSeg_interface.h
 *
 * Created: 9/30/2022 9:21:17 AM
 *  Author:D
 */ 


#ifndef SEVSEG_INTERFACE_H_
#define SEVSEG_INTERFACE_H_

#include "../MCAL/DIO_interface.h"
#include "SevSeg_config.h"
#define  F_CPU 16000000UL
#include <avr/delay.h>

void SevSeg_init();
void SevSeg_Write(u8 num);




#endif /* SEVSEG_INTERFACE_H_ */