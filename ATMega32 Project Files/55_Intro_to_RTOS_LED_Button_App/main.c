/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

	/*--------------------------------------------------------------------- Program Description -----------------------------------------------------------------------------------------------------------------------------------------------------------------------

	Programming Project by USBasp kit using AVR Dude to:
	ATMega32 has three Timers (TIMER/COUNTER 0, TIMER/COUNTER 1, TIMER/COUNTER 2). There are 2 methods to use Timers:
	1- Flag (when something happen flag is raised)    2- Interrupt (when something happens an ISR function is executed)
	The thing to be happened in order to specify timer counts are two methods:
	1- Overflow of counting register (TCNT0)		  2- Matching current count with a compare register.

	This code is used to introduce using Timers, specifically TIMER/COUNTER 0 with the method of (Overflow - Interrupt) with
	the normal mode of wave generation method. It's required to blink an LED connected on C0 with the concept of timers with the following signal.

	the signal is as

				  ______        ______	      ______
				 |		|	   |	  |		 |	    |
			_____|		|______|	  |______|	    |______

				 | T_on |T_off|

		T_on == T_off = 1 second

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
#include<avr/interrupt.h> // Used to include the interrupt register names in order to use it to start using interrupts

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

#define SREG   *(volatile u8*)  (0x5F) // Status register, to enable the global interrupt enable bit (I-bit)
#define I	7 // global interrupt enable bit (I-bit)

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

/* ------------------------------------- End of TIMER/COUNTER 0 Registers and their Bits' Macros ---------------------------------------------- */



// User Data Type definition

// Function prototype
ISR(__vector_11); // Timer/Counter0 Overflow. This function is executed when an overflow takes place in timer 0 register TCNT0


// Global variables (Declaration and Initialization)
	u8 ButtonState;
	u8 PreviousState = 0;

// Declared Functions


	void Init()
	{
		SetPinDirection(0, INPUT_PU); // A0 is pull up input
		SetPinDirection(8, OUTPUT); // B0 is led output pin
	}

	void PushButton()
	{
		if(GET_BIT(PINA, 0)) // not pressed
		{
			ButtonState = 0;
		}
		else
		{
			ButtonState = 1;
		}
	}

	void LED()
	{
		if(PreviousState != ButtonState)
		{
			SetPinValue(8, ButtonState);
			PreviousState = ButtonState;
		}

	}


	// Declared Structures (if Type definition)
	typedef struct
	{
		void (* ptr) (void);
		u16 Periodicity;
		s8 FirstDelay;
	} task;

	task Arr[] = {{Init, 0, 0}, {PushButton, 150, 0}, {LED, 150, 10}}; //

	void Schedular()
	{
		u8 i;
		for (i = 0; i<3; i++) // three tasks
		{
			if(Arr[i].FirstDelay == 0)
			{
				Arr[i].ptr();
				Arr[i].FirstDelay = Arr[i].Periodicity-1;
			}
			else if (Arr[i].FirstDelay != -1)
			{
				Arr[i].FirstDelay--;
			}
		}
	}


	// Enum




void main(void)
{

	// Declaration and Initialization (executed once)


	// program variables


	// Module Initialization
		// Timers Initialization
			CLR_BIT(TCCR0, WGM00); // Normal wave generation mode
			CLR_BIT(TCCR0, WGM01); // Normal wave generation mode
			SET_BIT(SREG, I); // global interrupt enable
			SET_BIT(TIMSK, TOIE0); // enable timer0 interrupt
			TCNT0 = 256-8; //
			SET_BIT(TCCR0, CS02); CLR_BIT(TCCR0, CS01); SET_BIT(TCCR0, CS00); // Start the timer TCCR0 = 0b00000101; prescaler 1024


	while(1)
	{
		// Write your instructions here.
	}

	// Don't Add anything here (will not be executed)
}


// Interrupt function to be executed when an overflow takes place in timer 0 register TCNT0
ISR(__vector_11) // Timer/Counter0 Overflow vector no. (12) - 1
{

TCNT0 = 256-8;
Schedular();

	// flag resets automatically
}
