// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code that ask the user to enter 10 values and save them in an array using a for 
	loop. Then print the summation and the average of the values entered. 
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
	int sum = 0; // summation var
	float avg; // average var
	
	// Write your instructions here.
	
		// filling the array by the user
		for ( i = 0; i <= 9; i++ )
		{
			printf("Please enter number %d : ", ( i + 1 ));
			scanf("%d", &numbers[i]);
			sum = sum + numbers[i]; // summation of array elements
		}
		
		avg = sum/10.0; // average calc
		
	// Output
	printf("Numbers entered summation is: %d : \n", sum); // summation output
	printf("Numbers entered average is: %f : ", avg); // average output
	
}