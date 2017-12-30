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

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

// User Data Type definition
// Function prototype
void TWI_Master_Init(void);
void TWI_Master_Start(void);
void TWI_Master_Write_Addr(u8 Slave_Addr);
void TWI_Master_Write_Data(u8 Master_Data);
void TWI_Master_Stop(void);



// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum



void main(void)
{
	// Declaration and Initialization (executed once)
		// Program Variables

		// Pin Direction (Input/Output)

		// Pin Values (initialization)
		// Module Initialization
		TWI_Master_Init();



		// After Send


	while(1)
	{
		// Write your instructions here.

		TWI_Master_Start();
		_delay_ms(1000);
		TWI_Master_Write_Addr(0x20);
		_delay_ms(1000);
		TWI_Master_Write_Data('A');
		_delay_ms(1000);
		TWI_Master_Stop();
		_delay_ms(1000);



	}

	// Don't Add anything here (will not be executed)
}
void TWI_Master_Init(void)
{
	TWBR = 0x00; // clear bit rate register
	TWBR = 0x0C; // set bit rate
}
void TWI_Master_Start(void)
{
    TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);

	while(GET_BIT(TWCR, TWINT) == 0);
	while((TWSR & (0xF8)) != 0x08);
}

void TWI_Master_Write_Addr(u8 Slave_Addr)
{
	TWDR = Slave_Addr;
    TWCR= (1<<TWINT)|(1<<TWEN);


	while(GET_BIT(TWCR, TWINT) == 0);
	while((TWSR & (0xF8)) != 0x18);

}

void TWI_Master_Write_Data(u8 Master_Data)
{
	TWDR = Master_Data;
    TWCR= (1<<TWINT)|(1<<TWEN);


	while(GET_BIT(TWCR, TWINT) == 0);
	while((TWSR & (0xF8)) != 0x28);

}

void TWI_Master_Stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);


}

