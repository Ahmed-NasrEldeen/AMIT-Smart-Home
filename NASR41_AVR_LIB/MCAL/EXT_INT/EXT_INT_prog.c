/*
* EXT_INT_prog.c
*
* Created: 10/14/2022 10:02:06 AM
*  Author:D
*/

#include "EXT_INT_interface.h"


void GIE(){ /* General Interrupt Enable (not used)*/
	
	SET_BIT(SREG,7);
	
}

void GID(){ /* General Interrupt Disable (not used)*/
	
	CLR_BIT(SREG,7);
	
}

void EXT_INT_SET_MODE(u8 SOURCE ,u8 IRQ ){ /* sets the mode for the external interrupt to be assigned to INIT0, INIT1, INIT2 */
	
	switch(SOURCE){
		
		case INT0:
		SET_BIT(GICR,INT0_EN);
		
		MCUCR= (MCUCR & 0xFC)|IRQ;
		break;
		
		case INT1:
		SET_BIT(GICR,INT1_EN);
		
		MCUCR=(MCUCR & 0xF3)| IRQ<<2;
				
		break;
		
		case INT2:
		
		SET_BIT(GICR,INT2_EN);
		
		switch(IRQ){
			
			case IRQ_AT_FALLING_EDGE :
			CLR_BIT(MCUCSR,ISC2);
			break;
			
			
			case IRQ_AT_RAISING_EDGE :
			SET_BIT(MCUCSR,ISC2);
			break;
			
		}
		
		break;

	}
		
}