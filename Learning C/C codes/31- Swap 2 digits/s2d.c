// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -------------------------------------------------------
	This program gets a number of two digits from the user and swap these digits and output the reversed form.
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
	int input; // ex 28
	float a, b;
	int no_1;
	int no_2;
	int output;
	
	// Write your instructions here.
	printf("Please input the number of two digits: ");
	scanf("%d", &input);
	
	/*
	// method 1
	a = input / 10.0; // 2.8
	no_1 = a; // 2
	float c = no_1;
	b = c - no_1; // 0.8
	no_2 = b * 100; // 80
	int output = no_1 + no_2; // 82
	*/
	
	// method 2
	
	int y = input / 10; // 2
	int z = input % 10; // 8
	output = y + z * 10 ; // 82
	// Output
	printf("After swaping digits %d: ", output);
	
}