// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code shows the possible cases for a constant pionter in 4 cases: 5, 6, 7, 8 and illustrates address and values states then
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int no_1 = 10;
	int no_2 = 20;
	
	// case 5: fixed address, non fixed value, change value of no_1 by itself and pointer
	printf("Case 5 \n");
	int* const ptr5 = &no_1; // assign address of no_1 to const address pointer
	printf("number 1 value by pointer case 5 %d \n", *ptr5); // no_1
	*ptr5 = 20; // change value of no_1 using the pointer created
	printf("After changing value of no_1 using pointer case 5 %d \n", *ptr5);
	// ptr5 = &no_2; --> gives compilation error
	
	
	// case 6: fixed value, non fixed address, change value only by the variable itself
	printf("Case 6 \n");
	const int* ptr6 = &no_1; // assign address of no_1 to const address pointer
	printf("number 1 value by pointer case 5 %d \n", *ptr6); // no_1
	ptr6 = &no_2; // change value of no_1 using the pointer created
	printf("After changing pointer value (address of no_1 to no_2) value of no_2 case 6 %d \n", *ptr6);
	// *ptr6 = 20; --> gives compilation error
	
	// case 7: fixed value, non fixed address, change value only by the variable itself --> same as case 6, but other declaration
	printf("Case 7 \n");
	int const* ptr7 = &no_1; // assign address of no_1 to const address pointer
	printf("number 1 value by pointer case 5 %d \n", *ptr7); // no_1
	ptr7 = &no_2; // change value of no_1 using the pointer created
	printf("After changing pointer value (address of no_1 to no_2) value of no_2 case 7 %d \n", *ptr7);
	// *ptr7 = 20; --> gives compilation error
	
	// case 8: (compilation error if defined) const* int ptr8
	printf("Case 8 : compilation error \n");
	
	// Write your instructions here.

	// Output
	
}