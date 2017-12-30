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
#include<avr/io.h>
#include<avr/eeprom.h>
// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds
/*
#define EEARL (*(volatile u8*) (0x3E))
#define EECR  (*(volatile u8*) (0x3C))
#define EEDR  (*(volatile u8*) (0x3D))

#define EEMWE 2
#define EEWE 1
#define EERE 0

*/

// User Data Type definition

// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
void vid_EEPROM_Write(u16 address, u8 data)
{
	while(GET_BIT(EECR, EEWE));
	EEDR = data;
	EEARL = address;


	SET_BIT(EECR, EEMWE);	//CLR_BIT(EECR, EEWE);

	SET_BIT(EECR, EEWE);

}

u8 u8_EEPROM_Read(u16 address)
{
while(GET_BIT(EECR, EEWE));
	EEARL = address;
	SET_BIT(EECR, EERE);

	return EEDR;

}
// Global variables (Declaration and Initialization)
// Enum

int main(void)
{	LCD_vidInit(); // Initialize the LCD
	// Declaration and Initialization (executed once)
		// Program Variables
		unsigned char eeprom_address = 0x00, write_char = 'X', read_char;		// Pin Direction (Input/Output)
		SetPinDirection(0, OUTPUT);
		SetPinDirection(1, OUTPUT);

		// Pin Values (initialization)
		// Module Initialization
		vid_EEPROM_Write(eeprom_address, write_char); // not working ??!
		//eeprom_write_byte(eeprom_address, write_char);
		//_delay_ms(1000);

		read_char = u8_EEPROM_Read(eeprom_address); // working fine
		LCD_vidWriteDecimal(read_char);

		//data = eeprom_read_byte(512);

		if(read_char == write_char)
		{
			SetPinValue(0, HIGH);
		}
		else
		{
			SetPinValue(1, HIGH);
		}

	while(1)
	{
		// Write your instructions here.





	}

	// Don't Add anything here (will not be executed)
}



