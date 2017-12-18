/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

	/*--------------------------------------------------------------------- Program Description -----------------------------------------------------------------------------------------------------------------------------------------------------------------------


	-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();
#include<avr/interrupt.h> // Used to include the interrupt register names in order to use it to start using interrupts

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.


// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds


#define I	7 // global interrupt enable bit (I-bit)



#define OC2PWM_Pin PIN31  // OC2 Pin D7


// User Data Type definition

// Function prototype
ISR(__vector_11); // Timer/Counter0 Overflow. This function is executed when an overflow takes place in timer 0 register TCNT0


// Global variables (Declaration and Initialization)

	u8 Button1State = 1;
	u8 Button2State = 1;
	u8 OCRValue = 12;
	u8 Angle = 90;

// Declared Functions

/* ------------------------ Task 1 --------------------------------*/
	void Init()
	{
		SetPinDirection(0, INPUT_PU); // A0 is pull up input
		SetPinDirection(1, INPUT_PU); // A1 is pull up input
		SetPinDirection(OC2PWM_Pin, OUTPUT); // define OC2 Pin (PWM) pin as output

	}
/* --------------------------------------------------------------- */

/* ------------------------ Task 2 --------------------------------*/
	void DIO()
	{
		if(!GET_BIT(PINA, 0)) // Button1 pressed
		{
			Button1State = 0;
		}
		else if (!GET_BIT(PINA, 1)) // Button2 pressed
		{
			Button2State = 0;
		}
		else
		{
			Button1State = 1;
			Button2State = 1;
		}
	}
/* --------------------------------------------------------------- */

/* ------------------------ Task 3 --------------------------------*/
	void PushButton()
	{
		if(Button1State == 0)
		{
			Angle+=23; if(Angle>180) {Angle = 180;}
			Button1State = 1;
		}
		else if(Button2State == 0)
		{
			Angle-=23; if(Angle<0) {Angle = 0;}
			Button2State = 1;
		}
	}
/* --------------------------------------------------------------- */

/* ------------------------ Task 4 --------------------------------*/
	void Servo()
	{
		OCRValue = (Angle*6)/180 + 7;

	}
/* --------------------------------------------------------------- */

/* ------------------------ Task 5 --------------------------------*/
	void PWM()
	{
		static u8 PreviousOCR = 12;
		if (PreviousOCR != OCRValue)
		{
			OCR2 = OCRValue;
			PreviousOCR = OCRValue;
		}
		else
		{
			OCR2 = OCRValue;
		}
	}
/* --------------------------------------------------------------- */


	// Declared Structures (if Type definition)
	typedef struct
	{
		void (* ptr) (void);
		u16 Periodicity;
		s8 FirstDelay;
	} task;

	task Arr[] = {{Init, 0, 0},  {DIO,150, 0}, {PushButton, 150, 10} , {Servo, 150, 0}, {PWM, 150, 10}}; //

/* ------------------------ Schedular --------------------------------*/
	void Schedular()
	{
		u8 i;
		for (i = 0; i<5; i++) // five tasks
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
/* --------------------------------------------------------------- */





void main(void)
{

	// Module Initialization
		// Timer0 Initialization (for system tick 1ms)
			CLR_BIT(TCCR0, WGM00); // Normal wave generation mode
			CLR_BIT(TCCR0, WGM01); // Normal wave generation mode
			SET_BIT(SREG, I); // global interrupt enable
			SET_BIT(TIMSK, TOIE0); // enable timer0 interrupt
			TCNT0 = 256-8; // initially (1 ms)
			SET_BIT(TCCR0, CS02); CLR_BIT(TCCR0, CS01); SET_BIT(TCCR0, CS00); // Start the timer TCCR0 = 0b00000101; prescaler 1024

		// Timer2 Initialization (for Servo. Fast PWM, 1024 prescaler, OC2 pin high till output compare match, low till overflow)
			SET_BIT(TCCR2, WGM20); // Fast PWM wave generation mode
			SET_BIT(TCCR2, WGM21); // Fast PWM wave generation mode
			SET_BIT(TCCR2, COM21); // Clear OC2 on compare match, set OC2 at BOTTOM
			CLR_BIT(TCCR2, COM20); // Clear OC2 on compare match, set OC2 at BOTTOM
			SET_BIT(TCCR2, CS22); SET_BIT(TCCR2, CS21); SET_BIT(TCCR2, CS20); // Start the timer. prescaler 1024



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
