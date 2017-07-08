// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
This program is used to show the if condition statement structures
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int x = 10;

	// write your instructions here.
	
	printf("If condition statements \n \n");
	
	// 1- Normal
		printf("Normal If statement \n");
		if (x == 10)
		{
			printf("Normal is OK \n \n");
		}
	
	// 2- if else
		printf("if-else statement \n");
		if (x != 10)
		{
			printf("if-else is Not OK \n \n");
		}
		else
		{
			printf("if-else is OK \n \n");
		}

	// 3- if, else if, else 
		printf("if, else if, if statement \n");
		if (x != 10)
		{
			printf("if, else if, is Not OK \n \n");
		}
		else if (x>=0)
		{
			printf("if, else if, else is OK \n \n");
		}
		else
		{
			printf("if, else if, else is Not Not OK \n \n");
		}
	
	// 4- if if
		printf("if if statement \n");
		if (x < 20)
		{
			printf("if-if 1 is OK \n");
		}
		if (x > 5)
		{
			printf("if-if 2 is OK \n \n");
		}
		
	// 5- Nested if (if(if))
		printf("Nested if (if(if)) statement \n");
		if (x != 5)
		{
			if (x > 5)
			{
				printf("Nested if (if(if)) is OK \n \n");
			}
		}
}