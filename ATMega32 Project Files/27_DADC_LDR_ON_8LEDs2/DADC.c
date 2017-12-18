/*
 * DADC.c
 *
 *  Created on: Sep 30, 2017
 *      Author: Ahmed A. Eltahan
 */
/*
 *
 *	ADMUX Register:
 *
 *	bit number: 	   7      6       5       4      3      2      1     0
 *	bit name:	     REFS1 | REFS0 | ADLAR | MUX4 | MUX3 | MUX2 | MUX1 | MUX0
 *  bits short description:
 *  	- REFS1, REFS0 (Reference Selection Bits): used to select the reference voltage: AREF pin (00), AVCC pin (01), Internal VREF 2.56V (11)
 *  	- ADLAR (ADC Left Adjust Result): used to select the adjustment of data (Left (1): [ADCH(8)] [ADCL(2) 00 0000], Right (0): [ADCH(2) 00 0000] [ADCL(8)])
 *		- MUX4, MUX3, MUX2, MUX1, MUX0 (Analog Channel and Gain Selection Bits): used to select channels used (single / differential)
 *
 *
 * ADCSRA Register:
 *	bit number: 	   7      6      5       4      3      2       1      0
 *	bit name:	     ADEN | ADSC | ADATE | ADIF | ADIE | ADPS2 | ADPS1 | ADPS0
 *  bits short description:
 *  	- ADEN (ADC Enable): (1) Enable using the ADC, (0) Disable using the ADC
 *  	- ADSC (ADC Start Conversion): (1) Start Conversion, (0) Stop Conversion
 *  	- ADATE (ADC Auto Trigger Enable): (1) Start Conversion based on specific signal input "Triggering", (0) stop auto triggering option
 *		- ADIF (ADC Interrupt Flag): In initialization it is automatically clear, after conversion completes it returns 1, to reset it again after fetching the data it must be cleared by setting it to 1
 *		- ADIE (ADC Interrupt Enable): When this bit is written to one and the I-bit in SREG is set, the ADC Conversion Complete Interrupt is activated.
 *		- ADPS2, ADPS1, ADPS0 (ADC Prescaler Select Bits): used to select the prescaler factor used to specify the sampling frequency as the following equation: (sampling frequency (fs) = MCU clock frequency / Prescaler value)
 *
 * There are two functions used in this driver:
 *    1- void ADC_Init(ADC_CONFIG Config); // This Function used to configure settings of ADC: Reference voltage, Adjustment (Left, Right), Channel (Single: 0, 1...7, Differential), Prescaler (2, 4, 8...128). It takes a structure object of the data type defined as ADC_CONFIG which has 4 variables to be specified (Ref, Adjustment, Channel, Prescaler)
 *    		so, we select configurations of the following:
 *    			I-   Switching on REF (use AREF, AVCC, Internal 2.56V)
 *    			II-  Switching on ADJUSTMENT (Left or Right)
 *				III- Switching on CHANNEL (Single Conversion: ADC0, ADC1...ADC7, Differential: )
 *				IV-  Switching on PRESCALER (2, 4, 8, 16, 32, 64, 128)
 *
 *    2- u16 ADC_GetData(void);			  // This Function is used to get the data from the ADC data registers (ADCH(8-bit), ADCL(8-bit) == 16-bit) after the ADC conversion process completes
 *			Getting data is done by the following algorithm:
 *				I-   Start the ADC conversion process by setting ADSC bit in ADCSRA register.
 *				II-  Wait till the conversion completes. If it completes, the interrupt returns 1. In other words, do nothing as the interrupt flag ADIF is zero
 *				III- Get the data from ADCH and ADCL registers and store them in u16 variable
 *				IV-  Reset the interrupt flag by setting it to 1
 *
 * */


#include"DDIO.h" // This header file includes the appropriate IO definitions for the device that has been specified by the -MCU= compiler command-line switch.
#include"DADC.h" // This header file includes the appropriate definitions and functions used to initialize the ADC with a pre-specified configurations and to get the data back from the ADC after conversion


