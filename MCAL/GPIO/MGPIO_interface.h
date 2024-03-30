/*
 * USART_program.c
 *
 *  Created on: Jan 10, 2024
 *      Author: Eslam Rizk
 */
 #ifndef MGPIO_INTERFACE_H
#define MGPIO_INTERFACE_H

#include "../LIB/STD_TYPES.h"

/* Mapping Controller Ports into numeric values */
typedef enum {
    GPIO_PORTA = 1,
    GPIO_PORTB,
    GPIO_PORTC,
} EN_GpioPortNo_t;

/* Mapping Controller pins into numeric values */
typedef enum {
    GPIO_PIN00 = 0,
    GPIO_PIN01,
    GPIO_PIN02,
    GPIO_PIN03,
    GPIO_PIN04,
    GPIO_PIN05,
    GPIO_PIN06,
    GPIO_PIN07,
    GPIO_PIN08,
    GPIO_PIN09,
    GPIO_PIN10,
    GPIO_PIN11,
    GPIO_PIN12,
    GPIO_PIN13,
    GPIO_PIN14,
    GPIO_PIN15,
} EN_GpioPinNo_t;

/* Mapping Gpio Modes into numeric values */
typedef enum {
    GPIO_MODE_INPUT = 0,
    GPIO_MODE_OUTPUT,
    GPIO_MODE_ALTERNATE_FUNCTION,
    GPIO_MODE_ANALOG,
} EN_GpioMode_t;

/* Mapping Gpio Output Types into numeric values */
typedef enum {
    GPIO_OTYPE_PUSH_PULL = 0,
    GPIO_OTYPE_OPEN_DRAIN,
} EN_GpioOtype_t;

/* Mapping Gpio Output Speeds into numeric values */
typedef enum {
    GPIO_OSPEED_LOW = 0,
    GPIO_OSPEED_MEDIUM,
    GPIO_OSPEED_HIGH,
    GPIO_OSPEED_VERY_HIGH,
} EN_GpioOSpeed_t;

/* Mapping Gpio internal pull resistors into numeric values */
typedef enum {
    GPIO_PUPD_NOT_PULLED = 0,
    GPIO_PUPD_PULL_UP,
    GPIO_PUPD_PULL_DOWN,
} EN_GpioPUPD_t;

/* Mapping Gpio voltage levels into numeric values */
typedef enum {
    GPIO_VOLT_LEVEL_LOW = 0,
    GPIO_VOLT_LEVEL_HIGH,
} EN_GpioVoltLevel_t;

/* Function prototypes */
void MGPIO_voidSetPinOutput(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioOtype_t OType, EN_GpioOSpeed_t OSpeed);
void MGPIO_voidSetPinInput(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioPUPD_t PUPD);
void MGPIO_voidSetPinMode(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioMode_t Mode);
void MGPIO_voidSetPinOType(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioOtype_t OType);
void MGPIO_voidSetPinOSpeed(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioOSpeed_t OSpeed);
void MGPIO_voidSetPinPUPD(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioPUPD_t PUPD);
void MGPIO_voidSetPinValue(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioVoltLevel_t VoltLevel);
void MGPIO_voidGetPinValue(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo, EN_GpioVoltLevel_t * P_enuVoltLevel);
void MGPIO_voidTogglePinValue(EN_GpioPortNo_t PortNo, EN_GpioPinNo_t PinNo);
void MGPIO_voidSet8PinsValue(EN_GpioPortNo_t PortNo, EN_GpioPortLevelPins_t PortLevelPins, uint8_t Value);

#endif
