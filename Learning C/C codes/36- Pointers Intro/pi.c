// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code is intended to show the basic concept of pointers by changing the value of a variable using itself and pointer
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int x; 
	x = 7; // initialization using x
	printf("Adding value to x using x is: %d \n", x);
	
	int* ptr; // these 2 lines can be int* ptr = &x;
	ptr = &x; // store x's address in the pointer
	printf("The address of x from x is: %d \n", &x);
	printf("The address of x from the pointer is: %d \n", ptr);

	printf("The address of the pointer itself is: %d \n", &ptr);	
	
	*ptr = 9; // change the value of x using the pointer
	printf("Changing the value of x using the pointer to be: %d \n", *ptr);
	// Write your instructions here.
	
	
	// Output
	
}