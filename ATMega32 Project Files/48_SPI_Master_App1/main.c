/*
 * main.c
 *
 *  Created on: Dec 29, 2017
 *      Author: Ahmed A. Eltahan
 */


/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	SPI transfer (Master)
*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

// User Data Type definition

// Function prototype
void SPI_vidMasterInit(void);
u8 SPI_u8Transceiver(u8 data);
u8 SPI_transmit(u8 data);


// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

/* ----------------- SPI Registers' IO Addresses and Bits Macros -------------*/

// SPI Registers' IO Addresses
#define SPCR (*(volatile u8*)(0x2D)) // SPI Control Register
#define SPDR (*(volatile u8*)(0x2F)) // SPI Data Register
#define SPSR (*(volatile u8*)(0x2E)) // SPI Status Register

// SPCR Bits
#define SPIE	7 // SPI interrupt
#define SPE		6 // SPI enable
#define DORD	5 // Most Signif. Bit First (MSB) or Least Sginif. Bit First (LSB)
#define MSTR	4 // Master or Slave Mode
#define CPOL	3 // Clock polarity
#define CPHA	2 // Clock phase
#define SPR1	1 // Used with SPR0 and SPIX2 to determine the SPI clock used
#define SPR0	0 // Used with SPR1 and SPIX2 to determine the SPI clock used

// SPSR Bits
#define SPIF	7 // Tranceiver (Transmit + Receive) completion (send + read) flag
#define WCOL	6 // Collision flag
#define SPI2X	5 // Double speed mode used with SPR1 and SPR0 to determine the SPI clock used

// Flags
#define SPI_TranceiveCompFlag	GET_BIT(SPSR, SPIF) // Tranceiving completion

/* ---------------------------------------------------------  */


void main(void)
{
	// Declaration and Initialization (executed once)
		// Program Variables
			u8 data=0; // to store data
		// Pin Direction (Input/Output)

			SetPinDirection(PIN24, OUTPUT); // LED1 D0
			SetPinDirection(PIN25, OUTPUT); // LED2 D1
			SetPinDirection(PIN26, OUTPUT); // LED3 D2

		// Pin Values (initialization)

		// Module Initialization
			// SPI Initialization
				SPI_vidMasterInit();




	while(1)
	{
		// Write your instructions here.



						data = SPI_u8Transceiver('S');
						if (data == 'P')
						{
							SetPinValue(PIN24,HIGH);
						}
						else
						{
							SetPinValue(PIN25,HIGH);
						}


		//_delay_ms(1000);
	//	SPI_transmit('S');
	}

	// Don't Add anything here (will not be executed)
}


// Function used to initialize the master
void SPI_vidMasterInit(void)
{
	//SPDR = 0; // zero first, initially
	SPCR = 0b01010111; // (polling not interrupt mode, enable SPI, Master mode, MSB first, 0 clock polarity, 1 clock phase, clk = fsys/128)
	// SPI Pins
		SetPinDirection(PIN15, OUTPUT); // B7 (SCK)
		SetPinDirection(PIN13, OUTPUT); // B5 (MOSI)
		SetPinDirection(PIN12, OUTPUT); // B4 (SS)

		SetPinValue(PIN12, LOW); // active low to select the slave

		// MISO is enforced to be input

}


//Function to send data from the master to the slave and receive data from the slave
//Function to send data from the master to the slave and receive data from the slave
u8 SPI_u8Transceiver(u8 data)
{
	SPDR = data; 						// load data to the buffer
	while(SPI_TranceiveCompFlag == 0);	// wait till tranceiving completion
	SET_BIT(SPSR, SPIF);
	data = SPDR;
	return data;
}


u8 SPI_transmit(u8 data)
{
	SPDR = data;
	while(SPI_TranceiveCompFlag == 0);	// wait till tranceiving completion
	SET_BIT(SPSR, SPIF);
}
