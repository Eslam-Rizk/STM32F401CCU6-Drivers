/*
 * HLedMatrix_private.h
 *
 *  Created on: Jan 18, 2024
 *      Author: Eslam Rizk
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MGPIO_interface.h"
#include "STK_interface.h"

#include "HLedMatrix_interface.h"
#include "HLedMatrix_private.h"
#include "HLedMatrix_config.h"

/* Function to initialize the LED matrix GPIO pins */
void HLedMatrix_voidInit(void)
{
    /* Set 16 GPIOs as OUTPUT PP.*/
    /* Configure control pins as output */
    MGPIO_voidSetPinOutput(CTRL_PORT, CTRL_PIN0 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(CTRL_PORT, CTRL_PIN1 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(CTRL_PORT, CTRL_PIN2 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(CTRL_PORT, CTRL_PIN3 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(CTRL_PORT, CTRL_PIN4 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(CTRL_PORT, CTRL_PIN5 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(CTRL_PORT, CTRL_PIN6 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(CTRL_PORT, CTRL_PIN7 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);

    /* Configure Data pins as output */
    MGPIO_voidSetPinOutput(DATA_PORT, DATA_PIN0 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(DATA_PORT, DATA_PIN1 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(DATA_PORT, DATA_PIN2 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(DATA_PORT, DATA_PIN3 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(DATA_PORT, DATA_PIN4 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(DATA_PORT, DATA_PIN5 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(DATA_PORT, DATA_PIN6 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);
    MGPIO_voidSetPinOutput(DATA_PORT, DATA_PIN7 ,GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_MEDIUM);

    /* Disable for All control pins */
    MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN0, DISABLE);
    MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN1, DISABLE);
    MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN2, DISABLE);
    MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN3, DISABLE);
    MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN4, DISABLE);
    MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN5, DISABLE);
    MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN6, DISABLE);
    MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN7, DISABLE);
}

/* Function to display a row of data on the LED matrix */
void HDisplayRowData(u8 Copy_u8ROWData)
{
    MGPIO_voidSetPinValue(DATA_PORT, DATA_PIN0, GET_BIT(Copy_u8ROWData , 0));
    MGPIO_voidSetPinValue(DATA_PORT, DATA_PIN1, GET_BIT(Copy_u8ROWData , 1));
    MGPIO_voidSetPinValue(DATA_PORT, DATA_PIN2, GET_BIT(Copy_u8ROWData , 2));
    MGPIO_voidSetPinValue(DATA_PORT, DATA_PIN3, GET_BIT(Copy_u8ROWData , 3));
    MGPIO_voidSetPinValue(DATA_PORT, DATA_PIN4, GET_BIT(Copy_u8ROWData , 4));
    MGPIO_voidSetPinValue(DATA_PORT, DATA_PIN5, GET_BIT(Copy_u8ROWData , 5));
    MGPIO_voidSetPinValue(DATA_PORT, DATA_PIN6, GET_BIT(Copy_u8ROWData , 6));
    MGPIO_voidSetPinValue(DATA_PORT, DATA_PIN7, GET_BIT(Copy_u8ROWData , 7));


void DisplayShape(u8 *shape)
{
	/*display 1st row*/
	HDisplayRowData(shape[0]);
	/* Enable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN0, ENABLE);
	/* Delay for 2.5msec */
	MSTK_voidSetBusyWaitDelay(2000);
	/* Disable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN0, DISABLE);

	/*display 2nd row*/
	HDisplayRowData(shape[1]);
	/* Enable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN1, ENABLE);
	/* Delay for 2.5msec */
	MSTK_voidSetBusyWaitDelay(2000);
	/* Disable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN1, DISABLE);

	/*display 3rd row*/
	HDisplayRowData(shape[2]);
	/* Enable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN2, ENABLE);
	/* Delay for 2.5msec */
	MSTK_voidSetBusyWaitDelay(2000);
	/* Disable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN2, DISABLE);

	/*display 4th row*/
	HDisplayRowData(shape[3]);
	/* Enable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN3, ENABLE);
	/* Delay for 2.5msec */
	MSTK_voidSetBusyWaitDelay(2000);
	/* Disable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN3, DISABLE);

	/*display 5th row*/
	HDisplayRowData(shape[4]);
	/* Enable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN4, ENABLE);
	/* Delay for 2.5msec */
	MSTK_voidSetBusyWaitDelay(2000);
	/* Disable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN4, DISABLE);

	/*display 6th row*/
	HDisplayRowData(shape[5]);
	/* Enable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN5, ENABLE);
	/* Delay for 2.5msec */
	MSTK_voidSetBusyWaitDelay(2000);
	/* Disable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN5, DISABLE);

	/*display 7th row*/
	HDisplayRowData(shape[6]);
	/* Enable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN6, ENABLE);
	/* Delay for 2.5msec */
	MSTK_voidSetBusyWaitDelay(2000);
	/* Disable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN6, DISABLE);

	
	/*display 8th row*/
	HDisplayRowData(shape[7]);
	/* Enable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN7, ENABLE);
	/* Delay for 2.5msec */
	MSTK_voidSetBusyWaitDelay(2000);
	/* Disable current Column */
	MGPIO_voidSetPinValue(CTRL_PORT, CTRL_PIN7, DISABLE);
}

void DisplayShiftingShape(u16 *cpy_shape) //pointer to array of pointers to u8
{
	/*u16 to Shift in and out on the led matrix*/
	u16 shapeArr[8];

	for(u8 i =0 ; i<8 ; i++)
	{
		shapeArr[i] = cpy_shape[i];
	}

	/*shift each char 16 times to shift in and out*/
	for(u32 j=0 ; j<16 ; j++)
	{
		/*pointer of index i that points to u16*/
		ShiftThenDisplayShape(shapeArr);
		MSTK_voidSetBusyWaitDelay(1000);
	}
}

void ShiftThenDisplayShape(u16 *cpy_shape)
{
	/*u8 array to hold shifted shape*/
	u8 shaprArr[8];

	for(u8 i=0 ; i<8 ; i++)
	{
		/*Right shift bit8:bit15 to bit0:bit7 and cast it with u8, then Save it in shapeArr array*/
		shaprArr[i] = (u8)(cpy_shape[i] >> 8);
	}
	/*DisplayShape*/
	for(u8 i=0 ; i<10 ; i++)
	{
		DisplayShape(shaprArr);
	}

	/*Character Shift-Lift*/
	for(u8 i=0 ; i<8 ; i++)
	{
		cpy_shape[i] <<= 1;
	}

}
