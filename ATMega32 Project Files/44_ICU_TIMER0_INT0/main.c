/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	--------------------------------------------------------------------- Program Description -----------------------------------------------------------------------------------------------------------------------------------------------------------------------



	This code is used to use TIMER 0 and External Interrupt pin INT0 to build an Input Capture Unit (ICT) that takes a signal on INT0 pin and
	bring back the register value corresponds to its duty cycle (high level) OCR0_Ton and the low level value OCR0_Toff

	-----------------------------------------------------TIMER0 Registers----------------------------------------------------------------

	Registers used and their description:

	1- Timer/Counter 0 Control Register (TCCR0):
		bits:
					  7       6      5        4       3       2      1        0
					FOC0 	WGM00 	COM01 	COM00 	WGM01 	CS02 	CS01 	CS00
		description:
		1- Force Output Compare (FOC0) : used only when WGM00 is specified for no PWM mode. used for compare match mode. Not used here
		2- Waveform Generation Mode (WGM00, WGM01): used to specify the mode of the timers (Normal 00, PWM 01, CTC 10, Fast PWM 11)
		3- Compare Match Output Mode (COM01, COM00): these bits control the Output Compare pin (OC0) behavior (used for compare match mode)
		4- Clock Select (CS02, CS01, CS00): used to select clock source and/or presecaler to be used by the Timer/Counter
			Note: when setting any of these bits, the timer is turned on. It will stop when all of the bits are zeros. There is an option to use external clock source


	2- Output Compare Register of Timer/Counter 0 (OCR0): The Output Compare Register contains an 8-bit value that is continuously compared with the counter value (TCNT0).


	-----------------------------------------------------External Interrupts Registers----------------------------------------------------------------

	3- MCU Control Register (MCUCR):
		configurable bits:
								bit3		bit2		bit1		bit0
								ISC11		ISC10		ISC01		ISC00
		bit description:

		---------- INT1 Interrupt Request Configuration -----------			---------- INT0 Interrupt Request Configuration -----------
		--- what happens on INT1 (D3) pin to request interrupt ----			--- what happens on INT0 (D2) pin to request interrupt ----

		(INT1) Interrupt Sense Control 1 Bit 3 & 2 (ISC11 & ISC10):			(INT1) Interrupt Sense Control 0 Bit 1 & 0 (ISC01 & ISC00):
		0|0 low level request interrupt										0|0 low level request interrupt
		0|1 any change on INT1 pin request interrupt						0|1 any change on INT1 pin request interrupt
		1|0 falling edge request interrupt									1|0 falling edge request interrupt
		1|1 rising edge request interrupt									1|1 rising edge request interrupt


	4- General Interrupt Control Register (GICR)
		configurable bits:
								bit7		bit6		bit5
								INT1		INT0		INT2
		bit description:
			I-   External Interrupt Request 1 Enable (INT1): Set it to enable using INT1
			II-  External Interrupt Request 0 Enable (INT0): Set it to enable using INT0
			III- External Interrupt Request 2 Enable (INT2): Set it to enable using INT2


	5- Status Register (SREG):
		configurable bits:
								bit7
								I
		bit description:
			I-   Global Interrupt Enable (I): Set it to enable any Maskuble interrupt (external (INT0, INT1, INT2), internal (ADC, UART, Timers,...))

	Note: The function that to be executed when interrupt is requested is:
		ISR(__vecotr_NO)
		{
			// Body of the function that to be executed when interrupt is requested
		}

		where NO is ( Vector No. - 1 ). Vector No. is found in Interrupt Vectors table in the data sheet



	-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();
#include<avr/interrupt.h> // Used to include the interrupt register names in order to use it to start using interrupts

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.


// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

/* ----------------------------------- Start of TIMER/COUNTER 0 Registers and their Bits' Macros ----------------------------------------------- */
// TIMER/COUNTER 0 Registers' Addresses
#define TCCR0  *(volatile u8*)  (0x53) // Timer/Counter 0 Control Register
#define OCR0   *(volatile u8*)  (0x5C) //  Output Compare Register 0 Register

// TCCR0 Bits Macros
#define WGM00 6 // wave generation bit
#define COM01 5 // compare match mode
#define COM00 4 // compare match mode
#define WGM01 3 // wave generation bit
#define CS02  2 // Prescaler Selection
#define CS01  1 // Prescaler Selection
#define CS00  0 // Prescaler Selection

/* ------------------------------------- End of TIMER/COUNTER 0 Registers and their Bits' Macros ---------------------------------------------- */

/*----------------------------------------------- Interrupt Register Macros -----------------------------------------------------------*/
// MCUCR Register Bit Macros
#define ICS00	0	// config of INT0
#define ICS01	1	// config of INT0


// GICR Register Bit Macros
#define INT0	6	// PIN D2

// SREG Register Bit Macro
#define I 	7 // I-bit : Global interrupt enable
/*-------------------------------------------------------------------------------------------------------------------------------------*/


// Pins Selected
#define INT0_Pin PIN26  // INT0 Pin D2

// User Data Type definition

// Function prototype
	ISR(INT0_vect); // Function executed on interrupt request

// Declared Structures (if Type definition)
// Declared Functions

	// Global variables (Declaration and Initialization)
	u8 OCR0_Ton, OCR0_Toff, direction, temp;
// Enum


void main(void)
{

	// Declaration and Initialization (executed once)
	DDRC = 0xFF; // all port C is output (LED) representation for OCR0_Ton value coming from the other MCU
	SetPinDirection(INT0_Pin, INPUT); // define INT0 pin as input


	// program variables

	// Module Initialization
		// Timers Initialization (Fast PWM, 64 prescaler, OC0 pin high till output compare match, low till overflow)
			CLR_BIT(TCCR0, WGM00); // Normal wave generation mode
			CLR_BIT(TCCR0, WGM01); // Normal wave generation mode
			CLR_BIT(TCCR0, COM01); // Normal mode, don't connect OC0 pin
			CLR_BIT(TCCR0, COM00); // Normal mode, don't connect OC0 pin

			CLR_BIT(TCCR0, CS02); SET_BIT(TCCR0, CS01); SET_BIT(TCCR0, CS00); // Start the timer. prescaler 64

		// External Interrupt INT0 Initialization
			// MCUCR
			SET_BIT(MCUCR, ICS00); // Interrupt request on any logical change on INT0
			CLR_BIT(MCUCR, ICS01); // Interrupt request on any logical change on INT0
			// GICR
			SET_BIT(GICR, INT0); // INT0 Interrupt enable
			// SREG
			SET_BIT(SREG, I); // global interrupt enable

	while(1)
	{
		// Write your instructions here.
		if (direction == 0)
		{
			OCR0_Ton = temp; // last input value was 1 -- was measuring T_on
			direction = 2;   // don't get to this again till anther interrupt happens
		}

		else if (direction == 1)
		{
			OCR0_Toff = temp; // last input value was 0 -- was measuring T_off
			direction = 2;   // don't get to this again till anther interrupt happens
		}

		PORTC = OCR0_Ton; // write the OCR0_Ton value on Port C to show its binary value
	}

	// Don't Add anything here (will not be executed)
}

// Function executed on interrupt request (get T_on, T_off, direction)
ISR(INT0_vect) // ISR(__vector_1)
{
	temp = TCNT0; // get the timer register value
	TCNT0 = 0; // clear the timer register
	direction = GetPinValue(INT0_Pin); // get the value of the input signal (now after interrupt happens)
}




