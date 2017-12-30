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

// User Data Type definition
// Function prototype
void TWI_Master_Init(void);
void TWI_Master_Start(void);
void TWI_Master_Write(u8 Master_Data);
void TWI_Master_Stop(void);
void TWI_Master_Read(u8* ptr);

void ExEEPROM_Read(u8 Addr, u8* ptr);
void ExEEPROM_Write(u8 Addr, u8 data);


// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum



void main(void)
{
	// Declaration and Initialization (executed once)
		// Program Variables
		u8 R;
		// Pin Direction (Input/Output)
SetPinDirection(PIN24, OUTPUT);
		// Pin Values (initialization)
		// Module Initialization
		TWI_Master_Init();



		// After Send


	while(1)
	{
		// Write your instructions here.
        ExEEPROM_Write(0x00,0xE0);

         _delay_ms(1000); // You must allow suffcent delay for the EEPROM to complete the its internal write cycle

         ExEEPROM_Read(0x00,&R);

         if (R==0xE0)

         {
                SetPinValue(PIN24, HIGH);

         }



	}

	// Don't Add anything here (will not be executed)
}
void TWI_Master_Init(void)
{
    TWSR=0;
    TWBR=0x0C;
    TWCR|=(1<<TWEN);

}
void TWI_Master_Start(void)
{
    TWCR= (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(GET_BIT(TWCR, TWINT) == 0);
}

void TWI_Master_Write(u8 Master_Data)
{
	TWDR = Master_Data;
    TWCR= (1<<TWINT)|(1<<TWEN);
	while(GET_BIT(TWCR, TWINT) == 0);

}

void TWI_Master_Stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWSTO);
}

void TWI_Master_Read(u8* ptr)
{
	TWCR=(1<<TWINT)|(1<<TWEN);SET_BIT(TWCR, TWEN);
	while(GET_BIT(TWCR, TWINT) == 0);
	*ptr = TWDR;
}

void ExEEPROM_Read(u8 Addr, u8* ptr)
{
	TWI_Master_Start();
	TWI_Master_Write(0xA8);
	TWI_Master_Write(Addr);
	TWI_Master_Start();
	TWI_Master_Write(0xA9);
	TWI_Master_Read(ptr);
	TWI_Master_Stop();
}

void ExEEPROM_Write(u8 Addr, u8 data)
{
	TWI_Master_Start();
	TWI_Master_Write(0xA8);
	TWI_Master_Write(Addr);
	TWI_Master_Write(data);
	TWI_Master_Stop();
}
