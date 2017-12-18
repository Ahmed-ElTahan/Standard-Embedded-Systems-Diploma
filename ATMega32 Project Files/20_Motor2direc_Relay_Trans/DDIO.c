/*
 * DDIO.c
 *
 *  Created on: Aug 26, 2017
 *      Author: Ahmed A. Eltahan
 */
/*
	  This code contains three functions:
 	  1- Function to set the pin number (0 to 31) direction as Input(floating)/Output/Input(pull up).
  	  Inputs (PinNumber, PinDirection) PinNumber: 0-31, PinDirection:0 for Input (use clear bit), 1 for Output (use set bit) -- no outputs
	  note: first if is to know the port, nested if to set the pin as Input(floating)/Output/Input(pull up).
	  2- Function to set the output of the output pins (0-31)
	  Inputs (PinNumber, PinValue) PinNumber: 0-31, PinValue: 0 for Low, 1 for High -- no outputs
	  3- Function to get the value of the input pin
	  Inputs (PinNumber): 0-31 -- output a u8 output of 0: Low, 1: High

*/
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// Function (1):  to set the pin number (0 to 31) direction as Input(floating)/Output/Input(pull up)
void SetPinDirection(u8 PinNumber, u8 PinDirection)
{
	u8 PortLetter = PinNumber/NUM; // to get the Port letter (0 for A, 1 for B, 2 for C, 3 for D)
	// PinNumber%NUM gives the number of the pin in the port from 0 to 7

	// 0 for port A
		if (PortLetter == PortA_Letter)
		{
			//DDRA
			if (PinDirection == INPUT) // Input (floating)
			{
				CLR_BIT(DDRA, PinNumber%NUM);
			}
			else if (PinDirection == OUTPUT) // Output
			{
				SET_BIT(DDRA, PinNumber%NUM);
			}
			else if (PinDirection == INPUT_PU)
			{
				CLR_BIT(DDRA, PinNumber%NUM); // define as input
				SET_BIT(PORTA, PinNumber%NUM); // write high to be Input (pull up)
			}
		}

	// 1 for port B
		else if (PortLetter == PortB_Letter)
		{
			//DDRB
			if (PinDirection == INPUT) // Input (floating)
			{
				CLR_BIT(DDRB, PinNumber%NUM);
			}
			else if (PinDirection == OUTPUT) // Output
			{
				SET_BIT(DDRB, PinNumber%NUM);
			}
			else if (PinDirection == INPUT_PU)
			{
				CLR_BIT(DDRB, PinNumber%NUM); // define as input
				SET_BIT(PORTB, PinNumber%NUM); // write high to be Input (pull up)
			}
		}

	// 2 for port C
		else if (PortLetter == PortC_Letter)
		{
			//DDRC
			if (PinDirection == INPUT) // Input (floating)
			{
				CLR_BIT(DDRC, PinNumber%NUM);
			}
			else if (PinDirection == OUTPUT) // Output
			{
				SET_BIT(DDRC, PinNumber%NUM);
			}
			else if (PinDirection == INPUT_PU)
			{
				CLR_BIT(DDRC, PinNumber%NUM); // define as input
				SET_BIT(PORTC, PinNumber%NUM); // write high to be Input (pull up)
			}
		}

	// 3 for port D
		else if (PortLetter == PortD_Letter)
		{
			//DDRA
			if (PinDirection == INPUT) // Input (floating)
			{
				CLR_BIT(DDRD, PinNumber%NUM);
			}
			else if (PinDirection == OUTPUT) // Output
			{
				SET_BIT(DDRD, PinNumber%NUM);
			}
			else if (PinDirection == INPUT_PU)
			{
				CLR_BIT(DDRD, PinNumber%NUM); // define as input
				SET_BIT(PORTD, PinNumber%NUM); // write high to be Input (pull up)
			}
		}

}

// Function (2): to set the output of the output pins (0-31)
void SetPinValue(u8 PinNumber, u8 PinValue)
{
	u8 PortLetter = PinNumber/NUM; // to get the Port letter (0 for A, 1 for B, 2 for C, 3 for D)
	// PinNumber%NUM gives the number of the pin in the port from 0 to 7


	if (PortLetter == PortA_Letter) // 0 for port A
	{
		//PORTA
		if (PinValue == LOW) // Low
		{
			CLR_BIT(PORTA, PinNumber%NUM);
		}
		else if (PinValue == HIGH) // High
		{
			SET_BIT(PORTA, PinNumber%NUM);
		}
	}

	else if (PortLetter == PortB_Letter) // 1 for port B
	{
		//PORTB
		if (PinValue == LOW) // Low
		{
			CLR_BIT(PORTB, PinNumber%NUM);
		}
		else if (PinValue == HIGH) // High
		{
			SET_BIT(PORTB, PinNumber%NUM);
		}
	}


	else if (PortLetter == PortC_Letter) // 2 for port C
	{
		//PORTC
		if (PinValue == LOW) // Low
		{
			CLR_BIT(PORTC, PinNumber%NUM);
		}
		else if (PinValue == HIGH) // High
		{
			SET_BIT(PORTC, PinNumber%NUM);
		}
	}

	else if (PortLetter == PortD_Letter) // 3 for port D
	{
		//PORTD
		if (PinValue == LOW) // Low
		{
			CLR_BIT(PORTD, PinNumber%NUM);
		}
		else if (PinValue == HIGH) // High
		{
			SET_BIT(PORTD, PinNumber%NUM);
		}
	}
}



// Fucntion (3): to get the value of the input pin
u8 GetPinValue(u8 PinNumber) // return the value of pin 0 - 31
{
	u8 PortLetter = PinNumber/NUM; // to get the Port letter (0 for A, 1 for B, 2 for C, 3 for D)
	// PinNumber%NUM gives the number of the pin in the port from 0 to 7

	if (PortLetter == PortA_Letter) // 0 for port A
	{
		//PINA
		return GET_BIT(PINA, PinNumber%NUM);
	}
	else if (PortLetter == PortB_Letter) // 1 for port B
	{
		//PINB
		return GET_BIT(PINB, PinNumber%NUM);
	}

	else if (PortLetter == PortC_Letter) // 2 for port C
	{
		//PINC
		return GET_BIT(PINC, PinNumber%NUM);
	}

	else if (PortLetter == PortD_Letter) // 3 for port D
	{
		//PIND
		return GET_BIT(PIND, PinNumber%NUM);
	}
}

