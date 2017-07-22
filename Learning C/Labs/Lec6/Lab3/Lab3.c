// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code that ask the user to enter 2 values and save them in two variables, then 
	the program sends these variables to function that calculates the summation and 
	subtraction of them, the function returns the 2 results and return them in two pointers 
	received as input arguments . The program then print the 2 results*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions
void Pass_add_sum_sub(int a, int b, int* summation, int* subtraction) // int* summation = &sum, int* subtraction = &sub
{
	*summation = a + b;
	*subtraction = a - b;
}

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int i; // counter
	int array[2];
	int sum, sub;
	
	for (i = 0; i < 2; i++)
	{
		printf("Please enter number %d: ", (i + 1));
		scanf("%d", &array[i]);
	}
	
	
	// Write your instructions here.
	Pass_add_sum_sub(array[0], array[1], &sum, &sub);
	
	printf("Sum is : %d \n", sum);
	printf("Sub is : %d \n", sub);
	
	// Output
	
}