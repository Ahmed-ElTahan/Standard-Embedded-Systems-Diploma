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
	the normal mode of wave generation method. It's required to blink an LED connected on C0 with the concept of timers.

	the signal is as

				  ______        ______	      ______
				 |		|	   |	  |		 |	    |
			_____|		|______|	  |______|	    |______

				 | T_on |T_off|

		T_on == T_off = 1 sec.

	Timers has the same register names except the last number points to the timer's number used

	Registers used and their description:

	1- Timer/Counter 0 Control Register (TCCR0):
		bits:
					  7       6      5        4       3       2      1        0
					FOC0 	WGM00 	COM01 	COM00 	WGM01 	CS02 	CS01 	CS00
		description:
		1- Force Output Compare (FOC0) : used only when WGM00 is specified for no PWM mode. used for compare match mode
		2- Waveform Generation Mode (WGM00, WGM01): used to specify the mode of the timers (Normal 00, PWM 01, CTC 10, Fast PWM 11)
		3- Compare Match Output Mode (COM01, COM00): these bits control the Output Compare pin (OC0) behavior (used for compare match mode)
		4- Clock Select (CS02, CS01, CS00): used to select clock source and/or presecaler to be used by the Timer/Counter
			Note: when setting any of these bits, the timer is turned on. It will stop when all of the bits are zeros. There is an option to use external clock source

	2- Timer/Counter 0 Register (TCNT0): The Timer/Counter Register gives direct access, both for read and write operations, to the Timer/Counter unit 8-bit counter. Read (e.g. for compare match method) Write (e.g. for initialization of the fraction number)

	3- Output Compare Register of Timer/Counter 0 (OCR0): The Output Compare Register contains an 8-bit value that is continuously compared with the counter value (TCNT0).

	4- Timer/Counter 0 Interrupt Mask Register (TIMSK):
		bits:
				      1       0
					OCIE0	TOIE0
		description:
		1- Timer/Counter 0 Output Compare Match Interrupt Enable (OCIE0): when it is set, this enables using the interrupt option. ISR function will be executed on compare match method
		2- Timer/Counter0 Overflow Interrupt Enable (TOIE0): when it is set, this enables using the interrupt option. ISR function will be executed when an overflow happens of the TCNT0 register


	5- Timer/Counter 0 Interrupt Flag Register (TIFR):
		bits:
				      1       0
					OCF0	TOV0
		description:
		1- Timer/Counter 0 Output Compare Flag (OCF0): returns 1 when a compare match occurs between TCNT0 and OCR0.
		2- Timer/Counter0 Overflow Flag (TOV0): returns 1 when an overflow of the TCNT0 register takes place.


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
#define TIMSK  *(volatile u8*)  (0x59) // Timer/Counter 0 Interrupt Mask Register
#define TIFR   *(volatile u8*)  (0x58) // Timer/Counter 0 Interrupt Flag Register
#define TCCR0  *(volatile u8*)  (0x53) // Timer/Counter 0 Control Register
#define TCNT0  *(volatile u8*)  (0x52) // Timer/Counter 0 Register

// TCCR0 Bits Macros
#define WGM00 6 // wave generation bit
#define COM01 5 // compare match mode
#define COM00 4 // compare match mode
#define WGM01 3 // wave generation bit
#define CS02  2 // Prescaler Selection
#define CS01  1 // Prescaler Selection
#define CS00  0 // Prescaler Selection

// TIMSK Bits Macros
#define OCIE0 1 // Output compare interrupt enable
#define TOIE0 0 // Overflow interrupt enable

// TIFR Bits Macros
#define OCF0 1 // Output compare match flag
#define TOV0 0 // Overflow flag

// Time Required Number of overflows and initial value of TCNT0 Macros (prescaler 1024)
	// One Second
	#define OneSecCounts_1024  31 // to check the number of loops
	#define OneSecInitTCNT0_1024  123 // to match the partial number of the part of a count (non full overflow)

/* ------------------------------------- End of TIMER/COUNTER 0 Registers and their Bits' Macros ---------------------------------------------- */

// Pins Selected
#define LED_Pin PIN16



// User Data Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)


// Enum


void main(void)
{

	// Declaration and Initialization (executed once)
	SetPinDirection(LED_Pin, OUTPUT); // define LED pin as output

	// program variables
	u8 overflows; // used to count the number of overflows
	// Timers Initialization

	while(1)
	{
		// Write your instructions here.

			// --------------------------------------- One Seconds Starts ---------------------------------------------
				// initially
				overflows = 0;
				TCNT0 = OneSecInitTCNT0_1024;

				// start count
				SET_BIT(TCCR0, CS02); CLR_BIT(TCCR0, CS01); SET_BIT(TCCR0, CS00); // TCCR0 = 0b00000101; pescaler 1024

				while (overflows <= OneSecCounts_1024) // stuck here till the count you want
				{
					while(GET_BIT(TIFR, TOV0)==0); // wait till flag is raised
					overflows++; // increment the counter of overflows
					SET_BIT(TIFR, TOV0); // clear flag
				}

				SetPinValue(LED_Pin, HIGH);
			// --------------------------------------- One Seconds Ends with (LED ON) ---------------------------------


			// --------------------------------------- One Seconds Starts ---------------------------------------------
				// initially
				overflows = 0;
				TCNT0 = OneSecInitTCNT0_1024; // getting out from the last One second, this to enforce the TCNT0 register to start from this number, then as the timer is on, it continues on it

				// start count (already started)
				// SET_BIT(TCCR0, CS02); CLR_BIT(TCCR0, CS01); SET_BIT(TCCR0, CS00); // TCCR0 = 0b00000101; pescaler 1024
				while (overflows <= OneSecCounts_1024) // stuck here till the count you want
				{
					while(GET_BIT(TIFR, TOV0)==0); // wait till flag is raised
					overflows++; // increment the counter of overflows
					SET_BIT(TIFR, TOV0); // clear flag
				}
				SetPinValue(LED_Pin, LOW);
			// --------------------------------------- One Seconds Ends with (LED OFF) --------------------------------

	}


}

	// Don't Add anything here (will not be executed)

