/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Use the Peripheral interrupt concept to operate the ADC peripheral. When enabling the interrupt of
	the ADC, the interrupt request is configured that when the ADC completes the conversion process, it
	goes to the ISR function to execute it. ISR function will contain the data fetching from the data
	registers ADCH, ADCL. Noting that when using ADC interrupt, we don't need to reset the flag after
	getting the data as it is automatically reset.

	The algorithm of the using the ADC interrupt is as follows:

		1- Initialize the ADC with your configurations (A_Ref, Left Adjustment, ADC0 channel, Prescaler 2)
		2- Enable Global Interrupt by setting SREG register bit no. 7
		3- Enable ADC Interrupt by setting ADIE bit in ADCSRA register
		4- Start ADC conversion by setting ADSC bit in ADCSRA register
		   Note: if started conversion instruction outside ISR function --> ADC converts once as
		   it completes once and request interrupt when completing. If wanted to convert data
		   continuously, at the end of the ISR function start conversion set ADSC

	Note: Never forget to connect Vref to what configured (here AREF)


	Note: The function that to be executed when interrupt is requested is:
		ISR(__vecotr_NO)
		{
			// Body of the function that to be executed when interrupt is requested
		}

		where NO is ( Vector No. - 1 ). Vector No. is found in Interrupt Vectors table in the data sheet

*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"DADC.h" // This header file includes the configurations of the ADC and function prototypes of ADC_init(); and ADC_GetData(); functions
#include<avr/interrupt.h> // Used to include the interrupt register names in order to use it to start using interrupts


// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

// Defined in interrupts.h
// #define SREG  *(volatile u8*)  (0x5F)


// SREG Register Bit Macro
#define I 	7 // I-bit : Global interrupt enable


	// User Data Type definition

	// Function prototype
		ISR(__vector_16);

	// Declared Structures (if Type definition)
	// Declared Functions
	// Global variables (Declaration and Initialization)

// Enum


void main(void)
{

		// Declaration and Initialization (executed once)
		// Program Variables

		// Pin Direction (Input/Output)
			DDRC = 0xFF; // define port C 8 pins output for LEDs

		// Pin Values (initialization)
		// Module Initialization


		SET_BIT(SREG, I); // global interrupt enable

		// Initialization of ADC and Configuration Specifications
			ADC_CONFIG MyConfig; // Create an object of the ADC_CONFIG data structure type
			MyConfig.Ref = REF_AREF; // let AREF pin is the VREF
			MyConfig.Adjustment = ADJUSTMENT_LEFT; // Left Adjustment
			MyConfig.Channel = CHANNEL_ADC0; // use ADC0 <-> A0 pin, don't define it as input
			MyConfig.Prescaler = PRESCALER_2; // use the prescaler of 2 i.e. sampling frequency = F_CPU / 2 = 4MHz
			ADC_Init(MyConfig); // Initialize the ADC with the previous configurations
			SET_BIT(ADCSRA, ADIE); // to enable using ADC Interrupt
			SET_BIT(ADCSRA, ADSC); // to start conversion using ADC, initially to go to the function ISR(__vector_16) {}




	while(1)
	{
		// Write your instructions here.


	}

	// Don't Add anything here (will not be executed)
}


// Function executed on interrupt request (ADC get data)
ISR(__vector_16) // ADC complete conversion (Vector No. 17  - 1). Executed when ADC completes conversion
{
	u8 data = ADCH; // get data from ADCH, 8 bit resolution
	PORTC = data; // write data on PORTC (8LEDs)
	// automatically reset the flag
	SET_BIT(ADCSRA, ADSC); // Again, start conversion to make the ADC continuously convert data

}

