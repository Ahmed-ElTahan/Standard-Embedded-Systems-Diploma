// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code used to show the concept of using array of pointers to a functions
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
	void Hello (void)
	{
		printf("Hello");
	}

	void World (void)
	{
		printf(" World");
	}

	// Create an array of pointers to the functions with the name of Hello and World and initialize the function pointer with them.
	void (* Arrptr[2]) (void) = {Hello, World}; // we don't add & (address) as it will replaced (the function name) with its address (Jump to address method)
	// the function pointer can be also related the previous HelloWorld fucntion as : void (* Arrptr) (void); Arrptr[0] = Hello; Arr[1] = World;
	
	
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	
	// Write your instructions here.
	
		// Calling the functions Hello and World using the array of pointers to functions
		Arrptr[0]();
		Arrptr[1]();
	// infinite loop  while(1){}
	// Output
	
}