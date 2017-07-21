// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code that ask the user to enter 10 values and save them in an array using a for 
	loop. Then ask the user to enter a value to search about, if the value existing in the 10 
	values, the program will print “Value Exists x times” where x defines how many times the 
	value exists. If the value is not exist, the program will print “Value Not Exist”. Use 
	Linear Searching Algorithm. 
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int size = 10; 
	int array[10];
	int i; // counter
	int input; // to search for
	int rep = 0; // to count repeatitions
	
	// Write your instructions here.
		
		// filling the array
		for (i = 0; i < size; i++)
		{
			printf("Please enter number %d: ", (i + 1));
			scanf("%d", &array[i]);
		}
		
		// the value you want to search for
		printf("Please enter number you want to search for: ");
		scanf("%d", &input);
		
		for (i = 0; i < size; i++)
		{
			if (array[i] == input)
			{
				rep = rep + 1;
			}
		}
		
	// Output
	if (rep != 0 )
	{
		printf("Value exists %d times \n", rep);
	}
	
	else
	{
		printf("Value Not Exist");
	}
}