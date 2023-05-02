/*
* TIMERS_config.h
*
* Created: 10/14/2022 9:28:53 PM
*  Author:D
*/


#ifndef TIMERS_CONFIG_H_
#define TIMERS_CONFIG_H_

#define NORMAL_MODE       0
#define PWM_PHASE_CORRECT 1
#define CTC_MODE          2
#define PWM_FAST_MODE	  3
#define TIMER0_MODE   NORMAL_MODE


#define PRE_1     1
#define PRE_8     2
#define PRE_64    3
#define PRE_256   4
#define PRE_1024  5
#define TIMER0_FREQ	  PRE_256
 

#define OC0_DISCONNECTED 0
#define OC0_NON_INVERTED 2
#define OC0_INVERTED     3
#define PWM_OC0_MODE OC0_NON_INVERTED


#endif /* TIMERS_CONFIG_H_ */