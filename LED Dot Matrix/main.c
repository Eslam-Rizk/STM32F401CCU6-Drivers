/*
 * HLedMatrix_private.h
 *
 *  Created on: Jan 18, 2024
 *      Author: Eslam Rizk
 */

#include <stdint.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"
#include "STK_interface.h"

#include "HLedMatrix_interface.h"

/* Define shapes as arrays of u16 */
u16 E_shape[] = {0xff,0xff,0xc0,0xff,0xff,0xc0,0xff,0xff};
u16 S_shape[] = {0xff,0xff,0xc0,0xff,0xff,0x03,0xff,0xff};
u16 L_shape[] = {0xc0,0xc0,0xc0,0xc0,0xc0,0xc0,0xff,0xff};
u16 A_shape[] = {0xff,0xff,0xc3,0xc3,0xff,0xff,0xc3,0xc3};
u16 M_shape[] = {0xff,0xff,0xdb,0xdb,0xdb,0xdb,0xdb,0xdb};

/* Array of pointers to shapes */
u16 *shapes[5]={E_shape , S_shape , L_shape , A_shape , M_shape};

int main(void)
{
    /* Initialize system clock */
    MRCC_voidInitSystemClock();

    /* Enable GPIO ports */
    MRCC_voidEnableVendorPerphiral(AHB1, AHB1_GPIOAEN);
    MRCC_voidEnableVendorPerphiral(AHB1, AHB1_GPIOBEN);

    /* Initialize SysTick timer */
    MSTK_voidInit();

    /* Initialize LED matrix */
    HLedMatrix_voidInit();

    while(1)
    {
        /* Iterate through each shape and display it */
        for(u8 i=0 ; i<5 ; i++)
        {
            DisplayShiftingShape(shapes[i]);
        }

        /* Delay for 100000 microseconds (100 milliseconds) */
        MSTK_voidSetBusyWaitDelay(100000);
    }
}
