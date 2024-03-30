/*
 * USART_interface.h
 *
 *  Created on: Jan 28, 2024
 *      Author: Eslam Rizk
 */

#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

/* Description: Initialize USART peripheral */
void USART_voidInit(void);

/* Description: Send a single byte of data via USART */
void USART_voidSendData(u8 Copy_u8Data);

/* Description: Receive a single byte of data via USART */
u8 USART_u8ReceiveData(void);

/* Description: Enable asynchronous receive mode with a callback function */
void USART_voidReceiveAsync(void (*ptr_func)(void));

/* Description: Enable USART peripheral */
void USART_voidEnable(void);

/* Description: Disable USART peripheral */
void USART_voidDisable(void);

/* Description: Send a string of data via USART */
void USART_voidSendString(u8 *Copy_pu8Data);

/* Description: Set a callback function to be called when data is received asynchronously */
void USART_voidCallBack(void (*ptr_func)(void));

#endif /* USART_INTERFACE_H_ */