void ADC_Init(ADC_CONFIG Config) // This Function used to configure settings of ADC: Reference voltage, Adjustment (Left, Right), Channel (Single: 0, 1...7, Differential), Prescaler (2, 4, 8...128). It takes a structure object of the data type defined as ADC_CONFIG which has 4 variables to be specified (Ref, Adjustment, Channel, Prescaler)
{

// Switching on REF (use AREF, AVCC, Internal 2.56V)
	switch(Config.Ref)
	{
	// REFS1 | REFS0 	0 | 0           // VREF = Input Voltage on AREF pin
	case (REF_AREF):
	CLR_BIT(ADMUX, REFS1);
	CLR_BIT(ADMUX, REFS0);
	break;

	// REFS1 | REFS0 	0 | 1           // VREF = Input Voltage on AVCC pin + cap. on AFER
	case (REF_AVCC):
	CLR_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
	break;

	// REFS1 | REFS0 	1 | 1           // VREF = Internal 2.56V + cap. on AFER
	case (REF_INTERNAL):
	SET_BIT(ADMUX, REFS1);
	SET_BIT(ADMUX, REFS0);
	break;
	}

// Switching on ADJUSTMENT (Left or Right)
	switch(Config.Adjustment)
	{
	// Left: Arrange data in this option as: [ADCH(8)] [ADCL(2) 00 0000]
	case (ADJUSTMENT_LEFT):
	SET_BIT(ADMUX, ADLAR);
	break;

	// Right: Arrange data in this option as: [ADCH(2) 00 0000] [ADCL(8)]
	case (ADJUSTMENT_RIGHT):
	CLR_BIT(ADMUX, ADLAR);
	break;
	}

// Switching on CHANNEL (Single Conversion: ADC0, ADC1...ADC7, Differential: )

		switch(Config.Channel)
		{

		// Single Conversion Channels

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 0 | 0 | 0 | 0		Channel: ADC0
			case (CHANNEL_ADC0):
			CLR_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 0 | 0 | 0 | 1		Channel: ADC1
			case (CHANNEL_ADC1):
			CLR_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 0 | 0 | 1 | 0		Channel: ADC2
			case (CHANNEL_ADC2):
			CLR_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 0 | 0 | 1 | 1		Channel: ADC3
			case (CHANNEL_ADC3):
			CLR_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 0 | 1 | 0 | 0		Channel: ADC4
			case (CHANNEL_ADC4):
			CLR_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 0 | 0 | 0 | 0		Channel: ADC5
			case (CHANNEL_ADC5):
			CLR_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 0 | 1 | 1 | 0		Channel: ADC6
			case (CHANNEL_ADC6):
			CLR_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 0 | 1 | 1 | 1		Channel: ADC7
			case (CHANNEL_ADC7): // 00111
			CLR_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;


		// Differential (1st Signal - 2nd Signal) * Gain

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 1 | 0 | 0 | 0		Channel: (ADC0 - ADC0)*10
			case (CHANNEL_ADC0_ADC0_10):
			CLR_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 1 | 0 | 0 | 1		Channel: (ADC1 - ADC0)*10
			case (CHANNEL_ADC1_ADC0_10):
			CLR_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 1 | 0 | 1 | 0		Channel: (ADC0 - ADC0)*200
			case (CHANNEL_ADC0_ADC0_200):
			CLR_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 1 | 0 | 1 | 1		Channel: (ADC1 - ADC0)*200
			case (CHANNEL_ADC1_ADC0_200):
			CLR_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 1 | 1 | 0 | 0		Channel: (ADC2 - ADC2)*10
			case (CHANNEL_ADC2_ADC2_10):
			CLR_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 1 | 1 | 0 | 1		Channel: (ADC3 - ADC2)*10
			case (CHANNEL_ADC3_ADC2_10):
			CLR_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 1 | 1 | 1 | 0		Channel: (ADC2 - ADC2)*200
			case (CHANNEL_ADC2_ADC2_200):
			CLR_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		0 | 1 | 1 | 1 | 1		Channel: (ADC3 - ADC2)*200
			case (CHANNEL_ADC3_ADC2_200):
			CLR_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 0 | 0 | 0 | 0		Channel: (ADC0 - ADC1)*1
			case (CHANNEL_ADC0_ADC1_1):
			SET_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 0 | 0 | 0 | 1		Channel: (ADC1 - ADC1)*1
			case (CHANNEL_ADC1_ADC1_1):
			SET_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 0 | 0 | 1 | 0		Channel: (ADC2 - ADC1)*1
			case (CHANNEL_ADC2_ADC1_1):
			SET_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 0 | 0 | 1 | 1		Channel: (ADC3 - ADC1)*1
			case (CHANNEL_ADC3_ADC1_1):
			SET_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 0 | 1 | 0 | 0		Channel: (ADC4 - ADC1)*1
			case (CHANNEL_ADC4_ADC1_1):
			SET_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 0 | 1 | 0 | 1		Channel: (ADC5 - ADC1)*1
			case (CHANNEL_ADC5_ADC1_1):
			SET_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 0 | 1 | 1 | 0		Channel: (ADC6 - ADC1)*1
			case (CHANNEL_ADC6_ADC1_1):
			SET_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 0 | 1 | 1 | 1		Channel: (ADC7 - ADC1)*1
			case (CHANNEL_ADC7_ADC1_1):
			SET_BIT(ADMUX, MUX4); CLR_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 1 | 0 | 0 | 0		Channel: (ADC0 - ADC2)*1
			case (CHANNEL_ADC0_ADC2_1):
			SET_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 1 | 0 | 0 | 1		Channel: (ADC1 - ADC2)*1
			case (CHANNEL_ADC1_ADC2_1):
			SET_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 1 | 0 | 1 | 0		Channel: (ADC2 - ADC2)*1
			case (CHANNEL_ADC2_ADC2_1):
			SET_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 1 | 0 | 1 | 1		Channel: (ADC3 - ADC2)*1
			case (CHANNEL_ADC3_ADC2_1):
			SET_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); CLR_BIT(ADMUX, MUX2); SET_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 1 | 1 | 0 | 0		Channel: (ADC4 - ADC2)*1
			case (CHANNEL_ADC4_ADC2_1):
			SET_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); CLR_BIT(ADMUX, MUX0);
			break;

			//  MUX4 | MUX3 | MUX2 | MUX1 | MUX0 		1 | 1 | 1 | 0 | 1		Channel: (ADC5 - ADC2)*1
			case (CHANNEL_ADC5_ADC2_1):
			SET_BIT(ADMUX, MUX4); SET_BIT(ADMUX, MUX3); SET_BIT(ADMUX, MUX2); CLR_BIT(ADMUX, MUX1); SET_BIT(ADMUX, MUX0);
			break;

		}



