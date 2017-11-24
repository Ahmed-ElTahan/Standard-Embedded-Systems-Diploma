/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

#include <avr/io.h>
void main (void)
{
	// instructions compiled once
	DDRA = 0b00000001; // define pin A0 as output
	PORTA = 0b00000001; // output 1 on pin A0

	while(1)
	{

	}
}
