/*
 * main.c
 *
 *  Created on: Aug 25, 2017
 *      Author: Ahmed A. Eltahan
 */


/*
	----------------------------- Program Description -----------------------------------------
	Programing Project by USBasp kit using AVR Dude to:
	blink led on pin C0
*/

// Libraries
#include<avr/io.h> // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
// User-defined header files #define (Macros: Object / Function
#define delay_ms 1000 // milliseconds
// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)
	DDRC = 0b00000001; // configure C0 as output
	PORTC = 0b00000000; // output zero on Port C
	while(1)
	{
		// Write your instructions here.
		PORTC = 0b00000001; // output 1 on pin C0
		_delay_ms(delay_ms); // pause for delay_ms.
		PORTC = delay_ms; // output 0 on pin C0
		_delay_ms(delay_ms); // pause for delay_ms.
	}

	// Don't Add anything here (will not be executed)
}