// Switching on PRESCALER (2, 4, 8, 16, 32, 64, 128)
	switch(Config.Prescaler)
	{
		// ADPS2 | ADPS1 | ADPS0		0 | 0 | 0				Prescaler  = 2
		case (PRESCALER_2):
		CLR_BIT(ADCSRA, ADPS2); CLR_BIT(ADCSRA, ADPS1); CLR_BIT(ADCSRA, ADPS0);
		break;

		// ADPS2 | ADPS1 | ADPS0		0 | 1 | 0				Prescaler  = 4
		case (PRESCALER_4):
		CLR_BIT(ADCSRA, ADPS2); SET_BIT(ADCSRA, ADPS1); CLR_BIT(ADCSRA, ADPS0);
		break;

		// ADPS2 | ADPS1 | ADPS0		0 | 1 | 1				Prescaler  = 8
		case (PRESCALER_8):
		CLR_BIT(ADCSRA, ADPS2); SET_BIT(ADCSRA, ADPS1); SET_BIT(ADCSRA, ADPS0);
		break;

		// ADPS2 | ADPS1 | ADPS0		1 | 0 | 0				Prescaler  = 16
		case (PRESCALER_16): //
		SET_BIT(ADCSRA, ADPS2); CLR_BIT(ADCSRA, ADPS1); CLR_BIT(ADCSRA, ADPS0);
		break;

		// ADPS2 | ADPS1 | ADPS0		1 | 0 | 1				Prescaler  = 32
		case (PRESCALER_32): //
		SET_BIT(ADCSRA, ADPS2); CLR_BIT(ADCSRA, ADPS1); SET_BIT(ADCSRA, ADPS0);
		break;

		// ADPS2 | ADPS1 | ADPS0		1 | 1 | 0				Prescaler  = 64
		case (PRESCALER_64):
		SET_BIT(ADCSRA, ADPS2); SET_BIT(ADCSRA, ADPS1); CLR_BIT(ADCSRA, ADPS0);
		break;

		// ADPS2 | ADPS1 | ADPS0		1 | 1 | 1				Prescaler  = 128
		case (PRESCALER_128):
		SET_BIT(ADCSRA, ADPS2); SET_BIT(ADCSRA, ADPS1); SET_BIT(ADCSRA, ADPS0);
		break;
	}

// Enabling ADC to start, give power only not starting conversion
	SET_BIT(ADCSRA, ADEN);
}


// Want to return all the resolution of 10 bits, so need u16
u16 ADC_GetData(void) // This Function is used to get the data from the ADC data registers (ADCH(8-bit), ADCL(8-bit) == 16-bit) after the ADC conversion process completes
{
	SET_BIT(ADCSRA, ADSC); // Start Conversion

	while(ADCIF == 0); // wait here as the ADC interrupt flag is not 1. If 1, it ADC finished conversion

	u16 data = 0; // used to store the data got from ADC after Conversion
	data = ADCL; // 0000 0000 [ADCL (2) 00 0000]
	data = data | (ADCH << 8); // [ADCH (8)] | [ADCL (2) 00 0000]

	SET_BIT(ADCSRA, ADIF); // Clear Interrupt Flag by writing 1

	return data; // return the data after conversion
}
