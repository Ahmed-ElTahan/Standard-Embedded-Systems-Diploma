/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Run a servo motor using delay function. The signal input to the servo is as:

	 ______
	|      |
	|      |_________________

    | T_on |

    |          20 ms         |

    T_on = 1 ms - 2 ms : -90 - 90 degree


*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

#define ServoMotor_Pin PIN0    // servo motor signal input pin (orange pin)
#define ServoMotorEN_Pin PIN1  // servo motor enable pin (NPN 2N2222 transistro switching)

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)
	SetPinDirection(ServoMotor_Pin, OUTPUT);
	SetPinDirection(ServoMotorEN_Pin, OUTPUT);

	SetPinValue(ServoMotorEN_Pin, HIGH); // enable servo motor
		// Program Variables

	u16 T_on = 1200; // between 1000 (-90 deg) 1500 ( 0 deg) 2000 ( 90 deg)
	u16 T_off = 20000 - T_on;

		// Pin Direction (Input/Output)
		// Pin Values (initialization)
		// Module Initialization


	while(1)
	{
		// Write your instructions here.

		// Send T_on on High level defined above then send (20000 - T_on = T_off) on Low level
		SetPinValue(ServoMotor_Pin, HIGH);
		_delay_us(T_on);

		SetPinValue(ServoMotor_Pin, LOW);
		_delay_us(T_off);

	}

	// Don't Add anything here (will not be executed)
}
