// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------

*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int size;
	int array[] = {1, 2, 4, 6, 8, 10, 87};
	
	// Write your instructions here.
	
	// using data_type
		// integar
		size = sizeof(int);
		printf("The size of integar value is: %d Bytes \n", size);
		
		// float
		size = sizeof(float);
		printf("The size of float value is: %d Bytes \n", size);
		
		// double
		size = sizeof(double);
		printf("The size of double value is: %d Bytes \n", size);
		
		// char
		size = sizeof(char);
		printf("The size of character value is: %d Bytes \n", size);
	 
	// using array name
		size = sizeof(array);
		printf("The size of the array of int data type is: %d Bytes \n", size);
	
	// using array element
		size = sizeof(array[0]);
		printf("The size of the array element of int data type is: %d Bytes \n", size);
		
	// using variable name 
		size = sizeof(size);
		printf("The size of variable size is: %d Bytes \n", size);
	
	// getting the number of elements of an array
		size = sizeof(array) / sizeof(array[0]);
		printf("The number of elements of an int array is: %d Elements \n", size);
		
	// Output
	
}