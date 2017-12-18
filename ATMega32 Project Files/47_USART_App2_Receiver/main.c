/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Configure USART peripheral (Receiver Code)

*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay)_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

// User Data Type definition

// Function prototype
void USART_vidSendData(u8 data); // send data through USART
u8 USART_u8ReceiveData(void); // receive data from UART

// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum
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
#define ServoMotorEn PIN1 // A1 to enable servo motor

/* ---------------------------  UART Registers' IO Adresses and Bits Macros  ------------------------------- */

// UART Registers' IO Adresses
#define UCSRA *(u8 * volatile) 0x2B // USART Control and Status Register A
#define UCSRB *(u8 * volatile) 0x2A // USART Control and Status Register B
#define UCSRC *(u8 * volatile) 0x40 // USART Control and Status Register C
#define UBRRH *(u8 * volatile) 0x40 // USART Buadrate Register High
#define UBRRL *(u8 * volatile) 0x29 // USART Buadrate Register LOW
#define UDR   *(u8 * volatile) 0x2C // USART IO Data Register

// UCSRA Bits
#define RXC		7 // Receive complete flag bit
#define TXC 	6 // Transmission complete flag bit
#define UDRE	5 // Empty data register flag bit
#define FE		4 // Frame error flag bit
#define DOR		3 // Data overrun flag bit
#define PE		2 // Polarity error flag
#define U2X		1 // Double speed mode bit
#define MPCM	0 // Multiprocessor communication mode bia

// UCSRB Bits
#define RXCIE	7 // Receive complete interrupt enable
#define TXCIE	6 // Transmission complete interrupt enable
#define UDRIE	5 // Empty data register interrupt enable
#define RXEN	4 // Receiving mode enable
#define TXEN	3 // Transmitting mode enable
#define UCSZ2	2 // Used with UCSZ1 and UCSZ0 to select the number of data bits (5,6,7,8,9)
#define RXB8	1 // ninth received bit if select data register 9 bits (1 + 8 UDR)
#define TXB8	0 // ninth transimitted bit if select data register 9 bits (1 + 8 UDR)

// UCSRC Bits
#define URSEL	7 // Used to select accessing UCSRC or UBRRH
#define UMSEL	6 // Used to select: Async or Sync mode
#define UPM1	5 // Used to select parity mode
#define UPM0	4 // Used to select parity mode
#define USBS	3 // Used to select number of bits of stop bits (1 or 2)
#define UCSZ1	2 // Used with UCSZ2 and UCSZ0 to select the number of data bits (5,6,7,8,9)
#define UCSZ0	1 // Used with UCSZ2 and UCSZ1 to select the number of data bits (5,6,7,8,9)
#define UCPOL	0 // Used to select clock polarity (FE or RE)

// UBRRH and UBRRL (UBRR 12) Bits
#define UBRR11		11 // UBRRH bit 3 --> Used to select the baudrate
#define UBRR10		10 // UBRRH bit 2 --> Used to select the baudrate
#define UBRR9		9  // UBRRH bit 1 --> Used to select the baudrate
#define UBRR8		8  // UBRRH bit 0 --> Used to select the baudrate
#define UBRR7		7  // UBRRL bit 7 --> Used to select the baudrate
#define UBRR6		6  // UBRRL bit 6 --> Used to select the baudrate
#define UBRR5		5  // UBRRL bit 5 --> Used to select the baudrate
#define UBRR4		4  // UBRRL bit 4 --> Used to select the baudrate
#define UBRR3		3  // UBRRL bit 3 --> Used to select the baudrate
#define UBRR2		2  // UBRRL bit 2 --> Used to select the baudrate
#define UBRR1		1  // UBRRL bit 1 --> Used to select the baudrate
#define UBRR0		0  // UBRRL bit 0 --> Used to select the baudrate

// Flags
#define TransCompFlag		GET_BIT(UCSRA, TXC)  // transmission complete flag value
#define ReceivCompFlag		GET_BIT(UCSRA, RXC)  // receive complete flag value
#define DataRegEmptyFlag	GET_BIT(UCSRA, UDRE) // empty data register flag value

/* ------------------------------------------------------------------------------------------------------------ */



void main(void)
{
	// Declaration and Initialization (executed once)
		// Program Variables
		u8 data; // used to store the input serial data

		// Pin Direction (Input/Output)
		// Pin Values (initialization)

		// Module Initialization

			// Timers Initialization (Fast PWM, 1024 prescaler, OC0 pin high till output compare match, low till overflow)
				SET_BIT(TCCR0, WGM00); // Fast PWM wave generation mode
				SET_BIT(TCCR0, WGM01); // Fast PWM wave generation mode
				SET_BIT(TCCR0, COM01); // Clear OC0 on compare match, set OC0 at BOTTOM
				CLR_BIT(TCCR0, COM00); // Clear OC0 on compare match, set OC0 at BOTTOM

				SET_BIT(TCCR0, CS02); CLR_BIT(TCCR0, CS01); SET_BIT(TCCR0, CS00); // Start the timer. prescaler 1024

				OCR0 = 10; // initially, value between (7.8125 and 15.625) (-90 and 90 degree)


			// UART Initialization

				// UCSRA

				// UCSRB
					SET_BIT(UCSRB, RXEN); // enable receiving mode
					SET_BIT(UCSRB, TXEN); // enable transmission mode

				// UCSRC
					CLR_BIT(UCSRC, UMSEL); // Select Async mode
					CLR_BIT(UCSRC, UPM1); // Select no polarity mode
					CLR_BIT(UCSRC, UPM0); // Select no polarity mode
					CLR_BIT(UCSRC, USBS); // Select 1 stop bit
					SET_BIT(UCSRC, UCSZ1); // Select 8 data bit
					SET_BIT(UCSRC, UCSZ0); // Select 8 data bit

				// UBRRH

				// UBRRL
					UBRRL = 51; // slect 9600 baudrate

				// Initialization of DDIO (LEDs)
					SetPinDirection(PIN0, OUTPUT); // LED1 A0

					SetPinDirection(OC0PWM_Pin, OUTPUT); // define OC0 Pin (PWM) pin as output
					SetPinDirection(ServoMotorEn, OUTPUT); // Output Enable pin A1


	while(1)
	{
		// Write your instructions here.
		data = USART_u8ReceiveData();
		if (data >= 7 && data < 17)
		{
			OCR0 = data;
			SetPinValue(PIN0, LOW);
		}
		else
		{
			USART_vidSendData('E'); // error
			SetPinValue(PIN0, HIGH);
		}
	}

	// Don't Add anything here (will not be executed)
}

void USART_vidSendData(u8 data)
{
	//while(DataRegEmptyFlag == 0); // wait if there are data in the data register UDR
	UDR = data; // write data on the data register UDR
	while(TransCompFlag == 0); // wait till transmission completes
	SET_BIT(UCSRA, TXC); // reset the flag
}

u8 USART_u8ReceiveData(void)
{
	u8 data;
	while(ReceivCompFlag == 0); // wait till the data are received from the transmitter
	data = UDR; // get the data from the data regeister UDR
	SET_BIT(UCSRA, RXC); // reset the flag (not needed)

	return data;
}
