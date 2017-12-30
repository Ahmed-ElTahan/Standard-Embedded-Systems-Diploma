
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
//#include<util/twi.h>
#include<avr/io.h>
// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

// User Data Type definition
// Function prototype
void TWI_Slave_Init(u8 Slave_Addr);
void TWI_Slave_Match_ACK(void);
u8 TWI_Slave_Read_Data(void);

// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum



void main(void)
{
	// Declaration and Initialization (executed once)
		// Program Variables

		// Pin Direction (Input/Output)
		DDRB = 0xFF;
		// Pin Values (initialization)
		// Module Initialization
		TWI_Slave_Init(0x20);

		u8 data;


	while(1)
	{
		// Write your instructions here.
		TWI_Slave_Match_ACK();
		data = TWI_Slave_Read_Data();
		if(data == 'A')
		{
			SetPinValue(8, HIGH);
		}
		else
		{
			SetPinValue(9, HIGH);
		}




	}

	// Don't Add anything here (will not be executed)
}
void TWI_Slave_Init(u8 Slave_Addr)
{
	 TWAR = Slave_Addr;
}

void TWI_Slave_Match_ACK(void)
{
	while((TWSR &(0xF8)) != 0x60)
	{

	    TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);

		while(GET_BIT(TWCR, TWINT) == 0);

	}

}

u8 TWI_Slave_Read_Data(void)
{
	u8 x;

    TWCR= (1<<TWINT)|(1<<TWEA)|(1<<TWEN);

	while(GET_BIT(TWCR, TWINT) == 0);
	while((TWSR &(0xF8)) != 0x80);

	x = TWDR;
	return x;

}


