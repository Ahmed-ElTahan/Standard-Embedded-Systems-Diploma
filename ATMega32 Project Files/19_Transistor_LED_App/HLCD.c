/*
 * HLCD.c
 *
 *  Created on: Sep 8, 2017
 *      Author: Ahmed A. Eltahan
 */
/*
 This .c file is used to write 3 basic functions are used to start using LCD:
	1- LCD_vidwriteCommand: used to send "commands" to the LCD screen as choosing modes(4/8 pins), no. of lines, cursor show, cursor blink
	that happens by setting control pins/bits (RS, RW, EN) and Data pins/bits (D0 --> D7) to special set (0s and 1s) according to the data sheet
	Note: any command sent to the LCD will not work till an "enable pulse" is sent after it as:
			enable (high) --> hold for 2 ms --> enable (low)
	Fist declare used pins as I/O then set their values

	2- LCD_vidwriteData: used to send "data" to the LCD screen as numbers/chars/special chars. the char is sent as ASCCI (between 2 single quotes)
	Fist declare used pins as I/O then set their values

	3- LCD_vidInit(): used to initialize the LCD for working as the following:
		a- delay with minimum 30 ms to let the high voltage reach its value in the LCD
		b- set a bunch of settings as:
			- Function set (mode 4/8 pins, no. of lines, resolution)
			- Display on/off control (display on/off, cursor show, cursor blink)
			- Clear screen
	Fist declare used pins as I/O then set their values

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

 */
#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

#include"HLCD.h" // This header file includes the set of pins selected to connect LCD with MCU and 3 function prototypes above that used to control and display commands and data on LCD screen, repectively


void LCD_vidwriteCommand(u8 command)
{
	//RS=0
	SetPinDirection(LCD_RS, OUTPUT);
	SetPinValue(LCD_RS, LOW);

	//RW=0
	SetPinDirection(LCD_RW, OUTPUT);
	SetPinValue(LCD_RW, LOW);

	//command: writing command to the pins defined and connected to the data pins to send commands to the LCD
	SetPinDirection(LCD_D0, OUTPUT); // declare D0 as output
	SetPinValue(LCD_D0, GET_BIT(command, 0)); // get the value of the 1st bit of "command" var. and put it at D0 which is the 1st bit/pin of the data pins/bits

	SetPinDirection(LCD_D1, OUTPUT); // declare D1 as output
	SetPinValue(LCD_D1, GET_BIT(command, 1)); // get the value of the 1st bit of "command" var. and put it at D1 which is the 2nd bit/pin of the data pins/bits

	SetPinDirection(LCD_D2, OUTPUT); // declare D2 as output
	SetPinValue(LCD_D2, GET_BIT(command, 2)); // get the value of the 1st bit of "command" var. and put it at D2 which is the 3rd bit/pin of the data pins/bits

	SetPinDirection(LCD_D3, OUTPUT); // declare D3 as output
	SetPinValue(LCD_D3, GET_BIT(command, 3)); // get the value of the 1st bit of "command" var. and put it at D3 which is the 4th bit/pin of the data pins/bits

	SetPinDirection(LCD_D4, OUTPUT); // declare D4 as output
	SetPinValue(LCD_D4, GET_BIT(command, 4)); // get the value of the 1st bit of "command" var. and put it at D4 which is the 5th bit/pin of the data pins/bits

	SetPinDirection(LCD_D5, OUTPUT); // declare D5 as output
	SetPinValue(LCD_D5, GET_BIT(command, 5)); // get the value of the 1st bit of "command" var. and put it at D5 which is the 6th bit/pin of the data pins/bits

	SetPinDirection(LCD_D6, OUTPUT); // declare D6 as output
	SetPinValue(LCD_D6, GET_BIT(command, 6)); // get the value of the 1st bit of "command" var. and put it at D6 which is the 7th bit/pin of the data pins/bits

	SetPinDirection(LCD_D7, OUTPUT); // declare D7 as output
	SetPinValue(LCD_D7, GET_BIT(command, 7)); // get the value of the 1st bit of "command" var. and put it at D7 which is the 8th bit/pin of the data pins/bits

	// Enable Pulse
		//Enable high
		SetPinDirection(LCD_EN, OUTPUT);
		SetPinValue(LCD_EN,HIGH);
		//delay 2ms
		_delay_ms(2);
		//Enable low
		SetPinValue(LCD_EN,LOW);
}

