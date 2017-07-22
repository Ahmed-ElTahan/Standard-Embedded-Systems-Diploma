// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code that ask the user to enter 2 values and save them in two variables, then 
	the program sends these variables by address to a function that returns the summation of 
	them. The program then prints the result
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions
int Pass_add_sum(int* a, int* b) // int* a = &array[0], int* b = &array[1]
{
	int summation = *a + *b;
	return summation;
}

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int i; // counter
	int array[2];
	int sum;
	
	for (i = 0; i < 2; i++)
	{
		printf("Please enter number %d: ", (i + 1));
		scanf("%d", &array[i]);
	}
	
	
	// Write your instructions here.
	sum = Pass_add_sum(&array[0], &array[1]);
	
	printf("Sum is : %d \n", sum);
	
	// Output
	
}