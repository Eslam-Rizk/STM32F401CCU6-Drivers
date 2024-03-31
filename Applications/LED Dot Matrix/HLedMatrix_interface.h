/*
 * HLedMatrix_interface.h
 *
 *  Created on: Jan 18, 2024
 *      Author: Eslam Rizk
 */

#ifndef HLEDMATRIX_INTERFACE_H_
#define HLEDMATRIX_INTERFACE_H_

/* Function: HLedMatrix_voidInit
 * Description: Initialize the LED matrix module.
 */
void HLedMatrix_voidInit(void);

/* Function: HDisplayRowData
 * Description: Display a single row of data on the LED matrix.
 * Parameters:
 *   - Copy_u8ROWData: The data to be displayed on the row.
 */
void HDisplayRowData(u8 Copy_u8ROWData);

/* Function: DisplayShape
 * Description: Display a custom shape on the LED matrix.
 * Parameters:
 *   - cpy_shape: Pointer to an array containing the shape data.
 */
void DisplayShape(u8 *cpy_shape);

/* Function: DisplayShiftingShape
 * Description: Display a shifting shape on the LED matrix.
 * Parameters:
 *   - cpy_shape: Pointer to an array containing the shape data.
 */
void DisplayShiftingShape(u16 *cpy_shape);

/* Function: ShiftThenDisplayShape
 * Description: Shift the shape data and then display it on the LED matrix.
 * Parameters:
 *   - cpy_shape: Pointer to an array containing the shape data.
 */
void ShiftThenDisplayShape(u16 *cpy_shape);

#endif /* HLEDMATRIX_INTERFACE_H_ */
