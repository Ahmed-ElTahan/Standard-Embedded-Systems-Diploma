// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code that uses array concept to get 10 values from the user and then print them in two ways, normal order and reversed order
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	
	int i; // counter
	int numbers[10]; // array declaration
	
	// Write your instructions here.
	
		// filling the array by the user
		for ( i = 0; i <= 9; i++ )
		{
			printf("Please enter number %d : ", ( i + 1 ));
			scanf("%d", &numbers[i]);
		}
		
		// printing entered numbers in a normal order
		printf("printing entered numbers in a normal order\n");
		for ( i = 0; i <= 9; i++ )
		{
			printf("Number %d you entered is: %d \n", (i+1), numbers[i]);
		}
		
		// printing entered numbers in a reversed order
		printf("printing entered numbers in a reversed order\n");
		for ( i = 9; i >=0; i-- )
		{
			printf("Number %d you entered is: %d \n", (i+1), numbers[i]);
				
		}
	
	// Output
	
}