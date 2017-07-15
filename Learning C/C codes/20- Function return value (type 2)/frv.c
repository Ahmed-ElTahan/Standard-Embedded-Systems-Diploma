// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program the use of function type 2 which returns output
*/


#include<stdio.h> // Library to include c functions for the compiler.

// function declaration and body
int add()
{
	int no_1;
	int no_2;
	int sum;
	
	// no_1
	printf("Please enter no_1: ");
	scanf("%d", &no_1);

	// no_2
	printf("Please enter no_2: ");
	scanf("%d", &no_2);
	
	sum = no_1 + no_2;
	
	return sum;
}

main()
{	
	// Declaration and Inintialization
	int func_output; // function output to be stored in

	// Write your instructions here.
	func_output = add(); // function call

	// Output
	printf("summation of number 1 and 2 is: %d", func_output);

	
}