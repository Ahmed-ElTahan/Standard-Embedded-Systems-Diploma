// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program is intended to show an application to avoid problem with memory overflow
	a function is required to take two char inputs, multiply them to each other, and return the 
	result. To avoid Memory overflow problem, get the max of result (max(char) * max(char)) = 255*255 = 65025 < max(int) = 4294967296 then
	use int data type for return
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype
int multp()
{
	unsigned char x, y; // to avoid char overflow from (-128 => 127) to (0 => 255)
	int result;
	printf("Please Enter number 1: ");
	scanf("%d", &x);
	printf("Please Enter number 2: ");
	scanf("%d", &y);
	result = x * y;
	return result;
}
// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int output; // returning variable can store 65025 without memory overflow
	// Write your instructions here.
	output = multp();
	printf("Output is %d", output);
	// Output
	
}