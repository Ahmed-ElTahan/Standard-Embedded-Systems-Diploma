/*
 * SLCD_WriteDecimal.c
 *
 *  Created on: Oct 16, 2017
 *      Author: Ahmed A. Eltahan
 */

/*	This c file used to write a decimal number on LCD screen with a predefined max number of digits used.
 *  The function used here object is to separate the decimal number using the divisor concept
 *  and print each one once it's separated on the LCD screen.
 */

#include"HLCD.h" // This header file includes the set of pins selected to connect LCD with MCU and 3 function prototypes above that used to control and display commands and data on LCD screen, repectively
#include"SLCD_WriteDecimal.h" // This header file contains the function prototype of that to be used in order to a wite decimal number on LCD screen with a predefined max number of digits used.

LCD_vidWriteDecimal(s64 x)
{
	s64 y = x; // copy the number to y in order to get the first number using division and divisor
	s64 z = x; // copy the number to z in order to save the other digits (leave the first) using modulus and divisor
	s64 divisor = 1; // initially
	u8 i;  // counter
	u8 fns = 0; // condition to check zero first numbers
	for(i=1; i<digits; i++) {divisor *= 10;}; // to specify the counter knowing the number of digits (e.g. 3 digits need divisor of 100)

	// The function separate the decimal number and print each one once it's separated.
	for (i = 1; i<=digits; i++)
	{
		y = (s64) y / divisor; // get the first number and neglect the others
		z = (s64) z % divisor; // get the rest of the number digits (leave the first) for the next as its first will be taken in y next loop
		divisor = divisor / 10; // make the divisor smaller by 10 because the number of the digits has decreased by one
		if(y == 0 && fns == 0) // check if the first numbers are zero
		{
			y = z; // save the rest of the number to y as is its first number will be separated next loop after the current loop iteration is skipped
			continue; // leave the current loop iteration as the first number is zero
		}

		else
		{
			fns = digits; // in order if there is inner zero not to enter the above if condition (put fns = digits to be ensure that the last zero to be condistered)
			// writing ascci to LCD is as : 0 --> 0x48, 1 --> 0x49 ... so get the decimal number and add it to 48 to send it to the LCD as it understands ascci
			LCD_vidwriteData( y + 48 ); // write the value of y (first number of the current decimal number) to the LCD screen. This function is inside the LCD driver (Services layer can freely see HAL layer)
			y = z; // save the rest of the number to y as is its first number will be separated next loop.
		}

	}
}
