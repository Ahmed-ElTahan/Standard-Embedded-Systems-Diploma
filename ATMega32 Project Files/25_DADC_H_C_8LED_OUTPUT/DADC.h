/*
 * DADC.h
 *
 *  Created on: Sep 30, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
 * This header file is used to include the Macros related to the ADC driver as:
 * (ADMUX, ADSRA, ADCH, ADCL) Registers' Addresses, Bits of these registers
 * Reference voltage reference options (AREF, AVCC, Internal 2.56V), Adjustment options (Left/Right),
 * Channel Selection (single/differential), Prescaler no. selection, structure data type to include the
 * variables to configure the usage of the ADC, and functions' prototypes used in this driver.
 *
 *
 *
 **	ADMUX Register:
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
 *
 * There are two functions used in this driver:
 *    1- void ADC_Init(ADC_CONFIG Config); // This Function used to configure settings of ADC: Reference voltage, Adjustment (Left, Right), Channel (Single: 0, 1...7, Differential), Prescaler (2, 4, 8...128). It takes a structure object of the data type defined as ADC_CONFIG which has 4 variables to be specified (Ref, Adjustment, Channel, Prescaler)
 *    2- u16 ADC_GetData(void);			  // This Function is used to get the data from the ADC data registers (ADCH(8-bit), ADCL(8-bit) == 16-bit) after the ADC conversion process completes
 *
 * */


#ifndef DADC_H_
#define DADC_H_

// ADC main registers and their addresses
#define ADMUX  *(volatile u8*) 	(0x27) // ADC Multiplexer Selection Register
#define ADCSRA *(volatile u8*) 	(0x26) // ADC Control and Status Register
#define ADCH   *(volatile u8*)  (0x25) // ADC Data Register High Byte
#define ADCL   *(volatile u8*)  (0x24) // ADC Data Register Low Byte

// ADMUX Register (configure: VREF (AREF, AVCC, Internal), Adjustment (Left/Right), Channel Selection (Single(0,1,...7), Differential))
#define REFS1 7 // Reference Selection Bits
#define REFS0 6 // Reference Selection Bits
#define ADLAR 5 // ADC Left Adjust Result
#define MUX4  4 // Analog Channel and Gain Selection Bits
#define MUX3  3 // Analog Channel and Gain Selection Bits
#define MUX2  2 // Analog Channel and Gain Selection Bits
#define MUX1  1 // Analog Channel and Gain Selection Bits
#define MUX0  0 // Analog Channel and Gain Selection Bits

// ADCSRA Register (configure: enable ADC, start conversion, Trigger, interrupt flag, interrupt enable, prescaler)
#define ADEN  7 // ADC Enable
#define ADSC  6 // ADC Start Conversion
#define ADATE 5 // ADC Auto Trigger Enable
#define ADIF  4 // ADC Interrupt Flag
#define ADIE  3 // ADC Interrupt Enable
#define ADPS2 2 // ADC Prescaler Select Bits
#define ADPS1 1 // ADC Prescaler Select Bits
#define ADPS0 0 // ADC Prescaler Select Bits

#define ADCIF GET_BIT(ADCSRA, ADIF) // ADCSRA: Interrupt flag bit value

// Reference Voltage Macros
#define REF_AREF 		0 // AREF Pin
#define REF_AVCC 		1 // AVCC Pin + Capacitor on AREF
#define REF_INTERNAL 	2 // VREF is 2.56 + Capacitor on AREF

// Adjustment Selection Macros
#define ADJUSTMENT_LEFT 	1 // [ADCH(8)] [ADCL(2) 00 0000]
#define ADJUSTMENT_RIGHT 	0 // [0000 00 ADCH(2)] [ADCL(8)]

