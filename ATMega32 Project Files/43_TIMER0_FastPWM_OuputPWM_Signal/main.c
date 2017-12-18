/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	--------------------------------------------------------------------- Program Description -----------------------------------------------------------------------------------------------------------------------------------------------------------------------

	Programming Project by USBasp kit using AVR Dude to:
	ATMega32 has three Timers (TIMER/COUNTER 0, TIMER/COUNTER 1, TIMER/COUNTER 2). There are 2 methods to use Timers:
	1- Flag (when something happen flag is raised)    2- Interrupt (when something happens an ISR function is executed)
	The thing to be happened in order to specify timer counts are two methods:
	1- Overflow of counting register (TCNT0)		  2- Matching current count with a compare register.

	This code is used to introduce using Timers, specifically TIMER/COUNTER 0 with the method of (Overflow - Flag) with
	the fast PWM mode of wave generation method. The PWM signal generated on OC0 (B3) pin used as an input to another MCU
	to be tested by input capture unit coded on it.

	Fast PWM mode used the 2 modes (compare match - overflow) to do something depending on the configuration of COM01 and COM00 as the following:

				COM01 	|   COM00    | Action

				  0           0          do interrupt/flag if each happen (interally)
				  0           1 	     --------------------------------------------
				  1           0          output a signal on OC0 pin (B3) as this:
				  				  	  	  	  ______
				 	 	 	 	 	 	 	 |		|
			     	 	 	 	 	 	 	 |		|________________________
				  	  	  	  	  	  	  	        compare                  overflow
				  	  	  	  	  	  	  	        match action			 action
				  	  	  	  	  	  	  	        set Low					 set high
													based on
													value of OCR0
													register

				  1           1          output a signal on OC0 pin (B3) as this:
				  				  	  	  	  	  	  	  	  	  	  	  	  ______
				 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	 |		|
			     	 	 	 	 	 	 	 	     ________________________|		|
				  	  	  	  	  	  	  	        				   compare       overflow
				  	  	  	  	  	  	  	         	 	 	       match action	 action
				  	  	  	  	  	  	  	        				   set High	     set low
																	   based on
																	   value of OCR0
																	   register

	the signal required is as  COM01 = 1, COM00 = 0;

				  ______
				 |		|
			     |		|________________________

			     | T_on |

			     |           2.048 ms          |

			     2.048 ms is the T_overflow based on Prescaler of 64
			     T_pulse = 8 us
				 T_on = 1.75 ms
	OCR0 will be defined as T_on/Prescaler ~= 219

	Timers has the same register names except the last number points to the timer's number used

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



	-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

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

// Pins Selected
#define OC0PWM_Pin PIN11  // OC0 Pin B3

// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum


void main(void)
{

	// Declaration and Initialization (executed once)
	SetPinDirection(OC0PWM_Pin, OUTPUT); // define OC0 Pin (PWM) pin as output


	// program variables

	// Module Initialization
		// Timers Initialization (Fast PWM, 64 prescaler, OC0 pin high till output compare match, low till overflow)
			SET_BIT(TCCR0, WGM00); // Fast PWM wave generation mode
			SET_BIT(TCCR0, WGM01); // Fast PWM wave generation mode
			SET_BIT(TCCR0, COM01); // Clear OC0 on compare match, set OC0 at BOTTOM
			CLR_BIT(TCCR0, COM00); // Clear OC0 on compare match, set OC0 at BOTTOM

			CLR_BIT(TCCR0, CS02); SET_BIT(TCCR0, CS01); SET_BIT(TCCR0, CS00); // Start the timer. prescaler 64

			OCR0 = 219; // T_on = 1.75 ms

	while(1)
	{
		// Write your instructions here.
	}
	// Don't Add anything here (will not be executed)
}



