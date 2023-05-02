/*
* TIMERS_interface.h
*
* Created: 10/14/2022 9:29:21 PM
*  Author:D
*/


#ifndef TIMERS_INTERFACE_H_
#define TIMERS_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "TIMERS_config.h"
#include "TIMERS_private.h"
#include "DIO_interface.h"

void TIMER0_INIT (void);
void TIMER0_PWM_Stop (void);
void TIMER0_PWM_Start (void);
void TIMER0_PWM_Set_Dutiy_Cycle(u8 percentage);
void TIMER0_Start(void);
void TIMER0_Stop (void);
void TIMER1_INIT();
void TIMER1_OCR1(u8 value);


#endif /* TIMERS_INTERFACE_H_ */