/*
 * USART_program.c
 *
 *  Created on: Jan 18, 2024
 *      Author: Eslam Rizk
 */
 
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"
#include "STK_register.h"

/* Pointer to function for interval notification */
static void (*G_pfSetIntervalNotification)(void) = NULL;

/* State flag for interval mode */
static EN_IntervalState_t G_enuIntervalStateFlag = SYSTICK_INTERVAL_SINGLE;

/* Busy flag indicating if the SysTick timer is busy */
static EN_BusyFlag_t BusyFlag = NOT_BUSY;

/* Function to initialize the SysTick timer */
void MSTK_voidInit(void) {
    /* Configure SysTick control register with the selected clock source */
    STK->CTRL = (CLOCK_SOURCE_CONFIG_VALUE << CLOCK_SOURCE_BIT);
}

/* Function to generate a busy wait delay using the SysTick timer */
void MSTK_voidSetBusyWaitDelay(u32 Copy_u32Ticks) {
    if(BusyFlag == NOT_BUSY) {
        BusyFlag = BUSY;

        /* Reset Counter register */
        STK->VAL = 0;

        /* Set Load Register with the passed ticks value */
        STK->LOAD = Copy_u32Ticks;

        /* Enable Timer */
        SET_BIT(STK->CTRL, ENABLE_BIT);

        /* Wait till the flag has been raised */
        while(GET_BIT(STK->CTRL, COUNT_FLAG) == FLAG_NOT_READY) {
            /* Wait */
        }

        /* Disable Timer */
        CLR_BIT(STK->CTRL, ENABLE_BIT);

        /* Reset for the next time */
        STK->VAL = 0;
        STK->LOAD = 0;

        BusyFlag = NOT_BUSY;
    }
}

/* Function to set a single interval using the SysTick timer */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*pf_Notification)(void) ) {
    /* Setup the Environment */
    if(BusyFlag == NOT_BUSY) {
        BusyFlag = BUSY;

        STK->VAL = 0;
        STK->LOAD = Copy_u32Ticks;

        /* Enable Interrupt */
        SET_BIT(STK->CTRL, TICKINT_BIT);

        /* Save the pointer to function */
        G_pfSetIntervalNotification = pf_Notification;

        /* Enable Timer */
        SET_BIT(STK->CTRL, ENABLE_BIT);

        G_enuIntervalStateFlag = SYSTICK_INTERVAL_SINGLE;
    }
}

/* Function to set a periodic interval using the SysTick timer */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*pf_Notification)(void) ) {
    /* Setup the Environment */
    if(BusyFlag == NOT_BUSY) {
        BusyFlag = BUSY;

        STK->VAL = 0;
        STK->LOAD = Copy_u32Ticks;

        /* Enable Interrupt */
        SET_BIT(STK->CTRL, TICKINT_BIT);

        /* Save the pointer to function */
        G_pfSetIntervalNotification = pf_Notification;

        /* Enable Timer */
        SET_BIT(STK->CTRL, ENABLE_BIT);

        G_enuIntervalStateFlag = SYSTICK_INTERVAL_PERIODIC;
    }
}

/* Function to stop the SysTick timer */
void MSTK_voidTimerStop(void) {
    /* Disable Timer */
    CLR_BIT(STK->CTRL, ENABLE_BIT);

    /* Reset for the next time */
    STK->VAL = 0;
    STK->LOAD = 0;

    /* Disable Interrupt */
    CLR_BIT(STK->CTRL, TICKINT_BIT);

    BusyFlag = NOT_BUSY;
}

/* Function to get the elapsed time since the start of the interval */
void MSTK_voidGetElapsedTime(u32 *P_u32ReadVariable) {
    *P_u32ReadVariable = STK->LOAD - STK->VAL;
}

/* Function to get the remaining time until the end of the interval */
void MSTK_voidGetRemainingTime(u32 *P_u32ReadVariable) {
    *P_u32ReadVariable = STK->VAL;
}

/* SysTick timer interrupt handler */
void SysTick_Handler(void) {
    if(G_pfSetIntervalNotification != NULL) {
        switch(G_enuIntervalStateFlag) {
        case SYSTICK_INTERVAL_SINGLE:
            MSTK_voidTimerStop();
            G_pfSetIntervalNotification();
            break;
        case SYSTICK_INTERVAL_PERIODIC:
            G_pfSetIntervalNotification();
            break;
        }
    }
}
