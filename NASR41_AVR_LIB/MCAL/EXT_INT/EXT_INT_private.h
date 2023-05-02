/*
 * EXT_INT_private.h
 *
 * Created: 10/14/2022 10:00:00 AM
 *  Author:D
 */ 


#ifndef EXT_INT_PRIVATE_H_
#define EXT_INT_PRIVATE_H_

#define SREG         (   *(volatile u8 *) 0x5F )

#define GICR         (   *(volatile u8 *) 0x5B )

#define  INT1_EN     7
#define  INT0_EN	 6
#define  INT2_EN	 5

#define GIFR         (   *(volatile u8 *) 0x5A )

#define INTF2	     5
#define INTF0        6
#define INTF1        7

#define MCUCR        (   *(volatile u8 *) 0x55 )

#define ISC00        0
#define ISC01        1

#define ISC10        2
#define ISC11        3

#define MCUCSR       (   *(volatile u8 *) 0x54)

#define ISC2         6

 #define IRQ_AT_LOW_LEVEL          0
 #define IRQ_AT_ANY_LOGIC_CHANGE   1
 #define IRQ_AT_FALLING_EDGE       2
 #define IRQ_AT_RAISING_EDGE       3
 
 
 #define INT0  0
 #define INT1  1
 #define INT2  2



#endif /* EXT_INT_PRIVATE_H_ */