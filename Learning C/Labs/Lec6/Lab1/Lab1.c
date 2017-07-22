// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code defines an int initialized with 10, then print it, then define a pointer that 
	points to that int and change the value of the int through the pointer to be 20, then print it again.
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
	x = 10; // initialization using x
	printf("Adding value to x using x is: %d \n", x);
	
	int* ptr; // these 2 lines can be int* ptr = &x;
	ptr = &x; // store x's address in the pointer
	printf("The address of x from x is: %d \n", &x);
	printf("The address of x from the pointer is: %d \n", ptr);
	
	printf("The address of the pointer itself is: %d \n", &ptr);
	
	*ptr = 20; // change the value of x using the pointer
	printf("Changing the value of x using the pointer to be: %d \n", *ptr);
	// Write your instructions here.
	
	
	// Output
	
}