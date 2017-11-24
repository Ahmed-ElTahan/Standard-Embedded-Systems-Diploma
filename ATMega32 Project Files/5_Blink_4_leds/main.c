/*
 * main.c
 *
 *  Created on: Aug 25, 2017
 *      Author: Ahmed A. Eltahan
 */


/*
	----------------------------- Program Description -----------------------------------------
	Programing Project by USBasp kit using AVR Dude to:
	blink 4 leds on pin C0, C1, C2, C3
*/

// Libraries
#include<avr/io.h> // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
// User-defined header files #define (Macros: Object / Function)
#define delay_ms 500 // milliseconds
// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)
	DDRC = 0b00001111; // configure C0, C1, C2, C3 as output
	PORTC = 0b00000000; // output zero on Port C
	while(1)
	{
		// Write your instructions here.

		// blink led 1 C0
		PORTC = 0b00000001; // output 1 on pin C0
		_delay_ms(delay_ms); // pause for delay_ms
		PORTC = 0b00000000; // output 0 on pin C0
		_delay_ms(delay_ms); // pause for delay_ms

		// blink led 2 C1
		PORTC = 0b00000010; // output 1 on pin C1
		_delay_ms(delay_ms); // pause for delay_ms
		PORTC = 0b00000000; // output 0 on pin C1
		_delay_ms(delay_ms); // pause for delay_ms

		// blink led 3 C2
		PORTC = 0b00000100; // output 1 on pin C2
		_delay_ms(delay_ms); // pause for delay_ms
		PORTC = 0b00000000; // output 0 on pin C2
		_delay_ms(delay_ms); // pause for delay_ms

		// blink led 4 C3
		PORTC = 0b00001000; // output 1 on pin C3
		_delay_ms(delay_ms); // pause for delay_ms
		PORTC = 0b00000000; // output 0 on pin C3
		_delay_ms(delay_ms); // pause for delay_ms

	}

	// Don't Add anything here (will not be executed)
}
