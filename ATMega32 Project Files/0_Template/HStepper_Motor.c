/*
 * HStepper_Motor.c
 *
 *  Created on: ???/???/????
 *      Author: comp
 */
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HStepper_Motor.h"

void H_vid_StepperMotortInitialize()
{
	// Set Motor Pins as output
	SetPinDirection(Blue_Pin, OUTPUT); 		// Blue
	SetPinDirection(Pink_Pin, OUTPUT); 		// Pink
	SetPinDirection(Yellow_Pin, OUTPUT); 	// Yellow
	SetPinDirection(Orange_Pin, OUTPUT); 	// Orange

	// Initialize the pins with zeros (no motion)
	SetPinValue(Blue_Pin, LOW);		// Blue
	SetPinValue(Pink_Pin, LOW);		// Pink
	SetPinValue(Yellow_Pin, LOW);	// Yellow
	SetPinValue(Orange_Pin, LOW);	// Orange
}

void H_vid_SetStepperMotor(char orient, int steps, int delay_time)
{

	if (!Cont_Mode) // Stepping Mode (enter steps)
	{
		switch(orient) // check orientation CW or CCW
		{
			case CW:
			break;

			case CCW:
			break;
		}
	}


	else // Continuous Mode (keep rotating)
	{
		switch(orient) // check orientation CW or CCW
		{
			case CW:
			break;

			case CCW:
			break;
		}
	}


}
