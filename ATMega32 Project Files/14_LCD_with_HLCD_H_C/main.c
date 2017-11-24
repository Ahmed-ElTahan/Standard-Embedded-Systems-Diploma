/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Program LCD component. 3 basic functions are used to start using LCD:
	1- LCD_vidwriteCommand: used to send "commands" to the LCD screen as choosing modes(4/8 pins), no. of lines, cursor show, cursor blink
	that happens by setting control pins/bits (RS, RW, EN) and Data pins/bits (D0 --> D7) to special set (0s and 1s) according to the data sheet
	Note: any command sent to the LCD will not work till an "enable pulse" is sent after it as:
			enable (high) --> hold for 2 ms --> enable (low)
	2- LCD_vidwriteData: used to send "data" to the LCD screen as numbers/chars/special chars. the char is sent as ASCCI (between 2 single quotes)
	3- LCD_vidInit(): used to initialize the LCD for working as the following:
		a- delay with minimum 30 ms to let the high voltage reach its value in the LCD
		b- set a bunch of settings as:
			- Function set (mode 4/8 pins, no. of lines, resolution)
			- Display on/off control (display on/off, cursor show, cursor blink)
			- Clear screen
	Then 6 applications are presented:
	(1) write a character (by default at the beginning of the 1st line)
	(2) Write my name on the 2nd line
	(3) Write my 1st name centered 1st line, 2nd name centered 2nd line
	(4) Character Animation
	(5) Animation 1st name 1st line
	(6) Zigzag of 1st name

	Notes:
	1- There is an auto increment in the LCD and by default when you start writing, it begins at the left upper place
	in the 1st line. Write char, then another they will be place next to each other at the beginning of the left upper
	place of 1st line of the LCD.
	2- To start at the left upper 1st line --> LCD_vidwriteCommand(0b1100000);
	   TO start at the left lower 2nd line --> LCD_vidwriteCommand(0b1100000);
	   add ( + i  ) to the binary when wanted to move to ith place in the specified line.
	   ex. 4th place (starting from 0) at the 2nd line -->  LCD_writeCommand(0b1100000 + 4);
	3- To clear screen --> LCD_vidwriteCommand(0b00000001);
	4- delay 2 ms after setting the function set, display control (according to the data sheet)
	5- In any write or read command --> RS is 1, other commands its 0
	6- Put LCD_vidInit() in the main before the while loop

	RS: register select
	RW: Read/Write
	EN: Enable
*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HLCD.h" // This header file includes the set of pins selected to connect LCD with MCU and 3 function prototypes above that used to control and display commands and data on LCD screen, repectively

