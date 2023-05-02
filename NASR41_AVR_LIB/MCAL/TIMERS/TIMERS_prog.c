/*
* TIMERS_prog.c
*
* Created: 10/14/2022 9:29:39 PM
*  Author:D
*/

#include "TIMERS_interface.h"

void Timer0_Stop(){ /* Stops timer zero */
	
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	
}

void Timer0_INIT(){ /* initiates timer zero */
	SET_BIT(SREG,7);//GIE
	
	#if (TIMER0_MODE==NORMAL_MODE )
	SET_BIT(TIMSK,TOIE0);
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	#elif (TIMER0_MODE==PWM_PHASE_CORRECT )
	SET_BIT(TIMSK,TOIE0);
	SET_BIT(TIMSK,OCIE0);
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	#elif (TIMER0_MODE==CTC_MODE )
	SET_BIT(TIMSK,OCIE0);
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#elif (TIMER0_MODE==PWM_FAST_MODE )
	SET_BIT(TIMSK,TOIE0);
	SET_BIT(TIMSK,OCIE0);
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#endif
	
}


void Timer0_Start(){ /* starts timer zero */
	
	// re-update this code with #if
	
	
	switch(TIMER0_FREQ){
		
		case PRE_1024: {
			SET_BIT(TCCR0,CS00);
			CLR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		} break;
		case PRE_256: {
			CLR_BIT(TCCR0,CS00);
			CLR_BIT(TCCR0,CS01);
			SET_BIT(TCCR0,CS02);
		} break;
		
		
		case PRE_64: {
			SET_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLR_BIT(TCCR0,CS02);
		} break;
		
		
		case PRE_8: {
			
			CLR_BIT(TCCR0,CS00);
			SET_BIT(TCCR0,CS01);
			CLR_BIT(TCCR0,CS02);
		} break;
		
		
		case PRE_1: {
			
			SET_BIT(TCCR0,CS00);
			CLR_BIT(TCCR0,CS01);
			CLR_BIT(TCCR0,CS02);
		} break;
		
		
	}
}
void TIMER0_PWM_Start (void){ /* Starts Pulse Width Modulation for Timer0 */
	#if (PWM_OC0_MODE== OC0_NON_INVERTED)
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#elif (PWM_OC0_MODE=== OC0_INVERTED)
	SET_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);
	#endif
		
}

void TIMER0_PWM_Stop (void){ /* Stop Pulse Width Modulation for Timer0 */
	CLR_BIT(TCCR0,COM00);
	CLR_BIT(TCCR0,COM01);
}

void TIMER0_PWM_Set_Duty_Cycle(u8 percentage){ /* Starts Pulse Width Modulation for Timer0 */
	#if(PWM_OC0_MODE == OC0_INVERTED)
	percentage = 100 - percentage;
	#endif
	OCR0 = (u8)((percentage*256)/100 -1);
}


void TIMER1_INIT(){ /* initiates timer one */
		//DDRD |= (1<<PIND5);	/* Make OC1A pin as output */
		DIO_SetPinMode(DIO_PORTD,PIN5,OUTPUT);
		//TCNT1 = 0;		/* Set timer1 count zero */
		ICR1 = 2500;		/* Set TOP count for timer1 in ICR1 register */
		
		/* Set Fast PWM, TOP in ICR1, Clear OC1A on compare match, clk/64 */
		TCCR1A = (1<<WGM11)|(1<<COM1A1);
		TCCR1B = (1<<WGM12)|(1<<WGM13)|(1<<CS10)|(1<<CS11);
		TCCR1A|=(1<<COM1A1)|(1<<COM1B1)|(1<<WGM11);        //NON Inverted PWM
		TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)
		
		ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).

}

void TIMER1_OCR1(u8 value){ /* change the value of the OCR in timer one */
	OCR1A= value;
}