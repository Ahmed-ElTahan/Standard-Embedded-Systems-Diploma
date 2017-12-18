/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:

	It's required toggle a state of a LED connected with C1 pin by a push buttong connected as a pull up
	resistor connected with C0 as the following:
	Push and release --> state 1. Push and release again --> state 2.
	State 1/2 : On 	State 2/1 : Off
*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

#define ON 1
#define OFF 0

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
		// Declaration and Initialization (executed once)
		SetPinDirection(PIN16, INPUT_PU); // pin C0 input pull up resistor
		SetPinDirection(PIN17, OUTPUT);   // pin C1 LED output

		u8 input = 0;
		u8 led_state= OFF; // initially

		// Program Variables
		// Pin Direction (Input/Output)
		// Pin Values (initialization)
		// Module Initialization


	while(1)
	{
		// Write your instructions here.
		input = GetPinValue(PIN16); // get the value of the push button
		while(input == 1); // stay here as the button is not pressed. if pressed, move to the next while
		while(input == 0); // wait here as the button is pressed.
		TOG_BIT(led_state, 0); // now change the state of the LED
		SetPinValue(PIN17, led_state); // output the changed value on the LED
		// Note: after we release the push button, the state of the LED is changed.

	}

	// Don't Add anything here (will not be executed)
}
