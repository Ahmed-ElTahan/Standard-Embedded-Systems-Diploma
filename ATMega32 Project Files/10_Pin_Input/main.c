/*
 * main.c
 *
 *  Created on: Aug 26, 2017
 *      Author: Ahmed A. Eltahan
 */


/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	input a switch to control 3 leds' states
*/

// Libraries
#include<avr/io.h> // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"STD_TYPES.h" // To include user defined data types
#include"UTILS.h" // To include set/toggle/clear/get bit macros

// User-defined header files #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)
	CLR_BIT(DDRD, 0); // let D0 as input (switch)
	SET_BIT(DDRD, 1); // let D1 as output (LED 1);
	SET_BIT(DDRD, 2); // let D2 as output (LED 2);
	SET_BIT(DDRD, 3); // let D3 as output (LED 3);

	while(1)
	{
		// Write your instructions here.
		if (GET_BIT(PIND, 0) == 0) // switch is pressed
		{
			// LEDs 1 2 3 are on
			SET_BIT(PORTD, 1);
			SET_BIT(PORTD, 2);
			SET_BIT(PORTD, 3);
		}
		else // switch is released
		{
			// LEDs 1 2 3 are off
			CLR_BIT(PORTD, 1);
			CLR_BIT(PORTD, 2);
			CLR_BIT(PORTD, 3);
		}

	}

	// Don't Add anything here (will not be executed)
}
