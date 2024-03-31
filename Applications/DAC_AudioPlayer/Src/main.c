/*
 * HLedMatrix_private.h
 *
 *  Created on: Jan 30, 2024
 *      Author: Eslam Rizk
 */

#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STK_interface.h"
#include "MGPIO_interface.h"
#include "MRCC_interface.h"
#include "tune.h"


void tune();

int main(void)
{
	MRCC_voidInitSystemClock();
	MRCC_voidEnableVendorPerphiral(AHB1, AHB1_GPIOAEN);
	MSTK_voidInit();

	MGPIO_voidSetPinOutput(GPIO_PORTA, GPIO_PIN00, GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_HIGH);
	MGPIO_voidSetPinOutput(GPIO_PORTA, GPIO_PIN01, GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_HIGH);
	MGPIO_voidSetPinOutput(GPIO_PORTA, GPIO_PIN02, GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_HIGH);
	MGPIO_voidSetPinOutput(GPIO_PORTA, GPIO_PIN03, GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_HIGH);
	MGPIO_voidSetPinOutput(GPIO_PORTA, GPIO_PIN04, GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_HIGH);
	MGPIO_voidSetPinOutput(GPIO_PORTA, GPIO_PIN05, GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_HIGH);
	MGPIO_voidSetPinOutput(GPIO_PORTA, GPIO_PIN06, GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_HIGH);
	MGPIO_voidSetPinOutput(GPIO_PORTA, GPIO_PIN07, GPIO_OTYPE_PUSH_PULL, GPIO_OSPEED_HIGH);
	
	/*using periodic interupt*/
	MSTK_voidSetIntervalPeriodic(125, tune);
	/* Loop forever */
	while(1)
	{
		/*using busy wait*/
		/*for(u32 i=0;i<tune_raw_len;i++)
		{
			MGPIO_voidSet8PinsValue(GPIO_PORTA, GPIO_PORT_LOW_LEVEL_PINS, tune_raw[i]);
			MSTK_voidSetBusyWaitDelay(125);

		}*/
	}

}

/*function to iterate through audio array*/
void tune()
{
	static u32 i=0;
	MGPIO_voidSet8PinsValue(GPIO_PORTA, GPIO_PORT_LOW_LEVEL_PINS, tune_raw[i]);
	i++;
	if(i>=tune_raw_len)
	{
		i=0;
	}
}


