/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Initialize the ADC,
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

#define ADMUX  *(volatile u8*) 	(0x27) // ADC Multiplexer Selection Register
#define ADCSRA *(volatile u8*) 	(0x26) // ADC Control and Status Register
#define ADCH   *(volatile u8*)  (0x25) // ADC Data Register High Byte
#define ADCL   *(volatile u8*)  (0x24) // ADC Data Register Low Byte

// ADMUX Register
#define REFS1 7 // Reference Selection Bits
#define REFS0 6 // Reference Selection Bits
#define ADLAR 5 // ADC Left Adjust Result
#define MUX4  4 // Analog Channel and Gain Selection Bits
#define MUX3  3 // Analog Channel and Gain Selection Bits
#define MUX2  2 // Analog Channel and Gain Selection Bits
#define MUX1  1 // Analog Channel and Gain Selection Bits
#define MUX0  0 // Analog Channel and Gain Selection Bits

// ADCSRA Register
#define ADEN  7 // ADC Enable
#define ADSC  6 // ADC Start Conversion
#define ADATE 5 // ADC Auto Trigger Enable
#define ADIF  4 // ADC Interrupt Flag
#define ADIE  3 // ADC Interrupt Enable
#define ADPS2 2 // ADC Prescaler Select Bits
#define ADPS1 1 // ADC Prescaler Select Bits
#define ADPS0 0 // ADC Prescaler Select Bits

#define IF GET_BIT(ADCSRA, 4) // ADCSRA: Interrupt flag bit

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum


void ADC_Init(void)
{
	// ADMUX Register (can be written as ADMUX = 32)
		CLR_BIT(ADMUX, REFS1); // REFS1: VREF
		CLR_BIT(ADMUX, REFS0); // REFS0: VREF
		SET_BIT(ADMUX, ADLAR); // ADLAR: Left Adjustment
		CLR_BIT(ADMUX, MUX4); // MUX4:  ADC0 (channel 0)
		CLR_BIT(ADMUX, MUX3); // MUX3:  ADC0 (channel 0)
		CLR_BIT(ADMUX, MUX2); // MUX2:  ADC0 (channel 0)
		CLR_BIT(ADMUX, MUX1); // MUX1:  ADC0 (channel 0)
		CLR_BIT(ADMUX, MUX0); // MUX0:  ADC0 (channel 0)

	// ADCSRS Register (can be written as ADCSRA = 130)
		SET_BIT(ADCSRA, ADEN); // ADEN:  ADC Enable
		CLR_BIT(ADCSRA, ADSC); // ADSC:  Don't start ADC conversion
		CLR_BIT(ADCSRA, ADATE); // ADATE: Don't enable triggering
		//CLR_BIT(ADCSRA, ADIF); // ADIF: Interrupt Flag
		CLR_BIT(ADCSRA, ADIE); // ADIE:  ADC interrupt disable
		SET_BIT(ADCSRA, ADPS2); // ADPS2: Division factor = 4
		SET_BIT(ADCSRA, ADPS1); // ADPS1: Division factor = 4
		SET_BIT(ADCSRA, ADPS0); // ADPS0: Division factor = 4
}



void main(void)
{
	// Declaration and Initialization (executed once)
		// Program Variables
	int i; // counter
	u8 Data; // used to store the ADC converted data

	// Pin Direction (Input/Output)
	for(i = 16; i<=23; i++)
	{
	SetPinDirection(i, OUTPUT); // define port C 8 pins output for LEDs
	}

	// Pin Values (initialization)
	// Module Initialization
	ADC_Init(); // Initialize ADC

	while(1)
	{
		// Write your instructions here.
		SET_BIT(ADCSRA, ADSC); // Start ADC conversion
		while(IF==0); // wait here as IF is not 1. If 1, it ADC finished conversion

		Data = ADCH; // get data from High register (we neglected ADCL, use 8 bit resolution, no absolute error)

		SET_BIT(ADCSRA, ADIF); // Clear Interrupt Flag by writing 1
		PORTC = Data; // write data to the port C pins (on LEDs)

	}

	// Don't Add anything here (will not be executed)
}
