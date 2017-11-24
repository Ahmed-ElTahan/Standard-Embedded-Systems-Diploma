/*
 * HLCD.h
 *
 *  Created on: Sep 8, 2017
 *      Author: Ahmed A. Eltahan
 */
/*
 This Header file is used to:
 1- include the pins chosen to be connect LCD screen with the MCU
 2- include the function prototypes of 3 functions:
 	I- LCD_vidwriteCommand: used to send "commands" to the LCD screen as choosing modes(4/8 pins), no. of lines, cursor show, cursor blink
	that happens by setting control pins/bits (RS, RW, EN) and Data pins/bits (D0 --> D7) to special set (0s and 1s) according to the data sheet
	Note: any command sent to the LCD will not work till an "enable pulse" is sent after it as:
			enable (high) --> hold for 2 ms --> enable (low)
	II- LCD_vidwriteData: used to send "data" to the LCD screen as numbers/chars/special chars. the char is sent as ASCCI (between 2 single quotes)
	III- LCD_vidInit(): used to initialize the LCD for working as the following:
		a- delay with minimum 30 ms to let the high voltage reach its value in the LCD
		b- set a bunch of settings as:
			- Function set (mode 4/8 pins, no. of lines, resolution)
			- Display on/off control (display on/off, cursor show, cursor blink)
			- Clear screen
 */
#ifndef HLCD_H_
#define HLCD_H_

#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"STD_TYPES.h" // To include user defined data types (u8, u16 ... f96)
#include"UTILS.h" // To include set/toggle/clear/get bit function macros

// Control Pins
#define LCD_RS 16 // Register Select
#define LCD_RW 17 // Read/Write
#define LCD_EN 18 // Enable

// Data Pins D0 --> D7
#define LCD_D0 24 // D0
#define LCD_D1 25 // D1
#define LCD_D2 26 // D2
#define LCD_D3 27 // D3
#define LCD_D4 28 // D4
#define LCD_D5 29 // D5
#define LCD_D6 30 // D6
#define LCD_D7 31 // D7

// Note: VO, the contrast pin, should be connected to a potentiometer

// Function Prototypes
void LCD_vidwriteCommand(u8 command);
void LCD_vidwriteData(u8 data);
void LCD_vidInit(void);


#endif /* HLCD_H_ */
