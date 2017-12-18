/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	use keypad buttons to enter 2 numbers (0-9), do the sum, and print them on LCD screen

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
LCD_vidWriteDecimal(int x);

// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)

		// Program Variables
		u8 key; // to get the value got from key pad
		int i = 0; // counter
		int sum = 0; // summation

		// Pin Direction (Input/Output)
		// Pin Values (initialization)

		// Module Initialization
		LCD_vidInit(); // Initialize LCD
		KPD_vidInit(); // Initialize Keypad used to set the keypad connected pins as inputs and pulled up and outputs





	while(1)
	{
		// Write your instructions here.

		for (i = 0; i <=2; i++)
		{
			key = KPD_u8GetPressedKey(); // return the key pressed
			// switch on the value got from keypad to print it on the LCD screen (can do anything else)
			switch(key)
			{
				case 1:
				LCD_vidwriteData('1');
				break;

				case 2:
				LCD_vidwriteData('2');
				break;

				case 3:
				LCD_vidwriteData('3');
				break;

				case 4:
				LCD_vidwriteData('4');
				break;

				case 5:
				LCD_vidwriteData('5');
				break;

				case 6:
				LCD_vidwriteData('6');
				break;

				case 7:
				LCD_vidwriteData('7');
				break;

				case 8:
				LCD_vidwriteData('8');
				break;

				case 9:
				LCD_vidwriteData('9');
				break;

				case 10:
				LCD_vidwriteData('1');
				LCD_vidwriteData('0');
				break;

				case 11:
				LCD_vidwriteData('1');
				LCD_vidwriteData('1');
				break;

				case 12:
				LCD_vidwriteData('1');
				LCD_vidwriteData('2');
				break;

				case 13:
				LCD_vidwriteData('1');
				LCD_vidwriteData('3');
				break;

				case 14:
				LCD_vidwriteData('1');
				LCD_vidwriteData('4');
				break;

				case 15:
				LCD_vidwriteData('1');
				LCD_vidwriteData('5');
				break;

				case 16:
				LCD_vidwriteData('1');
				LCD_vidwriteData('6');
				break;

			}

			sum = sum + key;
		}

	// Don't Add anything here (will not be executed)
}
}


