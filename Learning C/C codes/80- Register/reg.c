// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code is used to show how to use register storage class
	register can be used with global / local variables
	register is used to store inside the memory of the microprocessor, if global this memory will be allocated
	as you run the code. if local, life time between the curly brackets
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define
// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)

// Enum

void main(void)
{	

	register int x = 10;
	// Declaration and Inintialization	
	// Write your instructions here.
	// infinite loop  while(1){}
	// Output
	printf("x is stored at the microprocessor's memory is %d", x);
	
}