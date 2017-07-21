// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code that ask the user to enter 10 values and save them in an array 
	using a for loop. Then print the minimum and the maximum of the values. 
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype
Get_max(int size, int array[]);
Get_min(int size, int array[]);

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
		
	// Declaration and Inintialization
		int i; // counter
		int size = 10;
		int array[10];
		int max, min; // maximum and minimum variables
		
	// Write your instructions here.
		// filling the array
		for (i = 0; i < size; i++)
		{
			printf("Please enter number %d: ", (i + 1));
			scanf("%d", &array[i]);
		}
		
		max = Get_max(size, array); // get the maximum using Get_max function call
		min = Get_min(size, array); // get the minimum using Get_min function call
		
	// Output
	printf("The maximum value is: %d \n", max); // printing max value
	printf("The minimum value is: %d", min); // printing min value
	
	
}