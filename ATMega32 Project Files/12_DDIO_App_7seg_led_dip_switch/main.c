/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Use Created DDIO.h .c to test it by using it to run 7segment, 8 leds using a crrect password wirtten on 4 dip switch
*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HSeven_Segment_DDIO.h" // This Header file includes the function prototype of SevSeg_ShowNumber(int i) function and selection of SPN and EN_PIN
#include"SCompareArrays.h"// This header file contains the function prototype of SCompareArrays(int Arr1[ ], int Arr2[ ], int Arr_Size) function

// User-defined #define (Macros: Object / Function)
#define delay_ms 50 // delay duration milliseconds
#define pass_size 4 // password size
#define pass 1,0,1,0 // password selected

// User Data Type definition
// Function prototype
void off_leds(void);

// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)
		// Program Variables
		int i; // counter
		int noe = 11; // number of elements

		// Pin Direction (Input/Output)
		for ( i = 16; i < 24; i++) // set pins of Port C (8-LEDs)
		{
			SetPinDirection(i, 1); // Direction output
			SetPinValue(i, 0); // zero output (ensure)
		}


		for (i = 0; i<pass_size; i++) // set pins from 0 to pin_size of port A as input (DIP switch)
		{
			SetPinDirection(i, 0); // Direction input
		}
		// Pin Values (initialization)
		int selected_pass[pass_size] = {pass}; // store defined password
		int entered_pass[pass_size]; // store entered password

	while(1)
	{
		// Write your instructions here.
		for (i = 0; i<pass_size; i++) // get pins' values from 0 to pin_size of port A (DIP switch) and store them in
		{
			entered_pass[i] = GetPinValue(i);
		}


		if (SCompareArrays(entered_pass, selected_pass, pass_size))
		{
			for (i = 0; i < noe; i++)
			{
				SevSeg_ShowNumber(i); // print numbers from 0 to 9 and dot

				SetPinValue(16, 1); SetPinValue(23, 1);
				_delay_ms(delay_ms); // pause for delay_ms
				SetPinValue(16, 0); SetPinValue(23, 0);

				SetPinValue(17, 1); SetPinValue(22, 1);
				_delay_ms(delay_ms); // pause for delay_ms
				SetPinValue(17, 0); SetPinValue(22, 0);

				SetPinValue(18, 1); SetPinValue(21, 1);
				_delay_ms(delay_ms); // pause for delay_ms
				SetPinValue(18, 0); SetPinValue(21, 0);

				SetPinValue(19, 1); SetPinValue(20, 1);
				_delay_ms(delay_ms); // pause for delay_ms
				SetPinValue(19, 0); SetPinValue(20, 0);

				SetPinValue(18, 1); SetPinValue(21, 1);
				_delay_ms(delay_ms); // pause for delay_ms
				SetPinValue(18, 0); SetPinValue(21, 0);

				SetPinValue(17, 1); SetPinValue(22, 1);
				_delay_ms(delay_ms); // pause for delay_ms
				SetPinValue(17, 0); SetPinValue(22, 0);

			}




		}

		else
		{
			off_leds();
			SetPinValue(16, 1); SetPinValue(23, 1);
			_delay_ms(delay_ms); // pause for delay_ms

		}

	}

	// Don't Add anything here (will not be executed)
}

void off_leds(void)
{
	//ShowNumber(0, 24);
	// all off (LEDs)
	int k;
	for ( k = 16; k < 24; k++)
	{
		SetPinValue(k, 0); // zero output (ensure)
	}
}
