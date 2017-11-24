/*
 * HKPD.h
 *
 *  Created on: Sep 9, 2017
 *      Author: Ahmed A. Eltahan
 */

/* This header file is used to select pins used for
 * keypad (row inputs pulled up, columns outputs(column activation)) and define 2 functions

	1- void KPD_vidInit(void); // used to set the keypad connected pins as inputs pulled up (Rows) and outputs (columns)
	2- u8 KPD_u8GetPressedKey(void); // used to activate/deactivate columns, search for pressed column switches continuously, and get the value pressed of the keypad

*/
/************** KeyPad Key Index ***************/
/*         Col_0    Col_1   Col_2   Col_3     */
/*	                                          */
/* row_0      1        2       3       4      */
/*	                                          */
/* row_1  	  5        6       7       8      */
/*	                                          */
/* row_2	  9        10      11      12     */
/*	                                          */
/* row_3	  13       14      15      16     */
/**********************************************/
//In IMT KIT the pins are
//row_3	row_2	row_1	row_0	col_0	col_1	col_2	col_3

#ifndef HKPD_H_
#define HKPD_H_


#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// Define Pins of Columns: 1st pin, and then orderly connect 3 after it, ex. start pin 16 --> rest 17, 18, 19
#define COL_FIRST_PIN 	PIN0 // A0
#define COL_NUMBER 		4  // Number of columns

// Define Pins of Rows: 1st pin, and then orderly connect 3 after it, ex. start pin 20 --> rest 21, 22, 23
#define ROW_FIRST_PIN 	PIN4 // A4
#define ROW_NUMBER 		4  // Number of rows


// Function Prototypes
void KPD_vidInit(void); // used to set the keypad connected pins as inputs pulled up (Rows) and outputs (columns)
u8 KPD_u8GetPressedKey(void); // used to activate/deactivate columns, search for pressed column switches continuously, and get the value pressed of the keypad

#endif /* HKPD_H_ */
