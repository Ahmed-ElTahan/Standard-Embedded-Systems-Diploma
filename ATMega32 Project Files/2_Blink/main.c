/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */


#include <avr/io.h>

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside the delay.h which defines the frequency used.
#include <avr/delay.h> // to add the delay functions


void main (void)
{
	// instructions compiled once
	DDRA = 0b00000001; // define pin A0 as output
	PORTA = 0b00000000; // output 0 on pin A0 (ensure)

	while(1)
	{
		PORTA = 0b00000001; // output 1 on pin A0
		_delay_ms(1000); // pause for 1000 ms. = 1 sec.
		PORTA = 0b00000000; // output 0 on pin A0
		_delay_ms(1000); // pause for 1000 ms. = 1 sec.
	}
}
