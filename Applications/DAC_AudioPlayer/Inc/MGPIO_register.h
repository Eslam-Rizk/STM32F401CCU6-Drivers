/*
 * USART_program.c
 *
 *  Created on: Jan 10, 2024
 *      Author: Eslam Rizk
 */
 
#ifndef MGPIO_REGISTER_H
#define MGPIO_REGISTER_H

/* Define base addresses for GPIO ports */
#define MGPIOA_BASE_ADDRESS     (0x40020000)
#define MGPIOB_BASE_ADDRESS     (0x40020400)
#define MGPIOC_BASE_ADDRESS     (0x40020800)

/* Define registers for GPIO port A */
#define GPIOA_MODER             (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x00))
#define GPIOA_OTYPER            (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x04))
#define GPIOA_OSPEEDR           (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x08))
#define GPIOA_PUPDR             (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x0C))
#define GPIOA_IDR               (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x10))
#define GPIOA_ODR               (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x14))
#define GPIOA_BSRR              (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x18))
#define GPIOA_LCKR              (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x1C))
#define GPIOA_AFRL              (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x20))
#define GPIOA_AFRH              (*(volatile uint32_t*)(MGPIOA_BASE_ADDRESS + 0x24))

/* Define registers for GPIO port B */
#define GPIOB_MODER             (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x00))
#define GPIOB_OTYPER            (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x04))
#define GPIOB_OSPEEDR           (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x08))
#define GPIOB_PUPDR             (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x0C))
#define GPIOB_IDR               (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x10))
#define GPIOB_ODR               (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x14))
#define GPIOB_BSRR              (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x18))
#define GPIOB_LCKR              (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x1C))
#define GPIOB_AFRL              (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x20))
#define GPIOB_AFRH              (*(volatile uint32_t*)(MGPIOB_BASE_ADDRESS + 0x24))

/* Define registers for GPIO port C */
#define GPIOC_MODER             (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x00))
#define GPIOC_OTYPER            (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x04))
#define GPIOC_OSPEEDR           (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x08))
#define GPIOC_PUPDR             (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x0C))
#define GPIOC_IDR               (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x10))
#define GPIOC_ODR               (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x14))
#define GPIOC_BSRR              (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x18))
#define GPIOC_LCKR              (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x1C))
#define GPIOC_AFRL              (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x20))
#define GPIOC_AFRH              (*(volatile uint32_t*)(MGPIOC_BASE_ADDRESS + 0x24))

#endif
