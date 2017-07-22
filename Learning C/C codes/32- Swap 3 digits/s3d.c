// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program gets a number of three digits from the user and swap these digits and output the reversed form.
	The idea stands behaing using / and % effectively with 10, 100, 1000 ... depending on the number of digits

*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int input; // ex 283
	int output;
	
	// Write your instructions here.
	printf("Please input the number of three digits: ");
	scanf("%d", &input);
	

	int a = input / 100; // 2
	int b = input % 100; // 83
	int c = b / 10; // 8
	int d = b % 10; // 3
	
	output = (d * 100) + (c * 10) + (a); // 382
	
	// Output
	printf("After swaping digits %d: ", output);
	
}