/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	use a DIP switch (only one) as a counter of how many times the state of the button is recycled
	from 0 to 1 and back to 1 (starting from 0 till 255) and show the number of them on 8 LEDs as a
	binary representation

*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HLCD.h" // This header file includes the set of pins selected to connect LCD with MCU and 3 function prototypes above that used to control and display commands and data on LCD screen, repectively
#include"STD_TYPES.h" // To include user defined data types (u8, u16 ... f96)

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum


// function used to convert a decimal number to a binary number stored in an array
void dec_to_bin_array(int input[], int Inc)
{
	int i; // counter
	//mapping the decimal value of Inc to the array input[] -- input = Inc
	for (i = 0; i<=7; i++)
	{
		input[i] = GET_BIT(Inc, i);
	}
}

void main(void)
{
	// Declaration and Initialization (executed once)
	int i; //counter
	int Inc = 0; // increment
	int input[8] = {0,0,0,0,0,0,0,0}; // from the DIP switch
	u8 sw1 = 1; // switch for increment


	for (i = 0; i<=7; i++)
	{
		SetPinDirection(i, OUTPUT); // Set port A as output (8 LEDs)
		SetPinValue(i, LOW); // ensure zeros on LEDs
	}

	for (i = 16; i<=16; i++)
	{
		SetPinDirection(i, INPUT_PU); // Set pin number 16 as input (8 DIP switches) + Pull up resistors of port C
	}
		// Program Variables
		// Pin Direction (Input/Output)
		// Pin Values (initialization)


	while(1)
	{

		// Write your instructions here.



			// sw1 is used to enter the loop of incrementing once if the button is held at the high state in order to avoid (continuous incrementing)

		// Not Increment button
			if (GetPinValue(16) && (sw1 == 1)) // released button
			{
				dec_to_bin_array(input, Inc);
				// write the output on LEDs
				for (i = 0; i<=7; i++)
				{
					SetPinValue(i, input[i]);
					sw1 = 0; // to allow to get into the else if when the button is in low
				}
			}

			// Increment button
			else if((!GetPinValue(16)) && (sw1 == 0)) // pressed button and check only once (sw)
			{
				sw1 = 1; // to not enter this else if when the switch is in high state
				Inc = Inc + 1;
				dec_to_bin_array(input, Inc);
				// write the output on LEDs
				for (i = 0; i<=7; i++)
				{
				SetPinValue(i, input[i]);
				}
			}




	}

	// Don't Add anything here (will not be executed)
}
