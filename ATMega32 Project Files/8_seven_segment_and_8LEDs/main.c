/*
 * main.c
 *
 *  Created on: Aug 25, 2017
 *      Author: Ahmed A. Eltahan
 */


/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	write a program that deals counts down from 9 to 0 on seven segment and at each step light up 8 LEDs in a nice behaviour.
	After Mapping a working common anode 7-segment (0 to light, 1 to dark),
	then, create array sevseg[] of 11 elements to store these decimal values and index corresponds to the number as:

	number 			binary				decimal			sevseg[]
	0				10100000			160				sevseg[0]
	1				11111001			249				sevseg[1]
	2				11000100			196				sevseg[2]
	3				11010000			208				sevseg[3]
	4				10010010			153				sevseg[4]
	5				10010010			146				sevseg[5]
	6				10000010			130				sevseg[6]
	7				11111000			248				sevseg[7]
	8				10000000			128				sevseg[8]
	9				10010000			144				sevseg[9]
	dot				01111111			127				sevseg[10]


*/
// Libraries
#include<avr/io.h> // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
// User-defined header files #define (Macros: Object / Function)
# define delay_ms 250 // delay in milliseconds

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)
	int sevseg[] = {160, 249, 196, 208, 153, 146, 130, 248, 128, 144}; // seven segment array to store decimal values corresponding to numbers 0 to 9
	int noe = sizeof(sevseg)/sizeof(sevseg[0]); // number of elements
	int i; // counter


	DDRD = 0b11111111; // Define Port D as output for the seven segment
	DDRC = 0b11111111; // Define Port C as output for the 8 LEDs
	DDRA = 0b00000001; // define A0 as output
	PORTA = 0b00000001; // high on A0 for the seven segment anode (Don't connect 7 segment directly to 5v)

	while(1)
	{
		// Write your instructions here.

		for (i = (noe - 1); i >= 0; i--)
		{
			// write number
			PORTD = sevseg[i]; // print numbers from 9 to 0

			// light up the lights
				// blink led 1 C0 and led 8 C7
				PORTC = 0b10000001; // output 1 on pin C0 and C7
				_delay_ms(delay_ms); // pause for delay_ms
				PORTC = 0b00000000; // output 0 on pin C0 and C7
				_delay_ms(delay_ms); // pause for delay_ms


				// blink led 2 C1 and led 7 C6
				PORTC = 0b01000010; // output 1 on pin C1 and C6
				_delay_ms(delay_ms); // pause for delay_ms
				PORTC = 0b00000000; // output 0 on pin C1 and C6
				_delay_ms(delay_ms); // pause for delay_ms

				// blink led 3 C2 and led 6 C5
				PORTC = 0b00100100; // output 1 on pin C2 and C5
				_delay_ms(delay_ms); // pause for delay_ms
				PORTC = 0b00000000; // output 0 on pin C2 and C5
				_delay_ms(delay_ms); // pause for delay_ms

				// blink led 4 C3 and led 5 C4
				PORTC = 0b00011000; // output 1 on pin C3 and C4
				_delay_ms(delay_ms); // pause for delay_ms
				PORTC = 0b00000000; // output 0 on pin C3 and C4
				_delay_ms(delay_ms); // pause for delay_ms

				// blink led 3 C2 and led 6 C5
				 PORTC = 0b00100100; // output 1 on pin C2 and C5
				_delay_ms(delay_ms); // pause for delay_ms
				PORTC = 0b00000000; // output 0 on pin C2 and C5
				_delay_ms(delay_ms); // pause for delay_ms

				// blink led 2 C1 and led 7 C6
				PORTC = 0b01000010; // output 1 on pin C1 and C6
				_delay_ms(delay_ms); // pause for delay_ms
				PORTC = 0b00000000; // output 0 on pin C1 and C6
				_delay_ms(delay_ms); // pause for delay_ms
		}

	}

	// Don't Add anything here (will not be executed)
}
