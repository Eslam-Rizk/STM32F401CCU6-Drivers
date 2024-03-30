/*
 * USART_program.c
 *
 *  Created on: Jan 28, 2024
 *      Author: Eslam Rizk
 */

#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "USART_config.h"
#include "USART_interface.h"
#include "USART_private.h"
#include "USART_register.h"

/* Pointer to callback function */
static void (*USART_RxCallback)(void);

void USART_voidInit(void)
{
    // Set baud rate
    USART1->BRR = 0x00683; // Set the baud rate to 115200 (assuming a 16 MHz clock and oversampling by 16)

    // Stop bit configuration
    CLR_BIT(USART1->CR2, 12); // Configure for 1 stop bit
    CLR_BIT(USART1->CR2, 13); // Additional configuration (assuming 1 stop bit)

    // Word length configuration
    CLR_BIT(USART1->CR1, 12); // Configure for 8 data bits (assuming 1 start bit, 8 data bits, and 1 stop bit)

    // Sampling method configuration
    SET_BIT(USART1->CR1, 15); // Oversampling by 16 (assuming oversampling by 16)

    // One sample bit method configuration
    SET_BIT(USART1->CR3, 11); // One sample bit method (assuming one sample bit method)

    // Enable transmit
    SET_BIT(USART1->CR1, 3); // Enable transmission

    // Enable receive
    SET_BIT(USART1->CR1, 2); // Enable reception

    // Enable USART1
    SET_BIT(USART1->CR1, 13); // Enable USART1
}

void USART_voidSendData(u8 Copy_u8Data)
{
    USART1->DR = Copy_u8Data;    // Reset TXE to be zero

    while (GET_BIT(USART1->SR, 7) == 0);
}

u8 USART_u8ReceiveData(void)
{
    while ((GET_BIT(USART1->SR, 5)) != 1);
    return (u8)USART1->DR;
}

void USART_voidReceiveAsync(void (*ptr_func)(void))
{
    /* Set the callback function */
    USART_RxCallback = ptr_func;

    /* Enable USART Receive interrupt */
    SET_BIT(USART1->CR1, 5);
}

/* USART1 Interrupt Handler */
void USART1_IRQHandler(void)
{
    if (GET_BIT(USART1->SR, 5) && GET_BIT(USART1->CR1, 5))
    {
        /* Clear the interrupt flag */
        CLR_BIT(USART1->SR, 5);

        /* Call the callback function */
        if (USART_RxCallback != NULL)
        {
            USART_RxCallback();
        }
    }
}

void USART_voidEnable(void)
{
    // Enable USART1
    SET_BIT(USART1->CR1, 13); // Enable USART1
}

void USART_voidDisable(void)
{
    // Disable USART1
    CLR_BIT(USART1->CR1, 13); // Disable USART1
}

void USART_voidSendString(u8 *u8Data)
{
    /* Length of array */
    u8 L_u8SizeOfArray = sizeof(u8Data) / sizeof(u8Data[0]);
    for (u8 i = 0; i < L_u8SizeOfArray; i++)
    {
        USART_voidSendData(u8Data[i]);
    }
}
