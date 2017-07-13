// This code is created by Ahmed A. Eltahan
#include<stdio.h> // Library to include c functions for the compiler.

/* 
	----------------------------- Program Description -----------------------------------------
   Write a C that ask the user to enter a number and check if it is Even or Odd number
*/


main()
{	
	// Declaration
	int input;
	int rem; // remainder
	
	// write your instructions here.
	printf("This program is intended to determine if the number given is even or odd \n \n");
	printf("Please enter number: ");
	scanf("%d", &input);
	
	rem = input%2; // when even number is divided by 2, ther is no remainder. On the other side, when an odd number is divided by 2, the remainder is 1
	
	// Method 1
		if (rem == 0)
		{
			printf("The Number Is Even");
		}
	
		else
		{
			printf("The Number Is Odd");
		}
	/*
	// Method 2 (no need for curly brackets and rem)
	if(input%2)	printf("The Number Is Odd");
	else printf("The Number Is Even");                     
	*/

	
}