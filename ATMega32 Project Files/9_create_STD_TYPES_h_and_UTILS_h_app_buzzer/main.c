/*
 * main.c
 *
 *  Created on: Aug 26, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	define our defined data types in STD_TYPES.h and set/clear/toggle/get bit in UTILS.h
	use these header files to output on a buzzer (application)
*/

// Libraries
#include<avr/io.h> // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"STD_TYPES.h" // To include user defined data types
#include"UTILS.h" // To include set/toggle/clear/get bit macros

// User-defined header files #define (Macros: Object / Function)
#define delay_ms 500 // delay duration

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)

	SET_BIT(DDRD, 0); // D0 is output == DDRD = 0b00000001 (but using macro, will save the other pin modes output/input. only set desired pin)
	CLR_BIT(PORTD, 0); // make D0 low at the beginning

	// Buzzer Signal
	SET_BIT(PORTD, 0); // high on D0
	_delay_ms(delay_ms); // pause with delay_ms
	CLR_BIT(PORTD, 0); // low on D0
	_delay_ms(delay_ms); // pause with delay_ms
	SET_BIT(PORTD, 0); // high on D0
	_delay_ms(delay_ms); // pause with delay_ms
	CLR_BIT(PORTD, 0); // low on D0
	_delay_ms(delay_ms); // pause with delay_ms

	// can be also done by TOG_BIT
	TOG_BIT(PORTD, 0); // high on D0 as it was low
	_delay_ms(delay_ms); // pause with delay_ms
	TOG_BIT(PORTD, 0); // low on D0
	_delay_ms(delay_ms); // pause with delay_ms
	TOG_BIT(PORTD, 0); // high on D0
	_delay_ms(delay_ms); // pause with delay_ms
	CLR_BIT(PORTD, 0); // low on D0

	while(1)
	{
		// Write your instructions here.


	}

	// Don't Add anything here (will not be executed)
}
