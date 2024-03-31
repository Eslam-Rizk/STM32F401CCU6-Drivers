/*
 * USART_program.c
 *
 *  Created on: Jan 18, 2024
 *      Author: Eslam Rizk
 */
 
#ifndef STK_REGISTER_H_
#define STK_REGISTER_H_

#include "STD_TYPES.h"

/* Structure representing the SysTick registers */
typedef struct {
    u32 CTRL;   /* Control register */
    u32 LOAD;   /* Load value register */
    u32 VAL;    /* Current value register */
    u32 CALIB;  /* Calibration value register */
} ST_Systick_t;

/* Base address of the SysTick peripheral */
#define SYSTICK_BASE_ADDRESS    (0xE000E010)

/* Pointer to the SysTick peripheral */
#define STK     ((volatile ST_Systick_t *)(SYSTICK_BASE_ADDRESS))

/* Bit positions in the SysTick control register */
#define CLOCK_SOURCE_BIT    (2)
#define ENABLE_BIT          (0)
#define COUNT_FLAG          (16)
#define TICKINT_BIT         (1)

#endif /* STK_REGISTER_H_ */
