/*
 * USART_program.c
 *
 *  Created on: Jan 13, 2024
 *      Author: Eslam Rizk
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_Interface.h"
#include "NVIC_Private.h"
#include "NVIC_Config.h"

void MNVIC_voidInit(void)
{
    // Initialize NVIC with the configured group and sub-group distribution
    SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}

void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptNumber)
{
    if(Copy_u8InterruptNumber <= 31)
    {
        NVIC_ISER0 = (1 << Copy_u8InterruptNumber); // Enable interrupt for interrupt numbers 0 to 31
    }
    else if(Copy_u8InterruptNumber <= 63)
    {
        Copy_u8InterruptNumber -= 32;
        NVIC_ISER1 = (1 << Copy_u8InterruptNumber); // Enable interrupt for interrupt numbers 32 to 63
    }
    // No action required for interrupt numbers greater than 63
}

void MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptNumber)
{
    if(Copy_u8InterruptNumber <= 31)
    {
        NVIC_ICER0 = (1 << Copy_u8InterruptNumber); // Disable interrupt for interrupt numbers 0 to 31
    }
    else if(Copy_u8InterruptNumber <= 63)
    {
        Copy_u8InterruptNumber -= 32;
        NVIC_ICER1 = (1 << Copy_u8InterruptNumber); // Disable interrupt for interrupt numbers 32 to 63
    }
    // No action required for interrupt numbers greater than 63
}

void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptNumber)
{
    if(Copy_u8InterruptNumber <= 31)
    {
        NVIC_ISPR0 = (1 << Copy_u8InterruptNumber); // Set pending flag for interrupt numbers 0 to 31
    }
    else if(Copy_u8InterruptNumber <= 63)
    {
        Copy_u8InterruptNumber -= 32;
        NVIC_ISPR1 = (1 << Copy_u8InterruptNumber); // Set pending flag for interrupt numbers 32 to 63
    }
    // No action required for interrupt numbers greater than 63
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptNumber)
{
    if(Copy_u8InterruptNumber <= 31)
    {
        NVIC_ICPR0 = (1 << Copy_u8InterruptNumber); // Clear pending flag for interrupt numbers 0 to 31
    }
    else if(Copy_u8InterruptNumber <= 63)
    {
        Copy_u8InterruptNumber -= 32;
        NVIC_ICPR1 = (1 << Copy_u8InterruptNumber); // Clear pending flag for interrupt numbers 32 to 63
    }
    // No action required for interrupt numbers greater than 63
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber)
{
    u8 Local_u8Result = 0;
    if(Copy_u8InterruptNumber <= 31)
    {
        Local_u8Result = GET_BIT(NVIC_IABR0 , Copy_u8InterruptNumber); // Get active flag for interrupt numbers 0 to 31
    }
    else if(Copy_u8InterruptNumber <= 63)
    {
        Copy_u8InterruptNumber -= 32;
        Local_u8Result = GET_BIT(NVIC_IABR1 , Copy_u8InterruptNumber); // Get active flag for interrupt numbers 32 to 63
    }
    // No action required for interrupt numbers greater than 63
    return Local_u8Result;
}

void MNVIC_voidSetPriority(u8 copy_u8PeripheralIdx ,u8 copy_u8Priority)
{
    if(copy_u8PeripheralIdx < 60)
    {
        NVIC_IPR[copy_u8PeripheralIdx] = copy_u8Priority; // Set priority for the specified peripheral index
    }
    else
    {
        // Report Error: Invalid peripheral index
    }
}