// User-defined  #define (Macros: Object / Function)
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
	int i; // counter
		// Program Variables
		// Pin Direction (Input/Output)
		// Pin Values (initialization)

	LCD_vidInit(); // Initialize the LCD
		/*
		// (1) write a character (by default at the beginning of the 1st line)
		//LCD_writeData('A');
		*/
		/*
		// (2) Write my name on the 2nd line
		LCD_vidwriteCommand(0b11000000); // go to the beginning of the 2nd line
		LCD_vidwriteCommand(0b11000000 + 2); // go to the beginning of the 2nd line at the 2nd place
		LCD_vidwriteData('A');
		LCD_vidwriteData('H');
		LCD_vidwriteData('M');
		LCD_vidwriteData('E');
		LCD_vidwriteData('D');
		LCD_vidwriteData(' ');
		LCD_vidwriteData('E');
		LCD_vidwriteData('L');
		LCD_vidwriteData('T');
		LCD_vidwriteData('A');
		LCD_vidwriteData('H');
		LCD_vidwriteData('A');
		LCD_vidwriteData('N');
	*/

	/*
		// (3) Write my 1st name centered 1st line, 2nd name centered 2nd line
		LCD_writeCommand(0b10000000 + 5); // go to the beginning of the 1st line at the 2nd place
		LCD_writeData('A');
		LCD_writeData('H');
		LCD_writeData('M');
		LCD_writeData('E');
		LCD_writeData('D');

		LCD_writeCommand(0b11000000 + 4); // go to the beginning of the 2nd line at the 2nd place
		LCD_writeData('E');
		LCD_writeData('L');
		LCD_writeData('T');
		LCD_writeData('A');
		LCD_writeData('H');
		LCD_writeData('A');
		LCD_writeData('N');
	*/


	/*
	// Writing Decimal Value to the LCD
	LCD_vidWriteDecimal(5);
	 */


	while(1)
	{
		// Write your instructions here.
	/*
		// (4) Character Animation
			LCD_vidwriteData('A');
			_delay_ms(delay_ms);
			LCD_vidwriteCommand(0b00000001); // clear the screen
			LCD_vidwriteCommand(0b10000000 + 1); // go to the beginning of the 1st line at the 1st place
			LCD_vidwriteData('A');
			_delay_ms(delay_ms);
			LCD_vidwriteCommand(0b00000001); // clear the screen
			LCD_vidwriteCommand(0b10000000); // go to the beginning of the 1st line
		 */

		/*
		// (5) Animation 1st name 1st line
			LCD_vidwriteCommand(0b10000000); // go to the beginning of the 1st line
			for (i = 0; i<=15-4; i++)
			{
				LCD_vidwriteCommand(0b10000000 + i); // go to the beginning of the 1st line at the ith place
				LCD_vidwriteData('A'); LCD_vidwriteData('H'); LCD_vidwriteData('M'); LCD_vidwriteData('E'); LCD_vidwriteData('D');
				_delay_ms(delay_ms);
				LCD_vidwriteCommand(0b00000001); // clear the screen
			}
			for (i = 15-4; i>=0; i--)
			{
				LCD_vidwriteCommand(0b10000000 + i); // go to the beginning of the 1st line at the ith place
				LCD_vidwriteData('A'); LCD_vidwriteData('H'); LCD_vidwriteData('M'); LCD_vidwriteData('E'); LCD_vidwriteData('D');
				_delay_ms(delay_ms);
				LCD_vidwriteCommand(0b00000001); // clear the screen
			}
		*/

/*
		// (6) Zigzag of 1st name
		LCD_vidwriteCommand(0b10000000); // go to the beginning of the 1st line

		LCD_vidwriteCommand(0b10000000); // go to the beginning of the 1st line
		LCD_vidwriteData('A'); LCD_vidwriteData('H'); LCD_vidwriteData('M'); LCD_vidwriteData('E'); LCD_vidwriteData('D');
		_delay_ms(delay_ms);
		LCD_vidwriteCommand(0b00000001); // clear the screen

		LCD_vidwriteCommand(0b11000000 + 5); // go to the beginning of the 1st line at the 5th place
		LCD_vidwriteData('A'); LCD_vidwriteData('H'); LCD_vidwriteData('M'); LCD_vidwriteData('E'); LCD_vidwriteData('D');
		_delay_ms(delay_ms);
		LCD_vidwriteCommand(0b00000001); // clear the screen

		LCD_vidwriteCommand(0b10000000 + 10); // go to the beginning of the 2nd line at the 10th place
		LCD_vidwriteData('A'); LCD_vidwriteData('H'); LCD_vidwriteData('M'); LCD_vidwriteData('E'); LCD_vidwriteData('D');
		_delay_ms(delay_ms);
		LCD_vidwriteCommand(0b00000001); // clear the screen

		LCD_vidwriteCommand(0b11000000 + 5); // go to the beginning of the 1st line at the 5th place
		LCD_vidwriteData('A'); LCD_vidwriteData('H'); LCD_vidwriteData('M'); LCD_vidwriteData('E'); LCD_vidwriteData('D');
		_delay_ms(delay_ms);
		LCD_vidwriteCommand(0b00000001); // clear the screen

		LCD_vidwriteCommand(0b10000000); // go to the beginning of the 1st line
		LCD_vidwriteData('A'); LCD_vidwriteData('H'); LCD_vidwriteData('M'); LCD_vidwriteData('E'); LCD_vidwriteData('D');
		_delay_ms(delay_ms);
		LCD_vidwriteCommand(0b00000001); // clear the screen
*/




	}

	// Don't Add anything here (will not be executed)
}
