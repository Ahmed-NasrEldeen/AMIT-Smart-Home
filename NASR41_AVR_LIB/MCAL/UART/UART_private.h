/*
 * UART_private.h
 *
 * Created: 6/4/2022 8:29:57 PM
 *  Author:D
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_
   /*Parity Modes*/
   #define DISABLED        0
   #define EVEN_PARITY     2
   #define ODD_PARITY      3




   /*Stop Bits*/
   #define _1_BIT          0
   #define _2_BIT          1

   /*Data Size*/
   #define _5_BIT          0
   #define _6_BIT          1
   #define _7_BIT          2
   #define _8_BIT          3

   /*Baud Rates*/

   #define B_4800          207
   #define B_9600          103
   #define B_14400         68
   #define B_19200         51
   #define B_28800         34
   #define B_38400         25
   #define B_57600         16
   #define B_76800         12
   #define B_115200        8
   #define B_250000        3
   #define B_500000        1
   #define B_1000000       0

   #define UBRRL   (*(volatile u8 *) (0x29)	)
#define UBRRH   (*(volatile u8 *) (0x40)	)
   #define UCSRB   (*(volatile u8 *) (0x2A)	)
   #define TXB8    0
   #define RXB8    1
   #define UCSZ2   2
   #define TXEN    3
   #define RXEN    4
   #define UDRIE   5
   #define TXCIE   6
   #define RXCIE   7

   #define UCSRA  (*(volatile u8 *) (0x2B))
   #define MPCM    0
   #define U2X     1
   #define UPE     2
   #define DOR     3
   #define FE      4
   #define UDRE    5
   #define TXC     6
   #define RXC     7

   #define UDR     (*(volatile u8 *)(0x2C))
  
   #define UCSRC   (*(volatile u8 *)(0x40))
   #define UCPOL   0
   #define UCSZ0   1
   #define UCSZ1   2
   #define USBS    3
   #define UPM0    4
   #define UPM1    5
   #define UMSEL   6
   #define URSEL   7

#endif /* UART_PRIVATE_H_ */