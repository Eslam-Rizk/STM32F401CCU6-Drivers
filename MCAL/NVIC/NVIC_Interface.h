/*
 * USART_program.c
 *
 *  Created on: Jan 13, 2024
 *      Author: Eslam Rizk
 */

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

/* Function prototypes */

/**
 * @brief Enable interrupt for the specified interrupt number.
 * 
 * @param Copy_u8InterruptNumber: The interrupt number to enable.
 */
void MNVIC_voidEnableInterrupt(u8 Copy_u8InterruptNumber);

/**
 * @brief Disable interrupt for the specified interrupt number.
 * 
 * @param Copy_u8InterruptNumber: The interrupt number to disable.
 */
void MNVIC_voidDisableInterrupt(u8 Copy_u8InterruptNumber);

/**
 * @brief Set pending flag for the specified interrupt number.
 * 
 * @param Copy_u8InterruptNumber: The interrupt number to set pending flag for.
 */
void MNVIC_voidSetPendingFlag(u8 Copy_u8InterruptNumber);

/**
 * @brief Clear pending flag for the specified interrupt number.
 * 
 * @param Copy_u8InterruptNumber: The interrupt number to clear pending flag for.
 */
void MNVIC_voidClearPendingFlag(u8 Copy_u8InterruptNumber);

/**
 * @brief Get the active flag status for the specified interrupt number.
 * 
 * @param Copy_u8InterruptNumber: The interrupt number to check for active flag.
 * 
 * @return u8: The active flag status (1 for active, 0 for inactive).
 */
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8InterruptNumber);

/**
 * @brief Initialize the NVIC module.
 * 
 * This function initializes the NVIC module.
 */
void MNVIC_voidInit(void);

/**
 * @brief Set the priority for the specified peripheral index.
 * 
 * @param copy_u8PeripheralIdx: The peripheral index to set the priority for.
 * @param copy_u8Priority: The priority value to set.
 */
void MNVIC_voidSetPriority(u8 copy_u8PeripheralIdx, u8 copy_u8Priority);

#endif /* NVIC_INTERFACE_H */