// Channels Selection Macros
	// Single Conversion Channel
	#define CHANNEL_ADC0 0 // Pin A0
	#define CHANNEL_ADC1 1 // Pin A1
	#define CHANNEL_ADC2 2 // Pin A2
	#define CHANNEL_ADC3 3 // Pin A3
	#define CHANNEL_ADC4 4 // Pin A4
	#define CHANNEL_ADC5 5 // Pin A5
	#define CHANNEL_ADC6 6 // Pin A6
	#define CHANNEL_ADC7 7 // Pin A7

	// Differential (1st Signal - 2nd Signal) * Gain
	#define CHANNEL_ADC0_ADC0_10 	8	// (ADC0 - ADC0)*10
	#define CHANNEL_ADC1_ADC0_10 	9	// (ADC1 - ADC0)*10
	#define CHANNEL_ADC0_ADC0_200 	10	// (ADC0 - ADC0)*200
	#define CHANNEL_ADC1_ADC0_200 	11	// (ADC1 - ADC0)*200
	#define CHANNEL_ADC2_ADC2_10 	12	// (ADC2 - ADC2)*10
	#define CHANNEL_ADC3_ADC2_10 	13	// (ADC3 - ADC2)*10
	#define CHANNEL_ADC2_ADC2_200 	14	// (ADC2 - ADC2)*200
	#define CHANNEL_ADC3_ADC2_200 	15	// (ADC3 - ADC2)*200
	#define CHANNEL_ADC0_ADC1_1 	16	// (ADC0 - ADC1)*1
	#define CHANNEL_ADC1_ADC1_1 	17	// (ADC1 - ADC1)*1
	#define CHANNEL_ADC2_ADC1_1 	18	// (ADC2 - ADC1)*1
	#define CHANNEL_ADC3_ADC1_1 	19	// (ADC3 - ADC1)*1
	#define CHANNEL_ADC4_ADC1_1 	20	// (ADC4 - ADC1)*1
	#define CHANNEL_ADC5_ADC1_1 	21	// (ADC5 - ADC1)*1
	#define CHANNEL_ADC6_ADC1_1 	22	// (ADC6 - ADC1)*1
	#define CHANNEL_ADC7_ADC1_1 	23	// (ADC7 - ADC1)*1
	#define CHANNEL_ADC0_ADC2_1 	24	// (ADC0 - ADC2)*1
	#define CHANNEL_ADC1_ADC2_1 	25	// (ADC1 - ADC2)*1
	#define CHANNEL_ADC2_ADC2_1 	26	// (ADC2 - ADC2)*1
	#define CHANNEL_ADC3_ADC2_1 	27	// (ADC3 - ADC2)*1
	#define CHANNEL_ADC4_ADC2_1 	28	// (ADC4 - ADC2)*1
	#define CHANNEL_ADC5_ADC2_1 	29	// (ADC5 - ADC2)*1

// Prescaler Selection Macros (sampling frequency (fs) = MCU clock frequency / Prescaler value)
#define PRESCALER_2 	0
#define PRESCALER_4 	1
#define PRESCALER_8 	2
#define PRESCALER_16 	3
#define PRESCALER_32 	4
#define PRESCALER_64 	5
#define PRESCALER_128 	6

// Define a defined struct data type to store: Ref, Adjustment, Channel, Prescaler options
typedef struct {
	u8 Ref; 		// Used to define the mode of the reference voltage (AREF, AVCC, Internal 2.56V)
	u8 Adjustment; 	// Used to specify the adjustment ( Left [ADCH(8)] [ADCL(2) 00 0000] or Right [0000 00 ADCH(2)] [ADCL(8)] )
	u8 Channel;		// Used to select the channel used (Single: ADC0...ADC7, Differential)
	u8 Prescaler;	// Used to select the prescaler in order to specify the sampled frequency (2, 4, 8...128)
} ADC_CONFIG;


// Functions' Prototypes
void ADC_Init(ADC_CONFIG Config); // This Function used to configure settings of ADC: Reference voltage, Adjustment (Left, Right), Channel (Single: 0, 1...7, Differential), Prescaler (2, 4, 8...128). It takes a structure object of the data type defined as ADC_CONFIG which has 4 variables to be specified (Ref, Adjustment, Channel, Prescaler)
u16 ADC_GetData(void);			  // This Function is used to get the data from the ADC data registers (ADCH(8-bit), ADCL(8-bit) == 16-bit) after the ADC conversion process completes

#endif /* DADC_H_ */
