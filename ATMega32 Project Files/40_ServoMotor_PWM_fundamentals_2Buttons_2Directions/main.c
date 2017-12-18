/*
 * main.c
 *
 *  Created on: Aug 19, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
	----------------------------- Program Description -----------------------------------------
	Programming Project by USBasp kit using AVR Dude to:
	Use 2 push buttons in order to stepwise the servo motor steps. One to increment and the other to decrement.
	A function used to send the required signal to position the servo called Servo_Write_us(u16 T_on) which takes the HIGH level period T_on

*/

// Libraries

#define F_CPU 8000000 // to define the crystal value (frequency used to set the time correctly). F_CPU is the variable inside delay.h which defines the frequency used.
#include<avr/delay.h> // Convenience functions for busy-wait delay loops: milliseconds: _delay_ms();, microseconds: _delay_us();

// User-defined header files #include
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.

// User-defined #define (Macros: Object / Function)
#define delay_ms 500 // delay duration milliseconds

#define ServoMotor_Pin PIN0   // Servo motor signal pin
#define ServoMotorEN_Pin PIN1 // Servo motor enable pin (NPN 2N2222 switching)
#define Button1_Pin PIN2      // Push button 1 A2
#define Button2_Pin PIN3      // Push button 2 A3


// User Data Type definition

// Function prototype
void Servo_Write_us(u16 T_on); // used to write the required signal to the servo motor
void Check_Value_Written(u16* Value_Written); // Used to write the signal required to the servo


// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Initialization)
// Enum

void main(void)
{
	// Declaration and Initialization (executed once)
	SetPinDirection(ServoMotor_Pin, OUTPUT); // Output servo signal pin A0
	SetPinDirection(ServoMotorEN_Pin, OUTPUT); // Output Enable pin A1
	SetPinDirection(Button1_Pin, INPUT_PU); // Input pull up resistor A2
	SetPinDirection(Button2_Pin, INPUT_PU); // Input pull up resistor A3

	SetPinValue(ServoMotorEN_Pin, HIGH); // enable servo motor
		// Program Variables
		u8 Button1 = 1; // initial default value pull up resistor
		u8 Button2 = 1; // initial default value pull up resistor
		u8 step = 100; // used for specifying the step to increment or decrement

		u16 Value_Written = 1000; // nominal value

		// Pin Direction (Input/Output)
		// Pin Values (initialization)
		// Module Initialization_delay_us(1500);
		//Servo_Write_us(1000); // initially



	while(1)
	{
		// Write your instructions here.
		// get the push buttons values
		Button1 = GetPinValue(Button1_Pin);
		Button2 = GetPinValue(Button2_Pin);

		// check if any pressed

			// Increment
			if (Button1 == LOW)
			{
				//_delay_ms(250); // for debouncing
				Value_Written += 100;
				Check_Value_Written(&Value_Written);
				Servo_Write_us(Value_Written);
			}

			// Decr-ement
			if (Button2 == LOW)
			{
				//_delay_ms(250); // for debouncing
				Value_Written -= 100;
				Check_Value_Written(&Value_Written);
				Servo_Write_us(Value_Written);
			}

		// Anyway, write the current value to the servo
	    Servo_Write_us(Value_Written);

		//while(Button1 == HIGH && Button2 == HIGH)
	}

	// Don't Add anything here (will not be executed)
}

// Used to write the signal required to the servo
void Servo_Write_us(u16 T_on)
{
	SetPinValue(ServoMotor_Pin, HIGH);
	_delay_us(T_on);

	SetPinValue(ServoMotor_Pin, LOW);
	_delay_us(20000 - T_on);
}

// Used to limit the vlue written to the servo between (1000 - 2000)
void Check_Value_Written(u16* Value_Written)
{
	if (*Value_Written < 1000) *Value_Written = 1000;
	if (*Value_Written > 2000) *Value_Written = 2000;
}

