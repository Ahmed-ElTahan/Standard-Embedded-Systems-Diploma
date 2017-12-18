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

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

#define TWAR  *(volatile u8*)  (0x22)
#define TWBR  *(volatile u8*)  (0x20)
#define TWCR  *(volatile u8*)  (0x56)
#define TWDR  *(volatile u8*)  (0x23)
#define TWSR  *(volatile u8*)  (0x21)


#define Button1_Pin PIN2      // Push button 1 A2
#define Button2_Pin PIN3      // Push button 2 A3

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
u8 value = 10;
// Enum



void main(void)
{
	// Declaration and Initialization (executed once)
		// Program Variables
	u8 Button1 = 1; // initial default value pull up resistor
	u8 Button2 = 1; // initial default value pull up resistor

		// Pin Direction (Input/Output)
		DDRD = 0xFF; // LEDs
		SetPinDirection(Button1_Pin, INPUT_PU); // Input pull up resistor A2
		SetPinDirection(Button2_Pin, INPUT_PU); // Input pull up resistor A3

		// Pin Values (initialization)
		// Module Initialization
		SET_BIT(TWCR, 2); // enable I2C



		// After Send


	while(1)
	{
		// Write your instructions here.

		/* -------------------------------------------------------------- */

		SET_BIT(TWCR, 5); // start bit ok
		SET_BIT(TWCR, 7); // clear flag to start operation
		while(GET_BIT(TWCR, 7) == 0); // wait till flag is set (operation is done)


		// flag is set by hw after start bit

		// output on led (00001000)
		PORTD = TWSR;
		_delay_ms(1000);

		// Sending SLA+W
		CLR_BIT(TWCR, 5); // no start condition
		TWDR = 0b00000010; //0b 0000 001 0
		SET_BIT(TWCR, 7); // clear flag to start operation
		while(GET_BIT(TWCR, 7) == 0); // wait till flag is set (operation is done)
		// flag out with 1

		// output on led (0x20, 0x38, 0x18)
		PORTD = TWSR;
		_delay_ms(1000);

		// Increment
		if (GetPinValue(PIN2) == LOW)
		{
			//_delay_ms(250); // for debouncing
			value += 1;
			if(value>40) {value = 40;}
		}

		// Decrement
		if (GetPinValue(PIN3) == LOW)
		{
			//_delay_ms(250); // for debouncing
			value -= 1;
			if(value<1) {value = 1;}
		}

		// send data packet
		TWDR = value;

		// output on led (0x20, 0x38, 0x18)
		PORTD = TWSR;
		_delay_ms(1000);

		SET_BIT(TWCR, 5); // send stop bit
		SET_BIT(TWCR, 7); // clear flag to start operation
		while(GET_BIT(TWCR, 7) == 0); // wait till flag is set (operation is done)
		// flag out with 1


		/* -------------------------------------------------------------- */

		SET_BIT(TWCR, 5); // start bit ok
		SET_BIT(TWCR, 7); // clear flag to start operation
		while(GET_BIT(TWCR, 7) == 0); // wait till flag is set (operation is done)


		// flag is set by hw after start bit

		// output on led (00001000)
		PORTD = TWSR;
		_delay_ms(1000);

		// Sending SLA+W
		CLR_BIT(TWCR, 5); // no start condition
		TWDR = 0b00000100; //0b 0000 010 0
		SET_BIT(TWCR, 7); // clear flag to start operation
		while(GET_BIT(TWCR, 7) == 0); // wait till flag is set (operation is done)
		// flag out with 1


		// Increment
		if (GetPinValue(PIN2) == LOW)
		{
			//_delay_ms(250); // for debouncing
			value += 1;
			if(value>40) {value = 40;}
		}

		// Decrement
		if (GetPinValue(PIN3) == LOW)
		{
			//_delay_ms(250); // for debouncing
			value -= 1;
			if(value<1) {value = 1;}
		}

		// send data packet
		TWDR = value;

		// output on led (0x20, 0x38, 0x18)
		PORTD = TWSR;
		_delay_ms(1000);

		SET_BIT(TWCR, 5); // send stop bit
		SET_BIT(TWCR, 7); // clear flag to start operation
		while(GET_BIT(TWCR, 7) == 0); // wait till flag is set (operation is done)
		// flag out with 1

		/* -------------------------------------------------------------- */

	}

	// Don't Add anything here (will not be executed)
}



