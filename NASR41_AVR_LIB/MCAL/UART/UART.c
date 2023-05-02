/*
* UART.c
*
* Created: 6/25/2021 1:28:22 PM
*  Author:D
*/

#define F_CPU 8000000UL			/* Define frequency here its 8MHz */
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>
#include "UART.h"

#define USART_BAUDRATE 9600
#define BAUD_PRESCALE (((F_CPU / (9600 * 16UL))) - 1)

void UART_INIT(void) /* initiates UART */
{

	UBRRH = (BAUD_PRESCALE >> 8);
	UBRRL = BAUD_PRESCALE;			/* Load lower 8-bits of the baud rate */
	UCSRB = (1 << RXEN) | (1 << TXEN)|(1<<RXCIE)	;/* Turn on transmission and reception */
	UCSRC = (1 << URSEL) | (1 << UCSZ0) | (1 << UCSZ1);/* Use 8-bit char size */
		
}

void UART_Transmit(u8 DATA) /* Sends a char to the UART */
{

	while (! (UCSRA & (1<<UDRE)));	/* Wait for empty transmit buffer*/
	UDR = DATA ;

}


u8 UART_Recieve(void) /* Sends a char to the UART */
{

	while (!(UCSRA & (1 << RXC)));/* Wait till data is received */
	return(UDR);		/* Return the byte */
	
}

void UART_SendString(char *str) /* Sends a string to the UART */
{
	unsigned char j=0;
	
	while (str[j]!=0)		/* Send string till null */
	{
		UART_Transmit(str[j]);
		j++;
	}
}
