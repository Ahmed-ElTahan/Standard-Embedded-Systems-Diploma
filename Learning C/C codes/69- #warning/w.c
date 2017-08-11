// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code shows how to use #warning --> compile but with warning message
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define
#define Max 150
// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	int arr[Max];
	// Write your instructions here.
	#if Max > 100
		#warning "Array can not exceed 100 elements"
	#endif
	
	// infinite loop  while(1){}
	// Output
	
}