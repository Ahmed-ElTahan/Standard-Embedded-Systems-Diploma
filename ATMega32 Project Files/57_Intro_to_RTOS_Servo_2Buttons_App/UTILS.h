/*
 * UTILS.h
 *
 *  Created on: Aug 26, 2017
 *      Author: Ahmed A. Eltahan
 */

// Using macrod will save the other pin modes (output/input), state (HIGH/LOW). Only set/get/clear/toggle desired pin
#ifndef UTILS_H_
#define UTILS_H_

// User-defined header files #define (Macros: Object / Function)
#define SET_BIT(REGISTER, BIT_NUMBER)	(REGISTER |= ( 1 << BIT_NUMBER ))  			// set bit #BIT_NUMBER of register REGISTER
#define CLR_BIT(REGISTER, BIT_NUMBER)	(REGISTER &= ( ~ ( 1 << BIT_NUMBER )))  	// clear bit #BIT_NUMBER of register REGISTER
#define TOG_BIT(REGISTER, BIT_NUMBER)	(REGISTER ^= ( 1 << BIT_NUMBER ))  			// toggle bit #BIT_NUMBER of register REGISTER
#define GET_BIT(REGISTER, BIT_NUMBER)	((REGISTER >> BIT_NUMBER) & 1)				// get the value of bit #BIT_NUMBER of register REGISTER

#endif /* UTILS_H_ */
