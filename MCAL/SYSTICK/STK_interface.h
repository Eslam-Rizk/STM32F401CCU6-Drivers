/*
 * USART_program.c
 *
 *  Created on: Jan 18, 2024
 *      Author: Eslam Rizk
 */
 
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/* Function: MSTK_voidInit
 * Description: Initializes the SysTick timer.
 * Parameters: None
 * Return: None
 */
void MSTK_voidInit(void);

/* Function: MSTK_voidSetBusyWaitDelay
 * Description: Sets a busy-wait delay using the SysTick timer.
 * Parameters:
 *   Copy_u32Ticks: The number of ticks to wait
 * Return: None
 */
void MSTK_voidSetBusyWaitDelay(u32 Copy_u32Ticks);

/* Function: MSTK_voidSetIntervalSingle
 * Description: Sets a single interval timer using the SysTick timer.
 *              When the timer expires, the provided callback function
 *              pf_Notification will be called.
 * Parameters:
 *   Copy_u32Ticks: The number of ticks to wait
 *   pf_Notification: Pointer to the callback function
 * Return: None
 */
void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks, void (*pf_Notification)(void));

/* Function: MSTK_voidSetIntervalPeriodic
 * Description: Sets a periodic interval timer using the SysTick timer.
 *              When the timer expires, the provided callback function
 *              pf_Notification will be called, and the timer will automatically
 *              reload the specified interval.
 * Parameters:
 *   Copy_u32Ticks: The number of ticks to wait
 *   pf_Notification: Pointer to the callback function
 * Return: None
 */
void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks, void (*pf_Notification)(void));

/* Function: MSTK_voidTimerStop
 * Description: Stops the SysTick timer.
 * Parameters: None
 * Return: None
 */
void MSTK_voidTimerStop(void);

/* Function: MSTK_voidGetElapsedTime
 * Description: Retrieves the elapsed time since the last timer start in milliseconds
 *              and stores it in the variable pointed to by P_u32ReadVariable.
 * Parameters:
 *   P_u32ReadVariable: Pointer to the variable to store the elapsed time
 * Return: None
 */
void MSTK_voidGetElapsedTime(u32 *P_u32ReadVariable);

/* Function: MSTK_voidGetRemainingTime
 * Description: Retrieves the remaining time until the timer expires in milliseconds
 *              and stores it in the variable pointed to by P_u32ReadVariable.
 * Parameters:
 *   P_u32ReadVariable: Pointer to the variable to store the remaining time
 * Return: None
 */
void MSTK_voidGetRemainingTime(u32 *P_u32ReadVariable);

#endif // STK_INTERFACE_H
