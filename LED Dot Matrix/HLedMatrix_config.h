/*
 * HLedMatrix_config.h
 *
 *  Created on: Jan 18, 2024
 *      Author: Eslam Rizk
 */

#ifndef HLEDMATRIX_CONFIG_H_
#define HLEDMATRIX_CONFIG_H_

/* GPIO port and pin configurations for controlling the LED matrix */
#define CTRL_PORT			GPIO_PORTB
#define CTRL_PIN0			GPIO_PIN00
#define CTRL_PIN1			GPIO_PIN01
#define CTRL_PIN2			GPIO_PIN02
#define CTRL_PIN3			GPIO_PIN03
#define CTRL_PIN4			GPIO_PIN04
#define CTRL_PIN5			GPIO_PIN05
#define CTRL_PIN6			GPIO_PIN06
#define CTRL_PIN7			GPIO_PIN07

/* GPIO port and pin configurations for data input to the LED matrix */
#define DATA_PORT			GPIO_PORTA
#define DATA_PIN0			GPIO_PIN00
#define DATA_PIN1			GPIO_PIN01
#define DATA_PIN2			GPIO_PIN02
#define DATA_PIN3			GPIO_PIN03
#define DATA_PIN4			GPIO_PIN04
#define DATA_PIN5			GPIO_PIN05
#define DATA_PIN6			GPIO_PIN06
#define DATA_PIN7			GPIO_PIN07

/* Disable and enable values */
#define DISABLE				HIGH
#define ENABLE				LOW

#endif /* HLEDMATRIX_CONFIG_H_ */
