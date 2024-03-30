/*
 * USART_register.h
 *
 *  Created on: Jan 28, 2024
 *      Author: Eslam Rizk
 */

#ifndef USART_REGISTER_H_
#define USART_REGISTER_H_

#include "STD_TYPES.h"  // Include standard data types

/* Base addresses for USART1 and USART2 peripherals */
#define USART1_BASE_ADDRESS 0x40011000  // Base address for USART1
#define USART2_BASE_ADDRESS 0x40004400  // Base address for USART2

/* Structure representing the USART registers */
typedef struct
{
    u32 SR;     /* Status register */
    u32 DR;     /* Data register */
    u32 BRR;    /* Baud rate register */
    u32 CR1;    /* Control register 1 */
    u32 CR2;    /* Control register 2 */
    u32 CR3;    /* Control register 3 */
    u32 GTPR;   /* Guard time and prescaler register */
} USART_t;

/* Pointer to the USART1 and USART2 peripherals */
#define USART1 ((volatile USART_t*)(USART1_BASE_ADDRESS))  // Pointer to USART1 peripheral
#define USART2 ((volatile USART_t*)(USART2_BASE_ADDRESS))  // Pointer to USART2 peripheral

#endif /* USART_REGISTER_H_ */
