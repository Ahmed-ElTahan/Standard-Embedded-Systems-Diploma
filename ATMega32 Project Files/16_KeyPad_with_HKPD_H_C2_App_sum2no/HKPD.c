/*
 * HKPD.c
 *
 *  Created on: Sep 9, 2017
 *      Author: Ahmed A. Eltahan
 */
/*
 * This c File contains:
 * 	1- the keypad multi-dimension array KPD_au8Keys that contains key values (these values are used to know which button is pressed then can print anything other in the main file when needed)
 *  2- void KPD_vidInit(void); // used to set the keypad connected pins as inputs pulled up (Rows) and outputs (columns) &
 *	3- u8 KPD_u8GetPressedKey(void); // used to activate/deactivate columns, search for pressed column switches continuously, and get the value pressed of the keypad
 *
 *
 *
 *
 * */
#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"HKPD.h" // This header file includes selection of keypad pins and define functions to deal with keypad (initialization, get pressed key)

const u8 KPD_au8Keys[COL_NUMBER][ROW_NUMBER] = // [columns][rows]
{

		{1, 5, 9, 13},  // 1st column(its rows)
		{2, 6, 10, 14}, // 2nd column(its rows)
		{3, 7, 11, 15}, // 3rd column(its rows)
		{4, 8, 12, 16}  // 4th column(its rows)
};

void KPD_vidInit(void)
{
	// Configure Keypad pins

		// Columns --> output, high
		u8 colIndex; // column index (0, 1...(COL_NUMBER-1))

		for(colIndex = COL_FIRST_PIN; colIndex < (COL_NUMBER + COL_FIRST_PIN); colIndex++)
		{
			SetPinDirection(colIndex, OUTPUT); // output
			SetPinValue(colIndex, HIGH); // high
		}

		// Rows --> inputs, pulled up
		u8 rowIndex; // row index (0, 1...(ROW_NUMBER-1))

		for(rowIndex = ROW_FIRST_PIN; rowIndex < (ROW_NUMBER + ROW_FIRST_PIN); rowIndex++)
		{
			SetPinDirection(rowIndex, INPUT_PU); // Define as output and activate internal pull up resistor
		}
}



u8 KPD_u8GetPressedKey(void) // used to activate/deactivate columns to search for pressed column switches continuously
{
	// Loop on columns
	// Activate one column (Set output 0)
	// Loop on rows
	// if (read row input after the column activating loop) = 0 --> return the value from the KPD_au8Keys

	u8 colIndex; // column index (0, 1...(COL_NUMBER-1))
	u8 rowIndex; // row index (0, 1...(ROW_NUMBER-1))

	u8  RetValue = 0; // to return the value of the pressed key according to the array KPD_au8Keys

/************Column Activating Loop (outer)-Searching pressed button in the activated column loop (inner)*************/

	/**************************** Start of Outer Loop (Column Activating) *************************/
	for(colIndex = COL_FIRST_PIN; colIndex < (COL_NUMBER + COL_FIRST_PIN); colIndex++) // Activating column loop
	{
		SetPinValue(colIndex, LOW); // Activate column number colIndex (0 then 1 then 2,.....)

		// each time you activate a column --> search for the activated column pressed key

		/**************************** Start of Inner Loop (Activated Column pressed keys) *************************/
		for(rowIndex = ROW_FIRST_PIN; rowIndex < (ROW_NUMBER + ROW_FIRST_PIN); rowIndex++) // Searching pressed activated column keys
		{
			if(GetPinValue(rowIndex) == LOW) // when Low --> key is pressed --> [0][0], [0][1], [0][2], [0][3].....
			{
				_delay_ms(50); // to avoid bouncing (50-250)ms
				if(GetPinValue(rowIndex) == HIGH) //to make sure you get back to the un-pressed state
				{
				RetValue= KPD_au8Keys[colIndex-COL_FIRST_PIN][rowIndex-ROW_FIRST_PIN]; // get the pressed key
				}
			}

		}
		/**************************** End of Inner Loop (Activated Column pressed keys) *************************/

	/****************************** End of Outer Loop (Column Activating) ****************************/

/*************************************************************************************************************/
		SetPinValue(colIndex, HIGH); // Deactivate column
	}

	return RetValue; // get the value of the pressed key (if any)
}
