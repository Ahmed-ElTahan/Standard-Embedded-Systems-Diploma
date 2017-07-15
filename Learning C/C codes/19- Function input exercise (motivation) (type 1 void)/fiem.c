// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program motivates the coder to use function type 2 which returns output without inputs
*/


#include<stdio.h> // Library to include c functions for the compiler.

// function declaration and body
void add()
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
	
	printf("summation of number 1 and 2 is: %d", sum);
}

main()
{	
	// Declaration and Inintialization

	// Write your instructions here.
	add(); // function call
	// Output
	
}