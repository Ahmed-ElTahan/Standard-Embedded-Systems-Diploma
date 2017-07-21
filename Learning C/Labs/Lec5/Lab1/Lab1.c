// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code that ask the user to enter 10 values and save them in an array using a for 
	loop. Then print the values entered by the user in reverse order using another for loop
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
		
		
		// printing entered numbers in a reversed order
		printf("printing entered numbers in a reversed order\n");
		for ( i = 9; i >=0; i-- )
		{
			printf("Number %d you entered is: %d \n", (i+1), numbers[i]);
				
		}
	
	// Output
	
}