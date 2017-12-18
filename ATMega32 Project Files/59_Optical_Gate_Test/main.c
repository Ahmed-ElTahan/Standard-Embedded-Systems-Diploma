/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Introduce using interrupts. This code is using external interrupt pin INT0 (D2) connected with push button which the input INT0
	pin is defined as a pull up resistor input in order to enlighten a LED pin state connected with C0. ATMega has 3 external interrupts
	INT0 (D2), INT1 (D3), INT2 (B2). The basic registers used to configure the interrupt are:

	1- MCU Control Register (MCUCR):
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

	2- MCU Control and Status Register (MCUSR)
		Used for using INT2 (B2) interrupt pin (Special case interrupt)

	3- General Interrupt Control Register (GICR)
		configurable bits:
								bit7		bit6		bit5
								INT1		INT0		INT2
		bit description:
			I-   External Interrupt Request 1 Enable (INT1): Set it to enable using INT1
			II-  External Interrupt Request 0 Enable (INT0): Set it to enable using INT0
			III- External Interrupt Request 2 Enable (INT2): Set it to enable using INT2

	5- General Interrupt Flag Register (GIFR)
		configurable bits:
								bit7		bit6		bit5
								INTF1		INTF0		INTF2
		bit description:
			I-   External Interrupt Flag 1 (INTF1): When signal triggers interrupt request, it is set to one (automatically). After the interrupt function finishes, it returns one. Don't forget to clear the flag at the end of the ISR function in order to response to other interrupts and clearing it is by setting it to 1
			II-  External Interrupt Flag 0 (INTF0): When signal triggers interrupt request, it is set to one (automatically). After the interrupt function finishes, it returns one. Don't forget to clear the flag at the end of the ISR function in order to response to other interrupts and clearing it is by setting it to 1
			III- External Interrupt Flag 2 (INTF2): When signal triggers interrupt request, it is set to one (automatically). After the interrupt function finishes, it returns one. Don't forget to clear the flag at the end of the ISR function in order to response to other interrupts and clearing it is by setting it to 1

	6- Status Register (SREG):
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

*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();
#include<avr/interrupt.h> // Used to include the interrupt register names in order to use it to start using interrupts
#include<avr/timers.h>

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds


/*----------------------------------------------- Interrupt Register Macros -----------------------------------------------------------*/
// Defined in interrupts.h
// #define SREG  *(volatile u8*)  (0x5F)
// #define MCUCR *(volatile u8*)  (0x55)
// #define GICR  *(volatile u8*)  (0x5B)
// #define GIFR  *(volatile u8*)  (0x5A)

// MCUCR Register Bit Macros
#define ICS00	0	// config of INT0
#define ICS01	1	// config of INT0

// GICR Register Bit Macros
#define INT0	6	// PIN D2


// SREG Register Bit Macro
#define I 	7 // I-bit : Global interrupt enable
/*-------------------------------------------------------------------------------------------------------------------------------------*/
// One Second
#define OneSecCounts_1024      31 // to check the number of loops
#define OneSecInitTCNT0_1024  256-133 // to match the partial number of the part of a count (non full overflow)


// Used Pins (LED, Switch)
#define	INT0_Pin PIN26  // D2

	// User Data Type definition

	// Function prototype
		ISR(INT0_vect); // Function executed on interrupt request
		ISR(__vector_11); // Timer/Counter0 Overflow. This function is executed when an overflow takes place in timer 0 register TCNT0

	// Declared Structures (if Type definition)
	// Declared Functions

	// Global variables (Declaration and Initialization)
		s64 counter=0;
		u8 flag =1;
		s64 rpm  = 0;
		s64 overflow = 0;
	// Enum


void main(void)
{

	// Declaration and Initialization (executed once)
	SetPinDirection(INT0_Pin, INPUT_PU); // Push button input pull up resistor declaration

		// Program Variables
		// Pin Direction (Input/Output)
		// Pin Values (initialization)
		// Module Initialization

			LCD_vidInit(); // Initialize the LCD


				/* --------------------------------------------- Interrupt pin INT0 Configuration -----------------------------------------	*/
				// INT0 rising edge interrupt request 1|1 (Optical Sensor)
				SET_BIT(MCUCR, ICS01);
				SET_BIT(MCUCR, ICS00);
				// Enable using interrupt pin INT0
				SET_BIT(GICR, INT0);
				// Enable Global Interrupt
				SET_BIT(SREG, I);
				/* ------------------------------------------------------------------------------------------------------------------------- */
			// Timers Initialization
					CLR_BIT(TCCR0, WGM00); // Normal wave generation mode
					CLR_BIT(TCCR0, WGM01); // Normal wave generation mode
					SET_BIT(SREG, I); // global interrupt enable
					SET_BIT(TIMSK, TOIE0); // enable timer0 interrupt
					TCNT0 = OneSecInitTCNT0_1024; // initially for the fractional part for 1 second
					SET_BIT(TCCR0, CS02); CLR_BIT(TCCR0, CS01); SET_BIT(TCCR0, CS00); // Start the timer TCCR0 = 0b00000101; prescaler 1024

	while(1)
	{
		// Write your instructions here.
		if(flag == 1)
			{
			LCD_vidwriteCommand(1); // clear screen
			LCD_vidwriteCommand(0b10000000); // go to the start of the first line
			LCD_vidwriteData('R'); LCD_vidwriteData('P'); LCD_vidwriteData('M'); LCD_vidwriteData('=');LCD_vidwriteData(' ');
			LCD_vidWriteDecimal(rpm);
			flag = 0;
			}

	}

	// Don't Add anything here (will not be executed)
}

// Function executed on interrupt request (Toggle LED state)
ISR(INT0_vect) // ISR(__vector_1)
{
	counter++;
}

ISR(__vector_11) // Timer/Counter0 Overflow vector no. (12) - 1
{
	if(overflow == OneSecCounts_1024)
	{
	rpm = counter*60/12;
	counter = 0; 	flag = 1; overflow = 0; TCNT0 = OneSecInitTCNT0_1024;
	}
	else
	{
		overflow++;
	}

}
