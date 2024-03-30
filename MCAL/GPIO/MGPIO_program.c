/*
 * USART_program.c
 *
 *  Created on: Jan 10, 2024
 *      Author: Eslam Rizk
 */
 #include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "MGPIO_config.h"
#include "MGPIO_private.h"
#include "MGPIO_register.h"

/* Set the mode of a GPIO pin */
void MGPIO_voidSetPinMode(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioMode_t Mode) {
	/* Set Mode to Pin */
	switch(PortNo) {
	case GPIO_PORTA:
		WRT_GROUP_OF_BITS(GPIOA_MODER, PinNo * 2, Mode, MASKING_TWO_BITS);
		break;
	case GPIO_PORTB:
		WRT_GROUP_OF_BITS(GPIOB_MODER, PinNo * 2, Mode, MASKING_TWO_BITS);
		break;
	case GPIO_PORTC:
		WRT_GROUP_OF_BITS(GPIOC_MODER, PinNo * 2, Mode, MASKING_TWO_BITS);
		break;
	}
}

/* Set the output type of a GPIO pin */
void MGPIO_voidSetPinOType(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioOtype_t OType) {
	/* Set OType to Pin */
	switch(PortNo) {
	case GPIO_PORTA:
		WRT_GROUP_OF_BITS(GPIOA_OTYPER, PinNo, OType, MASKING_ONE_BITS);
		break;
	case GPIO_PORTB:
		WRT_GROUP_OF_BITS(GPIOB_OTYPER, PinNo, OType, MASKING_ONE_BITS);
		break;
	case GPIO_PORTC:
		WRT_GROUP_OF_BITS(GPIOC_OTYPER, PinNo, OType, MASKING_ONE_BITS);
		break;
	}
}

/* Set the output speed of a GPIO pin */
void MGPIO_voidSetPinOSpeed(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioOSpeed_t OSpeed) {
	/* Set OSpeed to Pin */
	switch(PortNo) {
	case GPIO_PORTA:
		WRT_GROUP_OF_BITS(GPIOA_OSPEEDR, PinNo * 2, OSpeed, MASKING_TWO_BITS);
		break;
	case GPIO_PORTB:
		WRT_GROUP_OF_BITS(GPIOB_OSPEEDR, PinNo * 2, OSpeed, MASKING_TWO_BITS);
		break;
	case GPIO_PORTC:
		WRT_GROUP_OF_BITS(GPIOC_OSPEEDR, PinNo * 2, OSpeed, MASKING_TWO_BITS);
		break;
	}
}

/* Set the pull-up/pull-down configuration of a GPIO pin */
void MGPIO_voidSetPinPUPD(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioPUPD_t PUPD) {
	/* Set PUPD to Pin */
	switch(PortNo) {
	case GPIO_PORTA:
		WRT_GROUP_OF_BITS(GPIOA_PUPDR, PinNo * 2, PUPD, MASKING_TWO_BITS);
		break;
	case GPIO_PORTB:
		WRT_GROUP_OF_BITS(GPIOB_PUPDR, PinNo * 2, PUPD, MASKING_TWO_BITS);
		break;
	case GPIO_PORTC:
		WRT_GROUP_OF_BITS(GPIOC_PUPDR, PinNo * 2, PUPD, MASKING_TWO_BITS);
		break;
	}
}

/* Read the voltage level of a GPIO pin */
void MGPIO_voidGetPinValue(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioVoltLevel_t * P_enuVoltLevel) {
	switch(PortNo) {
	case GPIO_PORTA:
		*P_enuVoltLevel = GET_BIT(GPIOA_IDR, PinNo);
		break;
	case GPIO_PORTB:
		*P_enuVoltLevel = GET_BIT(GPIOB_IDR, PinNo);
		break;
	case GPIO_PORTC:
		*P_enuVoltLevel = GET_BIT(GPIOC_IDR, PinNo);
		break;
	}
}

/* Set the voltage level of a GPIO pin */
void MGPIO_voidSetPinValue(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioVoltLevel_t VoltLevel) {
	/* Set VoltLevel to Pin */
	switch(PortNo) {
	case GPIO_PORTA:
		WRT_GROUP_OF_BITS(GPIOA_ODR, PinNo, VoltLevel, MASKING_ONE_BITS);
		break;
	case GPIO_PORTB:
		WRT_GROUP_OF_BITS(GPIOB_ODR, PinNo, VoltLevel, MASKING_ONE_BITS);
		break;
	case GPIO_PORTC:
		WRT_GROUP_OF_BITS(GPIOC_ODR, PinNo, VoltLevel, MASKING_ONE_BITS);
		break;
	}
}

/* Set the mode, output type, and output speed of a GPIO pin */
void MGPIO_voidSetPinOutput(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioOtype_t OType, EN_GpioOSpeed_t OSpeed) {
	MGPIO_voidSetPinMode(PortNo, PinNo, GPIO_MODE_OUTPUT);
	MGPIO_voidSetPinOType(PortNo, PinNo, OType);
	MGPIO_voidSetPinOSpeed(PortNo, PinNo, OSpeed);
}

/* Set the mode and pull-up/pull-down configuration of a GPIO pin */
void MGPIO_voidSetPinInput(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioPUPD_t PUPD) {
	MGPIO_voidSetPinMode(PortNo, PinNo, GPIO_MODE_INPUT);
	MGPIO_voidSetPinPUPD(PortNo, PinNo, PUPD);
}

/* Toggle the voltage level of a GPIO pin */
void MGPIO_voidTogglePinValue(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo) {
	switch(PortNo) {
	case GPIO_PORTA:
		TOG_BIT(GPIOA_ODR, PinNo);
		break;
	case GPIO_PORTB:
		TOG_BIT(GPIOB_ODR, PinNo);
		break;
	case GPIO_PORTC:
		TOG_BIT(GPIOC_ODR, PinNo);
		break;
	}
}

/* Set the voltage level of 8 GPIO pins */
void MGPIO_voidSet8PinsValue(EN_GpioPortNo_t PortNo, EN_GpioPortLevelPins_t PortLevelPins, u8 Value) {
	switch(PortNo) {
	case GPIO_PORTA:
		WRT_GROUP_OF_BITS(GPIOA_ODR, PORT_LEVEL_PINS_START_BIT(PortLevelPins), Value, MASKING_EIGHT_BITS);
		break;
	case GPIO_PORTB:
		WRT_GROUP_OF_BITS(GPIOB_ODR, PORT_LEVEL_PINS_START_BIT(PortLevelPins), Value, MASKING_EIGHT_BITS);
		break;
	}
}
