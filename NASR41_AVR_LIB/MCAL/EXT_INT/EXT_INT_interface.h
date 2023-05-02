/*
 * EXT_INT_interface.h
 *
 * Created: 10/14/2022 10:01:36 AM
 *  Author:D
 */ 


#ifndef EXT_INT_INTERFACE_H_
#define EXT_INT_INTERFACE_H_

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXT_INT_config.h"
#include "EXT_INT_private.h"

/********* @para : SOURCE ********
 INT0  , INT1 , INT2 
*************@para :IRQ **************
 
 IRQ_AT_LOW_LEVEL  
 IRQ_AT_ANY_LOGIC_CHANGE  
 IRQ_AT_FALLING_EDGE   
 IRQ_AT_RAISING_EDGE   

*********************************************************************/
 void GIE(); //	GENERAL INTERRUPT ENABLE
 void GID();  //	GENERAL INTERRUPT DISABLE
 void EXT_INT_SET_MODE(u8 SOURCE ,u8 IRQ);

 
 


#endif /* EXT_INT_INTERFACE_H_ */