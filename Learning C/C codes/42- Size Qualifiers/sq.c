// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program shows the concept of size qulifiers (short and long)
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
	
	// Write your instructions here.
	
	// using data_type
		// integar
		size = sizeof(int);
		printf("The size of integar value is: %d Bytes \n", size);
		
		// long integar (long int == int long )
		size = sizeof(long int);
		printf("The size of long integar value is: %d Bytes \n", size);
		
		// long long integar
		size = sizeof(long long int);
		printf("The size of long long integar value is: %d Bytes \n", size);
		
		// short integar (short int x = int short x = short x)
		size = sizeof(short int);
		printf("The size of short integar value is: %d Bytes \n", size);
		
		// double
		size = sizeof(double);
		printf("The size of double value is: %d Bytes \n", size);
		
		// long double (long double == double long)
		size = sizeof(long double);
		printf("The size of long double value is: %d Bytes \n", size);
		
		// no short for double
				
		// char
		size = sizeof(char);
		printf("The size of character value is: %d Bytes \n", size);
	 
		// float
		size = sizeof(float);
		printf("The size of float value is: %d Bytes \n", size);
		
	// Output
	
}