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
	pin is defined as a pull up resistor input in order to blink an LED pin state connected with C0 once each time it is pressed (using delay).
	ATMega has 3 external interrupts INT0 (D2), INT1 (D3), INT2 (B2). The basic registers used to
	configure the interrupt are:

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

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.


#define LED_ON	1		// LED ON state
#define LED_OFF	0		// LED OFF state


// User-defined #define (Macros: Object / Function)
/*----------------------------------------------- Interrupt Register Macros -----------------------------------------------------------*/
// Defined in interrupts.h
// #define SREG  *(volatile u8*)  (0x5F)
// #define MCUCR *(volatile u8*)  (0x55)
// #define GICR  *(volatile u8*)  (0x5B)
// #define GIFR  *(volatile u8*)  (0x5A)

// MCUCR Register Bit Macros
#define ICS00	0	// config of INT0
#define ICS01	1	// config of INT0
#define ICS10	2	// config of INT1
#define ICS11	3	// config of INT1

// GICR Register Bit Macros
#define INT0	6	// PIN D2
#define INT1	7	// PIN D3
#define INT2	5	// PIN B2

// SREG Register Bit Macro
#define I 	7 // I-bit : Global interrupt enable
/*-------------------------------------------------------------------------------------------------------------------------------------*/

// Used Pins (LED, Switch)
#define LED_Pin PIN16
#define	INT0_Pin PIN26 // D2

// User Data Type definition
// Function prototype
ISR(INT0_vect);

// Declared Structures (if Type definition)
// Declared Functions

// Global variables (Declaration and Initialization)
u8 LED_State = LED_ON; // must be global to pass it as an input to ISR function to toggle the LED state


// Enum


void main(void)
{

	// Declaration and Initialization (executed once)
	SetPinDirection(LED_Pin, OUTPUT);
	SetPinDirection(INT0_Pin, INPUT_PU);
	// Program Variables
		// Pin Direction (Input/Output)
		// Pin Values (initialization)

		// Module Initialization

			/* --------------------------------------------- Interrupt pin INT0 Configuration -----------------------------------------	*/
			// INT0 falling edge interrupt request 1|0, and defined as pull up resistor. so once button is pressed --> interrupt request
			SET_BIT(MCUCR, ICS01);
			CLR_BIT(MCUCR, ICS00);
			// Enable using interrupt pin INT0
			SET_BIT(GICR, INT0);
			// Enable Global Interrupt
			SET_BIT(SREG, I);
			/* ------------------------------------------------------------------------------------------------------------------------- */

	while(1)
	{
		// Write your instructions here.


	}

	// Don't Add anything here (will not be executed)
}


// Function executed on interrupt request (Toggle LED state)
ISR(INT0_vect) // ISR(__vector_1)
{
	// LED ON
	SetPinValue(LED_Pin, HIGH);
	_delay_ms(500);

	// LED OFF
	SetPinValue(LED_Pin, LOW);
	_delay_ms(500);

	// LED ON
	SetPinValue(LED_Pin, HIGH);
	_delay_ms(500);

	// LED OFF
	SetPinValue(LED_Pin, LOW);
	_delay_ms(500);
}

