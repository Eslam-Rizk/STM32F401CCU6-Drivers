/*
 * USART_program.c
 *
 *  Created on: Jan 27, 2024
 *      Author: Eslam Rizk
 */

#include <stdint.h>
#include "BIT_MATH.h"        // Custom bit manipulation macros
#include "DMA_interface.h"   // DMA interface
#include "DMA_registers.h"   // DMA register definitions
#include "DMA_config.h"      // DMA configuration
#include "DMA_private.h"     // Private DMA configurations and definitions

/* Function pointer for DMA transfer complete callback */
static void (*CallBackFunc)(void);

/* Initialize the DMA channel with configured settings */
void MDMA_vChannelInit(void)
{
    /* Make sure that enable bit is cleared */
    CLR_BIT(DMA2->Stream[STREAM].CR , EN);
    /* Enable Direct Mode */
    SET_BIT(DMA2->Stream[STREAM].CR , 1);
    /* Enable Transfer complete Interrupt */
    SET_BIT(DMA2->Stream[STREAM].CR , 4);
    /* Data transfer direction >> MEM 2 MEM */
    SET_BIT(DMA2->Stream[STREAM].CR , 7);
    /* Set PINC & MIC */
    SET_BIT(DMA2->Stream[STREAM].CR , 9);
    SET_BIT(DMA2->Stream[STREAM].CR , 10);
    /* PSIZE & MSIZE= 32bit */
    SET_BIT(DMA2->Stream[STREAM].CR , 12);
    SET_BIT(DMA2->Stream[STREAM].CR , 14);
    /* Select Channel 0 >> Default channel */
}

/* Start a DMA transfer with the provided parameters */
void MDMA_vDMA_Start(uint32_t* pu32SourceAddress ,
                     uint32_t* pu32DestinationAddress,
                     uint16_t copy_u16Length,
                     void (*ptrFunc)(void))
{
    DMA2->Stream[STREAM].PAR = pu32SourceAddress;
    DMA2->Stream[STREAM].M0AR = pu32DestinationAddress;
    DMA2->Stream[STREAM].NDTR = copy_u16Length;
    CallBackFunc = ptrFunc;

    /* Clear Transfer complete interrupt flag */
    SET_BIT(DMA2->LIFCR , 5);
    /* DMA Start */
    SET_BIT(DMA2->Stream[STREAM].CR , EN);
}

/* DMA transfer complete interrupt handler */
void DMA2_Stream0_IRQHandler(void)
{
    CallBackFunc(); // Call the DMA transfer complete callback function
    /* Clear Transfer complete interrupt flag */
    SET_BIT(DMA2->LIFCR , 5);
}
