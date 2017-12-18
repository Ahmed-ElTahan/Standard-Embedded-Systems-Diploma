/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HLCD.h" // This header file includes the set of pins selected to connect LCD with MCU and 3 function prototypes above that used to control and display commands and data on LCD screen, repectively
#include"HKPD.h" // This header file includes selection of keypad pins and define functions to deal with keypad (initialization, get pressed key)

// User-defined #define (Macros: Object / Function)
#define delay_ms 3000 // delay duration milliseconds

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)
		// Program Variables
		// Pin Direction (Input/Output)
		SetPinDirection(16, OUTPUT);
		SetPinDirection(17, OUTPUT);
		// Pin Values (initialization)
		SetPinValue(16, LOW);
		SetPinValue(17, LOW);
		// Module Initialization


	while(1)
	{
		// Write your instructions here.
		SetPinValue(16, LOW);
		SetPinValue(17, HIGH);
		_delay_ms(delay_ms);

		SetPinValue(16, LOW);
		SetPinValue(17, LOW);
		_delay_ms(delay_ms);

		SetPinValue(16, HIGH);
		SetPinValue(17, LOW);
		_delay_ms(delay_ms);

		SetPinValue(16, LOW);
		SetPinValue(17, LOW);
		_delay_ms(delay_ms);

	}

	// Don't Add anything here (will not be executed)
}
