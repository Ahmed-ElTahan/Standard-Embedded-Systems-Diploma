/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Use DIP 8 pins switch and 8 LEDs so that each switch is related to a
	corresponding LED. when on --> LED light, off --> LED dark
*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HLCD.h" // This header file includes the set of pins selected to connect LCD with MCU and 3 function prototypes above that used to control and display commands and data on LCD screen, repectively

// User-defined #define (Macros: Object / Function)
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
	int i; //counter
	u8 input[8] = {0,0,0,0,0,0,0,0}; // from the DIP switch

	for (i = 0; i<=7; i++)
	{
		SetPinDirection(i, OUTPUT); // Set port A as output (8 LEDs)
		SetPinValue(i, LOW); // ensure zeros on LEDs
	}

	for (i = 16; i<=23; i++)
	{
		SetPinDirection(i, INPUT_PU); // Set port C as input (8 DIP switches) + Pull up resistors of port C
	}
		// Program Variables
		// Pin Direction (Input/Output)
		// Pin Values (initialization)


	while(1)
	{

		// Write your instructions here.

		for (i = 16; i<=23; i++) // get DIP switches' states
		{
			input[(i-16)] = GetPinValue(i);
		}

		for (i = 0; i<=7; i++) // write the value of each switch to a corresponding LED, not (!) is used as the switch is passive high
		{
			SetPinValue(i, !(input[i]));
		}

	}

	// Don't Add anything here (will not be executed)
}
