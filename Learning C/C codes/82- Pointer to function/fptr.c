// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code used to show the concept of using pointer to a function
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define (Macros: Object / Fuction)
// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions


// void input and output function that prints a message on the screen.	
	void HelloWorld (void)
	{
		printf("Hello World");
	}

	// Create a pointer to the function with the name of HelloWorld and initialize the function pointer with it.
	void (* Fptr) (void) = HelloWorld; // we don't add & (address) as it will replaced (the function name) with its address (Jump to address method)
	// the function pointer can be also related the previous HelloWorld fucntion as : void (* Fptr) (void); Fptr = HelloWorld;
	
	
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	
	// Write your instructions here.
	
		// Calling the function HelloWorld using the pointer function
		Fptr();
	// infinite loop  while(1){}
	// Output
	
}