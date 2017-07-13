// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a code that takes 2 numbers and print their summation, subtraction, anding, oring, and Xoring
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
		int a;
		int b; 
		int sum, sub, anding, oring, xoring;
	// Write your instructions here.
	printf("Please enter a:");
	scanf("%d", &a); // get number a
	
	printf("Please enter b:");
	scanf("%d", &b); // get number b

	// Summation operation
		sum = a + b;
		printf("a + b = %d \n \n", sum);

	// Subtraction operation
		sub = a - b;
		printf("a - b = %d \n \n", sub);

	// Anding operation
		anding = a & b;
		printf("a & b = %d \n \n", anding);

	// Oring operation
		oring = a | b;
		printf("a | b = %d \n \n", oring);
		
	// Xoring operation
		xoring = a ^ b;
		printf("a ^ b = %d", xoring);
	
}