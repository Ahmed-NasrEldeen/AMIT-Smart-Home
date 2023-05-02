/*
 * EEPROM_private.h
 *
 * Created: 12/16/2022 8:39:13 PM
 *  Author:D
 */ 


#ifndef EEPROM_PRIVATE_H_
#define EEPROM_PRIVATE_H_

//#define  EEARH (*( (volatile u8 *) 0x3F))
//#define  EEAR9		1
//#define  EEAR8		0
#define  EEAR  (*((volatile u16 *)0x3E))// EEARL  + EEARH

#define EEDR (*((volatile u8 *)0x3D))

#define EECR (*((volatile u8 *)0x3C))
#define EERIE   3
#define EEMWE   2
#define EEWE    1
#define EERE    0







#endif /* EEPROM_PRIVATE_H_ */