void LCD_vidwriteData(u8 data)
{
	//RS=1
	SetPinDirection(LCD_RS,OUTPUT);
	SetPinValue(LCD_RS,HIGH);

	//RW=0
	SetPinDirection(LCD_RW,OUTPUT);
	SetPinValue(LCD_RW,LOW);

	//data
	SetPinDirection(LCD_D0, OUTPUT); // declare D0 as output
	SetPinValue(LCD_D0,GET_BIT(data,0)); // get the value of the 1st bit of "data" var. and put it at D0 which is the 1st bit/pin of the data pins/bits

	SetPinDirection(LCD_D1, OUTPUT); // declare D1 as output
	SetPinValue(LCD_D1,GET_BIT(data,1)); // get the value of the 1st bit of "data" var. and put it at D1 which is the 2nd bit/pin of the data pins/bits

	SetPinDirection(LCD_D2, OUTPUT); // declare D2 as output
	SetPinValue(LCD_D2,GET_BIT(data,2)); // get the value of the 1st bit of "data" var. and put it at D2 which is the 3rd bit/pin of the data pins/bits

	SetPinDirection(LCD_D3, OUTPUT); // declare D3 as output
	SetPinValue(LCD_D3,GET_BIT(data,3)); // get the value of the 1st bit of "data" var. and put it at D3 which is the 4th bit/pin of the data pins/bits

	SetPinDirection(LCD_D4, OUTPUT); // declare D4 as output
	SetPinValue(LCD_D4,GET_BIT(data,4)); // get the value of the 1st bit of "data" var. and put it at D4 which is the 5th bit/pin of the data pins/bits

	SetPinDirection(LCD_D5, OUTPUT); // declare D5 as output
	SetPinValue(LCD_D5,GET_BIT(data,5)); // get the value of the 1st bit of "data" var. and put it at D5 which is the 6th bit/pin of the data pins/bits

	SetPinDirection(LCD_D6, OUTPUT); // declare D6 as output
	SetPinValue(LCD_D6,GET_BIT(data,6)); // get the value of the 1st bit of "data" var. and put it at D6 which is the 7th bit/pin of the data pins/bits

	SetPinDirection(LCD_D7, OUTPUT); // declare D7 as output
	SetPinValue(LCD_D7,GET_BIT(data,7)); // get the value of the 1st bit of "data" var. and put it at D7 which is the 8th bit/pin of the data pins/bits


	// Enable Pulse
		//Enable high
		SetPinDirection(LCD_EN, OUTPUT);
		SetPinValue(LCD_EN,HIGH);
		//delay 2ms
		_delay_ms(2);
		//Enable low
		SetPinValue(LCD_EN,LOW);
}

void LCD_vidInit(void)
{
	//Delay for voltage stability
	_delay_ms(50);

	//Function Set
	//Data length DL (0 -> 4pins, 1 -> 8 pins), Number of Lines N (0 -> 1 line, 1 -> 2 lines), and Font resolution (0 -> 5×8, 1 -> 5×11), - -> don't care
	// 0b|0|0|1|DL|N|F|-|-|
	LCD_vidwriteCommand(0b00111000);

	_delay_ms(2);

	//Display on/off D (0 off, 1 on)
	//Cursor on/off C (0 off, 1 on)
	//Cursor Blink on/off B (0 off, 1 on)
	// 0b|0|0|0|0|1|D|C|B|
	LCD_vidwriteCommand(0b00001100);

	_delay_ms(2);

	//Clear Screen
	LCD_vidwriteCommand(1);

	_delay_ms(2);
}
