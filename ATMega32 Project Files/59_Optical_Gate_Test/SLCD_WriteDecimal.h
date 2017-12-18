/*
 * SLCD_WriteDecimal.h
 *
 *  Created on: Oct 16, 2017
 *      Author: Ahmed A. Eltahan
 */


// This header file contains the function prototype of that to be used in order to a wite decimal number on LCD screen with a predefined max number of digits used.
#ifndef SLCD_WRITEDECIMAL_H_
#define SLCD_WRITEDECIMAL_H_

#define digits	5 // maximum number of digits used to be written on the LCD screen

// function prototype
LCD_vidWriteDecimal(s64 x); // function used to write the decimal value on the LCD screen


#endif /* SLCD_WRITEDECIMAL_H_ */
