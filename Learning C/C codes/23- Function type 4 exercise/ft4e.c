// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program the use of function type 4 which returns output and take inputs
	It's required to use function to take two numbers and print the maximum of them
*/


#include<stdio.h> // Library to include c functions for the compiler.

// function declaration and body
int max(int no_1, int no_2)
{
	int max;
	
	max = no_1; // initially
	
	if(max<=no_2)
	{
		max = no_2;
	}
	
	return max;
}

main()
{	
	// Declaration and Inintialization
	int func_output; // function output to be stored in
	int x, y;
	// Write your instructions here.
	
	// no_1
	printf("Please enter no_1: ");
	scanf("%d", &x);

	// no_2
	printf("Please enter no_2: ");
	scanf("%d", &y);
	
	
	func_output = max(x, y); // function call

	// Output
	printf("maximum of number 1 and 2 is: %d", func_output);

	
}