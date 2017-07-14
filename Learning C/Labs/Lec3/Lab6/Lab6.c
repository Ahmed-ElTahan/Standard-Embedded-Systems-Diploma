// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a program in C to calculate the factorial of an integer entered by the user using while loop
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int input;
	int fact = 1; // factorial storage
	
	// Write your instructions here.
	
	printf("Enter an integar: "); 
	scanf("%d", &input); // get the input from the user
	
	do
	{
		fact = fact*(input); // fact = input*(input-1)*(input-2)...*1
		
		input--; // action dec
	} while (input>=1);
	// Output
	printf("Factorial = %d", fact);
	
}