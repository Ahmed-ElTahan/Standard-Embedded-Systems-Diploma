// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program motivates the coder to use function type 3 which takes inputs but void (no return)
*/


#include<stdio.h> // Library to include c functions for the compiler.

// function declaration and body
void add(int no_1, int no_2)
{
	int sum;
	sum = no_1 + no_2;
	
	printf("summation of number 1 and 2 is: %d", sum);
}

main()
{	
	// Declaration and Inintialization
	
	int x;
	int y;
	
	// Write your instructions here.
	
	// no_1
	printf("Please enter no_1: ");
	scanf("%d", &x);

	// no_2
	printf("Please enter no_2: ");
	scanf("%d", &y);
	add(x, y); // function call
	
	// Output
	
}