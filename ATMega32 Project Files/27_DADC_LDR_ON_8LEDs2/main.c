/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	use DDAC driver in order to input Light Dependent Resistance (LDR) output(Vo) to ADC0 == A0 pin and
	convert the analog value through the ADC. Then, read the converted data and with 8 bit Resolution
	(only Read ADCH register) and print this digital value (0-255) on 8 LEDs connected on PORTC

	Note: Our Case:
	Vref = 5V, Resolution = 8 bit, Step = 5 / (2^8) = 0.0195 V = 19.5 mV (sensitivity), Max Digital (255), Max Analog (Vref = 5V)
	using R in the circuit:
	Digital value (output of the ADC) =

	Digital Value	|	Binary(LED output)	|	RL (LDR reisitance)
		245			|  11110101				|		400 Ohm
		134			|  10000110				|		9K  Ohm
		2			|  00000010				|		1M  Ohm

*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HLCD.h" // This header file includes the set of pins selected to connect LCD with MCU and 3 function prototypes above that used to control and display commands and data on LCD screen, repectively
#include"HKPD.h" // This header file includes selection of keypad pins and define functions to deal with keypad (initialization, get pressed key)
#include"DADC.h" // This header file includes the configurations of the ADC and function prototypes of ADC_init(); and ADC_GetData(); functions

// User-defined #define (Macros: Object / Function)
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
	// Program Variables
	u16 data; // to store data output after ADC conversion
	DDRC = 0xFF; // define port C 8 pins output for LEDs

		// Pin Direction (Input/Output)
		// Pin Values (initialization)

		// Module Initialization

			// Initialization of ADC and Configuration Specifications
			ADC_CONFIG MyConfig; // Create an object of the ADC_CONFIG data structure type
			MyConfig.Ref = REF_AREF; // let AREF pin is the VREF
			MyConfig.Adjustment = ADJUSTMENT_LEFT; // Left Adjustment
			MyConfig.Channel = CHANNEL_ADC0; // use ADC0 <-> A0 pin, don't define it as input
			MyConfig.Prescaler = PRESCALER_2; // use the prescaler of 2 i.e. sampling frequency = F_CPU / 2 = 4MHz
			ADC_Init(MyConfig); // Initialize the ADC with the previous configurations


	while(1)
	{
		// Write your instructions here.
		// ADC_GetData() returns data as: [ADCH (8)] [ADCL (8)] and we need them as [0000 0000] [ADCH (8)] neglect ADCL bits and use only ADCH reduce resolution 1024 to 255 with no absolute error
		data = ADC_GetData() >> 8; // shift ADCH to 1st 8 bits of the u16 as it is at bits (9-16)
		PORTC = data; // write the 8 bit data on the port C on LEDs

	}

	// Don't Add anything here (will not be executed)
}
