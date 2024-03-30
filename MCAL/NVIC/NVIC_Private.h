/*
 * USART_program.c
 *
 *  Created on: Jan 13, 2024
 *      Author: Eslam Rizk
 */

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H

/* Base address for NVIC */
#define NVIC_BASE_ADDRESS       0xE000E100

/* NVIC register offsets */
#define NVIC_ISER0_OFFSET       0x0000  /* Enable External Interrupt from 0 to 31 */
#define NVIC_ISER1_OFFSET       0x0004  /* Enable External Interrupt from 32 to 63 */
#define NVIC_ICER0_OFFSET       0x0080  /* Disable External Interrupt from 0 to 31 */
#define NVIC_ICER1_OFFSET       0x0084  /* Disable External Interrupt from 32 to 63 */
#define NVIC_ISPR0_OFFSET       0x0200  /* Set Pending flag from 0 to 31 */
#define NVIC_ISPR1_OFFSET       0x0204  /* Set Pending flag from 32 to 63 */
#define NVIC_ICPR0_OFFSET       0x0280  /* Clear Pending flag from 0 to 31 */
#define NVIC_ICPR1_OFFSET       0x0284  /* Clear Pending flag from 32 to 63 */
#define NVIC_IABR0_OFFSET       0x0300  /* Interrupt Active bit register from 0 to 31 (Read Only Register) */
#define NVIC_IABR1_OFFSET       0x0304  /* Interrupt Active bit register from 32 to 63 (Read Only Register) */
#define NVIC_IPR_OFFSET         0x0400  /* Interrupt priority Base Address */
#define SCB_AIRCR_OFFSET        0x0D0C  /* Application Interrupt and reset control register */

/* Macros for NVIC register access */
#define NVIC_ISER0              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_ISER0_OFFSET)))
#define NVIC_ISER1              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_ISER1_OFFSET)))
#define NVIC_ICER0              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_ICER0_OFFSET)))
#define NVIC_ICER1              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_ICER1_OFFSET)))
#define NVIC_ISPR0              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_ISPR0_OFFSET)))
#define NVIC_ISPR1              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_ISPR1_OFFSET)))
#define NVIC_ICPR0              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_ICPR0_OFFSET)))
#define NVIC_ICPR1              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_ICPR1_OFFSET)))
#define NVIC_IABR0              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_IABR0_OFFSET)))
#define NVIC_IABR1              (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + NVIC_IABR1_OFFSET)))
#define NVIC_IPR                ((volatile uint8_t*)(NVIC_BASE_ADDRESS + NVIC_IPR_OFFSET))
#define SCB_AIRCR               (*((volatile uint32_t*)(NVIC_BASE_ADDRESS + SCB_AIRCR_OFFSET)))

/* Macros for NVIC group and sub-group distributions */
#define MNVIC_GROUP_4_SUB_0     0x05FA0300
#define MNVIC_GROUP_3_SUB_1     0x05FA0400
#define MNVIC_GROUP_2_SUB_2     0x05FA0500
#define MNVIC_GROUP_1_SUB_3     0x05FA0600
#define MNVIC_GROUP_0_SUB_4     0x05FA0700

#endif /* NVIC_PRIVATE_H */
