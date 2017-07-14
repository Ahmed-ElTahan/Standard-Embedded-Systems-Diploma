// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C program that ask the user to enter two numbers and print their summation, this program should never ends until the user close the window 
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int input;
	int i; // counter
	int sum = 0; // summation storage
	
	// Write your instructions here.
	while(1) // infinite loop
	{
		for (i = 1; i<=2; i++) // enter 2 values and summation loop
		{
			printf("Please enter number 1: ");
			scanf("%d", &input); // get the numbers from the user
			
			sum = sum + input;
		}
		
	printf("The resuls is: %d \n \n", sum);
	sum = 0; // re-initialize sum after each for loop for the next summation
	
	}
	// Output
	
}