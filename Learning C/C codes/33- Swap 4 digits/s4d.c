// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program gets a number of four digits from the user and swap these digits and output the reversed form.
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
	int input; // ex 2835
	int output;
	
	// Write your instructions here.
	printf("Please input the number of four digits: ");
	scanf("%d", &input);
	

	int a = input / 1000; // 2
	int b = input % 1000; // 835
	int c = b / 100; // 8
	int d = b % 100; // 35
	int e = d / 10; // 3
	int f = d % 10; // 5
	
	output = (f * 1000) + (e * 100) + (c * 10) + a; // 382
	
	// Output
	printf("After swaping digits %d: ", output);
	
}