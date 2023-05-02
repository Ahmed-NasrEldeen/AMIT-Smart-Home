/*
* ADC_interface.h
*
* Created: 10/8/2022 7:20:17 PM
*  Author:D
*/


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "ADC_config.h"
#include "ADC_private.h"

#define ADC0              0
#define ADC1              1
#define ADC2              2
#define ADC3              3
#define ADC4              4
#define ADC5              5
#define ADC6              6
#define ADC7              7





void ADC_init();
u16 ADC_Read( u8 ADC_CHANNEL  ) ;



#endif /* ADC_INTERFACE_H_ */