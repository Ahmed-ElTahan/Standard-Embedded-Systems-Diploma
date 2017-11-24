/*
 * HStepper_Motor.h
 *
 *  Created on: ???/???/????
 *      Author: comp
 */

#ifndef HSTEPPER_MOTOR_H_
#define HSTEPPER_MOTOR_H_

// Directions Clockwise / Counter Clockwise
#define CW 	0
#define CCW 1

// Stepper Motor Pins
#define Blue_Pin 	PIN16
#define Pink_Pin 	PIN17
#define Yellow_Pin 	PIN18
#define Orange_Pin 	PIN19

// Continuous Mode
#define Cont_Mode	0

// Functions Prototypes
void H_vid_StepperMotortInitialize();
void H_vid_SetStepperMotor(char orient, int steps, int delay_time);


#endif /* HSTEPPER_MOTOR_H_ */
