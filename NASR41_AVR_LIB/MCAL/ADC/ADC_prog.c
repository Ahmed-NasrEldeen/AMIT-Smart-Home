/*
* ADC_prog.c
*
* Created: 10/8/2022 7:21:35 PM
*  Author:D
*/

#include "ADC_interface.h"

void ADC_init() {
	
	ADMUX = (ADC_VOLTAGE_REFERENCE << REFS0 ) ;

	#if (TRIGGER_MODE == SINGLE_CONVERSION_MODE)
	
	ADCSRA    = ADC_Division_Factor| (1 <<ADEN)  ;

	#else
	
	ADCSRA    = ADC_Division_Factor| (1 <<ADEN) | 1<<ADATE;
	
	SFIOR = (TRIGGER_MODE << 5)| (SFIOR & 0x0F);
	
	
	
	#endif
	

	
	
}


u16 ADC_Read( u8 ADC_CHANNEL ){
	
	
	ADMUX =ADC_CHANNEL	| (ADMUX & 0xE0)  ;
	
	CLR_BIT( DDRA,ADC_CHANNEL)  ;	   //setup adc channel as input pin
	
	
	
	SET_BIT(ADCSRA,ADSC); //  Start Conversion
	while(IS_LOW(ADCSRA,ADIF));
	
	//SET_BIT(ADCSRA,ADIF);// CLear flag by setting it to 1
	return ADC_DATA_REG ;
	
	
}