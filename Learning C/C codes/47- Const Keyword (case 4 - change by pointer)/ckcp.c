// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code shows that after a value is assigned to a const data type variable, it can be changed using pointers
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	const float pi = 22.0/7.0; // = float const pi = 22.0/7.0;
	printf("value of pi as assigned as constant is %f \n", pi);
	// Write your instructions here.
	float* ptr = &pi; // pointer declaration and pointing to const pi
	*ptr = 3.1; // change the value of const pu 
	printf("U can change the value of the constant defined above using pointers (can't hardware codded) \n");

	printf("pi will equal to %f", pi); // *ptr = pi
	
	// Output
	
}