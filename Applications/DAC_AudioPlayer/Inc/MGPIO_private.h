/*
 * USART_program.c
 *
 *  Created on: Jan 10, 2024
 *      Author: Eslam Rizk
 */
 
 #ifndef MGPIO_PRIVATE_H
#define MGPIO_PRIVATE_H

#define MASKING_TWO_BITS	(0b11)

#define MASKING_ONE_BITS	(0b1)

/* Used in the Set8PinsValue API */
#define MASKING_EIGHT_BITS				(0xFF)
#define PORT_LEVEL_PINS_START_BIT(X)	( (X) * 8 )

#endif
