/*
 * TIMERS_private.h
 *
 * Created: 10/14/2022 9:29:06 PM
 *  Author:D
 */ 


#ifndef TIMERS_PRIVATE_H_
#define TIMERS_PRIVATE_H_

#include "STD_TYPES.h"
 //-----TIMER0 REG ADD--------
 #define  SREG  (*((volatile u8 *)(0x5F)))	  //i-bit
 #define  TCCR0 (*((volatile u8 *)(0x53)))	  // WGM00/01  CS00/01/02
 #define  TCNT0 (*((volatile u8 *)(0x52)))	  // counting register
 #define  OCR0  (*((volatile u8 *)(0x5C)))	  // Comparing register
 #define  TIMSK (*((volatile u8 *)(0x59)))	  // interrupt enable  for OVF,CTC

//-----TCCR0-------------
#define CS00    0
#define CS01    1
#define CS02    2
#define WGM01   3
#define COM00   4
#define COM01   5
#define WGM00   6
#define FOC0    7
//---------TIMSK--------------
#define OCIE0 1
#define TOIE0  0


//-----TIMER1 REG ADD--------
#define  ICR1  (*((volatile u16 *)0x46))
#define  TCCR1A  (*((volatile u8 *)0x4F))
#define  TCCR1B  (*((volatile u8 *)0x4E))
#define  OCR1A  (*((volatile u16 *)0x4A))

#define COM1A1  7
#define COM1A0 6
#define COM1B1 5
#define COM1B0 4
#define FOC1A 3
#define FOC1B 2
#define WGM11 1
#define WGM10 0

#define ICNC1 7
#define ICES1 6
#define WGM13 4
#define WGM12 3
#define CS12 2
#define CS11 1
#define CS10 0



#endif /* TIMERS_PRIVATE_H_ */