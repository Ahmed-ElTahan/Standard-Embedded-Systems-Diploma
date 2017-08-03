// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------

*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype
// Declared Structures
union Grade {
	// elements
	short unsigned int Low;
	double High;
};
// Declared Functions
// Global variables (Declaration and Inintialization)

void main(void)
{	
	// Declaration and Inintialization
	union Grade English; // reserve max (short unsigned int, double) = 8 bytes accessed by both Low and High
	English.Low = 65535; // max of 2 bytes
	printf("English Low = %d \n", English.Low);
	printf("English High = %lf \n", English.High);
	English.High = 4294967290.2545158787; // max of 8 bytes
	printf("English Low = %d \n", English.Low);
	printf("English High = %lf \n", English.High);
	English.Low = 65535; // max of 2 bytes
	printf("English Low = %d \n", English.Low);
	printf("English High = %lf \n", English.High);

	// Write your instructions here.
	// infinite loop  while(1){}
	// Output
	
}