/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

#include <avr/io.h>

#define F_CPU 16000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside the delay.h which defines the frequency used.
#include <avr/delay.h> // to add the delay functions


void main (void)
{
	// instructions compiled once
	int i; // counter
	DDRA = 0b11111111; // define pins PORTA pins as output
	PORTA = 0b00000000; // output 0 on PORTA pins (ensure)

	while(1)
	{
		for (i=0; i<=255; i++)
		{
			PORTA = i; // output i on PORTA (put all possibilities on the leds from 00000000 to 11111111)
			_delay_ms(1000); // pause for 1000 ms. = 1 sec.
		}
	}
}
