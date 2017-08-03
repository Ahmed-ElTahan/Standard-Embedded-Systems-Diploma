// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code is implementing bubble sorting algorithm (Descending Order)
	v1 : using loops on all possiblities
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int i; // counter 1 for outer loop, how many times we apply the swap searching loop
	int j; // counter 2 for inner loop, how many times we apply swap
	int size = 10; // number of elements
	int array[10]; // array declaration
	int interchange; // variable of swaping

	// Write your instructions here.
	
		// filling the array by the user
		for ( i = 0; i < size; i++ )
		{
			printf("Please enter number %d : ", ( i + 1 ));
			scanf("%d", &array[i]);
		}
		
	for (i = 0; i <= (size - 2); i++) // need (size - 2) outer loops for repeatition of the swap searching loop, complete searching
	{
			for (j = 0; j <= (size - i -1); j++) // (-1) because the (jth + 1) element, (-i) is for leave checking of the last element each loop as it complies the condition
			{
				// swaping part
				if (array[j] < array[j+1])
				{		
					interchange = array[j]; // first store x in another variable (interchange)
					array[j] = array[j+1]; // put y in x
					array[j+1] = interchange; // return stored x value and store it in y
				}
			}
				
	}		
	
	// Output
	printf("Array after descending sorting is : \n ");
	for (i = 0; i <size; i++)
		{
			printf("%d \t", array[i]);
			
		}
}