// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program show how a character data type can be overflowed when we assign a number to it which is maximum than that it can store (0---255)
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	unsigned char x; // 0 ---- 255
	int i; // counter
	
	printf("x is char data type");
	
	for (i = 0; i < 300; i++)
	{
		x = i; // assign i to x
		printf("Assign %d to char x == %d", i, x);
		if (i >= 256)
		{
			printf("  Memory Overflow ");
		}
		printf("\n");
	}
	// Write your instructions here.
	
	// Output
	
}