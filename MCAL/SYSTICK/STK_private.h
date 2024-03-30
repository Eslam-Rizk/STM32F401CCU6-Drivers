/*
 * USART_program.c
 *
 *  Created on: Jan 18, 2024
 *      Author: Eslam Rizk
 */
 
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/* Enumeration: EN_IntervalState_t
 * Description: Enumeration representing the state of the SysTick timer interval.
 * Values:
 *   - SYSTICK_INTERVAL_SINGLE: Single interval mode
 *   - SYSTICK_INTERVAL_PERIODIC: Periodic interval mode
 */
typedef enum {
    SYSTICK_INTERVAL_SINGLE,
    SYSTICK_INTERVAL_PERIODIC,
} EN_IntervalState_t;

/* Enumeration: EN_BusyFlag_t
 * Description: Enumeration representing the busy flag state.
 * Values:
 *   - NOT_BUSY: Indicates that the SysTick timer is not busy
 *   - BUSY: Indicates that the SysTick timer is busy
 */
typedef enum {
    NOT_BUSY = 0,
    BUSY
} EN_BusyFlag_t;

/* Constants: AHB_DIVIDED_BY_8, AHB_CLOCK_FREQ
 * Description: Constants representing clock division options for the SysTick timer.
 *   - AHB_DIVIDED_BY_8: AHB clock divided by 8
 *   - AHB_CLOCK_FREQ: AHB clock frequency
 */
#define AHB_DIVIDED_BY_8    (0)
#define AHB_CLOCK_FREQ      (1)

/* Constant: FLAG_NOT_READY
 * Description: Constant representing the not ready flag state.
 */
#define FLAG_NOT_READY  (0)

#endif // STK_PRIVATE_H
