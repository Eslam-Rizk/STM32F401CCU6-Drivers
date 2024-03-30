/*
 * USART_program.c
 *
 *  Created on: Jan 27, 2024
 *      Author: Eslam Rizk
 */

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_

#include <stdint.h>

/* Function prototypes */

/**
 * @brief Initialize the DMA channel with configured settings.
 */
void MDMA_vChannelInit(void);

/**
 * @brief Start a DMA transfer with the provided parameters.
 *
 * @param pu32SourceAddress Pointer to the source data array.
 * @param pu32DestinationAddress Pointer to the destination data array.
 * @param copy_u16Length Number of data elements to transfer.
 * @param ptrFunc Pointer to the function to be called when the DMA transfer is complete.
 */
void MDMA_vDMA_Start(uint32_t *pu32SourceAddress,
                     uint32_t *pu32DestinationAddress,
                     uint16_t copy_u16Length,
                     void (*ptrFunc)(void));

#endif /* DMA_INTERFACE_H_ */
