/*
 * DMA_registers.h
 *
 *  Created on: Jan 27, 2024
 *      Author: Eslam Rizk
 */

#ifndef DMA_REGISTERS_H_
#define DMA_REGISTERS_H_

/* Base address for DMA2 peripheral */
#define DMA2_BASE_ADDRESS   0x40026400

/* Structure representing a DMA stream */
typedef struct {
    volatile uint32_t CR;    /* Control register */
    volatile uint32_t NDTR;  /* Number of data register */
    volatile uint32_t PAR;   /* Peripheral address register */
    volatile uint32_t M0AR;  /* Memory 0 address register */
    volatile uint32_t M1AR;  /* Memory 1 address register */
    volatile uint32_t FCR;   /* FIFO control register */
} DMA_Stream_t;

/* Structure representing DMA registers */
typedef struct {
    volatile uint32_t LISR;          /* Low interrupt status register */
    volatile uint32_t HISR;          /* High interrupt status register */
    volatile uint32_t LIFCR;         /* Low interrupt flag clear register */
    volatile uint32_t HIFCR;         /* High interrupt flag clear register */
    volatile DMA_Stream_t Stream[8]; /* DMA stream registers */
} DMA_t;

/* Pointer to the DMA2 peripheral */
#define DMA2    ((volatile DMA_t*)(DMA2_BASE_ADDRESS))

#endif /* DMA_REGISTERS_H_ */
