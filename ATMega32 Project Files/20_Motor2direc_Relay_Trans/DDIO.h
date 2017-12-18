/*
 * DDIO.h
 *
 *  Created on: Aug 26, 2017
 *      Author: Ahmed A. Eltahan
 */
/*	DDIO: Driver Digital Input/Output
 	This is the header file of DDIO that contains:
 	1- the macros to define Ports' registers, Input(floating)/Output/Input(pull up) pin state, HIGH/LOW pin output
 	2- function prototypes to set pin direction, set pin value, and get pin value
 	Notes:
 	1- Port A, B, C, D registers (DDR_, PORT_, PIN_) are addresses in the memory space that the MCU deals with them as addresses
 	2- Port A, B, C, D registers' addresses (DDR_, PORT_, PIN_) are included in order not to include avr/io.h as I am creating my DIO
 	3- Pins of ports A, B, C, D are replaced by numbers from 0 to 31.
 	   A[0 1 2 3 4 5 6 7], B[8 9 10 11 12 13 14 15], C[16 17 18 19 20 21 22 23], D[24 25 26 27 28 29 30 31].
 	4- Given the pin number, we can know the Port Letter by dividing pin number on 8 and take the real number.
 	   A [(0 to 7)/8 real number = 0], B [(8 to 15)/8 real number = 1], C [(16 to 23)/8 real number = 2], D [(24 to 31)/8 real number = 3]
	5- Given the pin number, we can know the pin number of the port (0 to 7) by getting the rest of the division of pin number on 8 (pin number%8)
	   ex. pin number 6, port = real(6/8) = 0 --> port A, pin = 6%8 = 6 so its A6
	   ex. pin number 18, port = real(18/8) = 2 --> port C, pin = 18%8 = 2 so its C2
*/
// Header file guards
#ifndef DDIO_H_
#define DDIO_H_

#include"STD_TYPES.h" // To include user defined data types (u8, u16 ... f96)
#include"UTILS.h" // To include set/toggle/clear/get bit function macros

// Port A Registers
#define DDRA  (* (volatile u8 *) (0x3A))
#define PORTA (* (volatile u8 *) (0x3B))
#define PINA  (* (volatile u8 *) (0x39))

// Port B Registers
#define DDRB  (* (volatile u8 *) (0x37))
#define PORTB (* (volatile u8 *) (0x38))
#define PINB  (* (volatile u8 *) (0x36))

// Port C Registers
#define DDRC  (* (volatile u8 *) (0x34))
#define PORTC (* (volatile u8 *) (0x35))
#define PINC  (* (volatile u8 *) (0x33))

// Port D Registers
#define DDRD  (* (volatile u8 *) (0x31))
#define PORTD (* (volatile u8 *) (0x32))
#define PIND  (* (volatile u8 *) (0x30))

// Port Letter
#define PortA_Letter 0
#define PortB_Letter 1
#define PortC_Letter 2
#define PortD_Letter 3

// Pin Numbers
#define PIN0	0
#define PIN1	1
#define PIN2	2
#define PIN3	3
#define PIN4	4
#define PIN5	5
#define PIN6	6
#define PIN7	7
#define PIN8	8
#define PIN9	9
#define PIN10	10
#define PIN11	11
#define PIN12	12
#define PIN13	13
#define PIN14	14
#define PIN15	15
#define PIN16	16
#define PIN17	17
#define PIN18	18
#define PIN19	19
#define PIN20	20
#define PIN21	21
#define PIN22	22
#define PIN23	23
#define PIN24	24
#define PIN25	25
#define PIN26	26
#define PIN27	27
#define PIN28	28
#define PIN29	29
#define PIN30	30
#define PIN31	31


// Used to set the pin direction
#define INPUT 		0	// Floating Input
#define OUTPUT 		1
#define INPUT_PU	2	// Pull up Input

// Used to set the value of the pin
#define HIGH 		1
#define LOW 		0

// Used to determine the Port Letter and Pin number in the port
#define NUM 		8


// function prototypes
void SetPinDirection(u8 PinNumber, u8 PinDirection); // set pin 0 - 31 as input/output
void SetPinValue(u8 PinNumber, u8 PinValue); // set the output pin 0 - 31 to high/low
u8 GetPinValue(u8 PinNumber); // return the value of the input pin 0 - 31 high/low


#endif /* DDIO_H_ */
