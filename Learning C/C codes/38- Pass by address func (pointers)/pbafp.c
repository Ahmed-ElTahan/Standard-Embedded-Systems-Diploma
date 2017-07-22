// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Pass by address function using pointers concept, change a variable in the main function by a declared function without return  (void function)
	note : a in main (variable) is completely different that a (pointer) in the Increment function, even it is no pointer
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions
void Increment(int* a)
{
	*a = *a + 1;
}

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int a = 10;
	
	// Write your instructions here.
	Increment(&a);
	printf("a = %d", a);
	
	// Output
	
}