/*
 * HSeven_Segment_DDIO.c
 *
 *  Created on: Aug 27, 2017
 *      Author: Ahmed A. Eltahan
 */

/* This c file is used to show number on the seven segment HW  using a function SevSeg_ShowNumber(int i)
 where i is the number wanted to be shown, SPN: Starting Pin Number (0-31).This function uses DDIO functions
 as SetPinValue, SetPinDirections to set values on the pins according the down table and to set pins as Outputs, and
 EN_PIN: the pin chosen to be the output high for the power of the sev seg.
 Note: Connect 1st pin of the seven segment to any pin number and then go orderly with 7 pins after it.
	   ex. 1st sev. seg. pin (SPN) is connected to pin no. 10, then connect 2nd, 3rd,...,8th pins to pin nos. 11, 12,...,17

	number 			binary				decimal			sevseg[]
	0				10100000			160				sevseg[0]
	1				11111001			249				sevseg[1]
	2				11000100			196				sevseg[2]
	3				11010000			208				sevseg[3]
	4				10011001			153				sevseg[4]
	5				10010010			146				sevseg[5]
	6				10000010			130				sevseg[6]
	7				11111000			248				sevseg[7]
	8				10000000			128				sevseg[8]
	9				10010000			144				sevseg[9]
	dot				01111111			127				sevseg[10]

*/

#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HSeven_Segment_DDIO.h" // This Header file includes the function prototype of SevSeg_ShowNumber(int i) function and selection of SPN and EN_PIN

void SevSeg_ShowNumber(int i)
{
	// Declare Seven segment pins as output
	SetPinDirection(SPN+0, OUTPUT); SetPinDirection(SPN+1, OUTPUT); SetPinDirection(SPN+2, OUTPUT); SetPinDirection(SPN+3, OUTPUT);
	SetPinDirection(SPN+4, OUTPUT); SetPinDirection(SPN+5, OUTPUT); SetPinDirection(SPN+6, OUTPUT); SetPinDirection(SPN+7, OUTPUT);

	// Declare a pin for the power of the seven segment to be output high
	SetPinDirection(EN_PIN, OUTPUT);
	SetPinValue(EN_PIN, HIGH);

	switch (i)
	{
		case 0: // number 0
		SetPinValue(SPN+0, 0); SetPinValue(SPN+1, 0); SetPinValue(SPN+2, 0); SetPinValue(SPN+3, 0);
		SetPinValue(SPN+4, 0); SetPinValue(SPN+5, 1); SetPinValue(SPN+6, 0); SetPinValue(SPN+7, 1);
		break;

		case 1: // number 1
		SetPinValue(SPN+0, 1); SetPinValue(SPN+1, 0); SetPinValue(SPN+2, 0); SetPinValue(SPN+3, 1);
		SetPinValue(SPN+4, 1); SetPinValue(SPN+5, 1); SetPinValue(SPN+6, 1); SetPinValue(SPN+7, 1);
		break;

		case 2: // number 2
		SetPinValue(SPN+0, 0); SetPinValue(SPN+1, 0); SetPinValue(SPN+2, 1); SetPinValue(SPN+3, 0);
		SetPinValue(SPN+4, 0); SetPinValue(SPN+5, 0); SetPinValue(SPN+6, 1); SetPinValue(SPN+7, 1);
		break;

		case 3: // number 3
		SetPinValue(SPN+0, 0); SetPinValue(SPN+1, 0); SetPinValue(SPN+2, 0); SetPinValue(SPN+3, 0);
		SetPinValue(SPN+4, 1); SetPinValue(SPN+5, 0); SetPinValue(SPN+6, 1); SetPinValue(SPN+7, 1);
		break;

		case 4: // number 4
		SetPinValue(SPN+0, 1); SetPinValue(SPN+1, 0); SetPinValue(SPN+2, 0); SetPinValue(SPN+3, 1);
		SetPinValue(SPN+4, 1); SetPinValue(SPN+5, 0); SetPinValue(SPN+6, 0); SetPinValue(SPN+7, 1);
		break;

		case 5: // number 5
		SetPinValue(SPN+0, 0); SetPinValue(SPN+1, 1); SetPinValue(SPN+2, 0); SetPinValue(SPN+3, 0);
		SetPinValue(SPN+4, 1); SetPinValue(SPN+5, 0); SetPinValue(SPN+6, 0); SetPinValue(SPN+7, 1);
		break;

		case 6: // number 6
		SetPinValue(SPN+0, 0); SetPinValue(SPN+1, 1); SetPinValue(SPN+2, 0); SetPinValue(SPN+3, 0);
		SetPinValue(SPN+4, 0); SetPinValue(SPN+5, 0); SetPinValue(SPN+6, 0); SetPinValue(SPN+7, 1);
		break;

		case 7: // number 7
		SetPinValue(SPN+0, 0); SetPinValue(SPN+1, 0); SetPinValue(SPN+2, 0); SetPinValue(SPN+3, 1);
		SetPinValue(SPN+4, 1); SetPinValue(SPN+5, 1); SetPinValue(SPN+6, 1); SetPinValue(SPN+7, 1);
		break;

		case 8: // number 8
		SetPinValue(SPN+0, 0); SetPinValue(SPN+1, 0); SetPinValue(SPN+2, 0); SetPinValue(SPN+3, 0);
		SetPinValue(SPN+4, 0); SetPinValue(SPN+5, 0); SetPinValue(SPN+6, 0); SetPinValue(SPN+7, 1);
		break;

		case 9: // number 9
		SetPinValue(SPN+0, 0); SetPinValue(SPN+1, 0); SetPinValue(SPN+2, 0); SetPinValue(SPN+3, 0);
		SetPinValue(SPN+4, 1); SetPinValue(SPN+5, 0); SetPinValue(SPN+6, 0); SetPinValue(SPN+7, 1);
		break;

		case 10: // dot
		SetPinValue(SPN+0, 1); SetPinValue(SPN+1, 1); SetPinValue(SPN+2, 1); SetPinValue(SPN+3, 1);
		SetPinValue(SPN+4, 1); SetPinValue(SPN+5, 1); SetPinValue(SPN+6, 1); SetPinValue(SPN+7, 0);
		break;
	}
}
