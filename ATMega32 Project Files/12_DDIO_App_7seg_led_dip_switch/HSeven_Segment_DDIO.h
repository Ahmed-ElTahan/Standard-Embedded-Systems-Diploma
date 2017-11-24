/*
 * Seven_Segment_DDIO.h
 *
 *  Created on: Aug 27, 2017
 *      Author: Ahmed A. Eltahan
 */
// This Header file includes the function prototype of SevSeg_ShowNumber(int i) function and selection of SPN and EN_PIN

/*Note: Connect 1st pin of the seven segment to any pin number and then go orderly with 7 pins after it.
	   ex. 1st sev. seg. pin (SPN) is connected to pin no. 10, then connect 2nd, 3rd,...,8th pins to pin nos. 11, 12,...,17
*/
#ifndef HSEVEN_SEGMENT_DDIO_H_
#define HSEVEN_SEGMENT_DDIO_H_

#define SPN 24 // starting pin number
#define EN_PIN 6 // output power pin

// Function prototype
void SevSeg_ShowNumber(int i);

#endif /* HSEVEN_SEGMENT_DDIO_H_ */
