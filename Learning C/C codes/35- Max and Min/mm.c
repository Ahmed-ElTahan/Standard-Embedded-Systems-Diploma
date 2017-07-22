// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code that ask the user to enter 10 values and save them in an array 
	using a for loop. Then print the minimum and the maximum of the values. 
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
		int size = 5;
		int array[5];
		int max, min; // maximum and minimum variables
		
	// Write your instructions here.
		// filling the array
		for (i = 0; i < size; i++)
		{
			printf("Please enter number %d: ", (i + 1));
			scanf("%d", &array[i]);
		}
		
		// Getting the maximum algorithm
		max = array[0]; // initially
		
		for (i = 0; i < size - 1; i++)
		{
				if (array[i+1] > max)
				{
					max = array[i+1];
				}
		}
		
		// Getting the minimum algorithm
		min = array[0]; // initially	
		for (i = 0; i < size - 1; i++)
		{
				if (array[i+1] < min)
				{
					min = array[i+1];
				}
		}
		
	// Output
	printf("The maximum value is: %d \n", max); // printing max value
	printf("The minimum value is: %d", min); // printing min value
	
	
}