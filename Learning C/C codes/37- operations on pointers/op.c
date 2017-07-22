// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code is intended to show various operations on pointers
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
	int y;
	int z;
	
	x = 7; // initialization using x
	
	int* ptr = &x; // define a pointer;
	int* ptr2 = &y; // define another pointer
	
	ptr = &x; // store x's address in the pointer
	printf("The address of x from the pointer is: %d \n", ptr);
		// Increment
		ptr ++; // step = size(int (pointers data type)) = 4 bytes
		printf("The address of x from the pointer after increment is: %d \n", ptr);
	
		// Decrement
		ptr --; // step = size(int (pointers data type)) = 4 bytes
		printf("The address of x from the pointer after decrement is: %d \n", ptr);
	
		// Addtion
		ptr += 4; // step = size(int (pointers data type)) = (4 bytes) * 4 = 16 bytes
		printf("The address of x from the pointer after adding 4  is: %d \n", ptr);
	
		// Subraction
		ptr -= 4; // step = size(int (pointers data type)) = (4 bytes) * 4 = 16 bytes
		printf("The address of x from the pointer after subtracting 4 is: %d \n", ptr);
		
		// pointer - pointer
		z = ptr - ptr2;
		printf("address in pointer 1 is: %d \n", ptr);
		printf("address in pointer 2 is: %d \n", ptr2);
		printf("difference is: %d steps \n", z);
	// Write your instructions here.
	
	
	// Output
	
} 