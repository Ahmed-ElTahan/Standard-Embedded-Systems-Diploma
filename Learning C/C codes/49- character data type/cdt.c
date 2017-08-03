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
	unsigned char x, y, z; // for non overflow
	x = 'a'; // letter char
	y = '@'; // special char
	z = '3'; // one number, according to ascii table
	
	printf("x = %c, y = %c, z = %c \n", x, y, z); // will print x = a, y = @, z = 3
	
	// case 1
	x = '213';
	printf("(hardware coded) store more than one element in char of 213 gets the last number %c \n", x);
	
	// case 2
	printf("please enter a number: ");
	scanf("%c", &x);
	printf("(using scanf) store more than one element in char of gets the first number %c \n", x);
	
	// case 4
	x = 100; // put decimal
	printf("for decimal x = %d \n", x); // 100
	printf("for ascii x = %c \n", x); // d (according to ascii table)

	// case 3
	x = 'T'; // put ascii
	printf("for decimal x = %d \n", x); // 84
	printf("for ascii x = %c \n", x); // T (according to ascii table)
	printf("for hex x = %x \n", x); // 54 (according to ascii table)


	// Write your instructions here.
	
	// Output
	
}