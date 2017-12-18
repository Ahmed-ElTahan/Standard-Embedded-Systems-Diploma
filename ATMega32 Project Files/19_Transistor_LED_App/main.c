/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Introduce switching concept on MCU. This code defines three a pin for:
	NPN : 2N2222 transistor connected on pin number 24 as output that is connected to LED
	PNP : BC566  transistor connected on pin number 25 as output that is connected to LED
	Optocoupler : 4N25 connected on pin number 2 as output that is connected to LED

	use each pin in its active state by writing appropriate signal on it to open its gate and light up the LED

*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HLCD.h" // This header file includes the set of pins selected to connect LCD with MCU and 3 function prototypes above that used to control and display commands and data on LCD screen, repectively
#include"HKPD.h" // This header file includes selection of keypad pins and define functions to deal with keypad (initialization, get pressed key)

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
		// Program Variables
		// Pin Direction (Input/Output)
		SetPinDirection(24, OUTPUT); // NPN
		SetPinDirection(25, OUTPUT); // PNP
		SetPinDirection(27, OUTPUT); // OptoCoupler

		// Pin Values (initialization with closed gage)
		SetPinValue(24, LOW); // OFF NPN
		SetPinValue(25, HIGH); // OFF PNP
		SetPinValue(27, LOW); // OFF OptoCoupler
		// Module Initialization


	while(1)
	{
		// Write your instructions here.
		// Write appropriate values to open their gate
		SetPinValue(24, HIGH); // ON NPN (active high)
		SetPinValue(25, LOW); // ON PNP (active low)
		SetPinValue(27, HIGH); // ON OptoCoupler (active high)

	}

	// Don't Add anything here (will not be executed)
}
