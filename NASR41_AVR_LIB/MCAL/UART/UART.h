/*
 * UART.h
 *
 * Created: 6/25/2021 1:28:45 PM
 *  Author:D
 */ 


#ifndef UART_H_
#define UART_H_

#include "UART_CFG.h"
#include "DIO_interface.h"




void UART_INIT(void);

u8 UART_Recieve(void);

void UART_Transmit(u8 DATA);
void UART_SendString(char *str);





#endif /* UART_H_ */