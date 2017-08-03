// This code is created by Ahmed A. Eltahan
// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Wirte a C code to take 10 values from the user and check if there are array that are repeated and give how many times each is repeated if any
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int i; // counter 1
	int j; // counter 2
	int size = 10; // number of elements
	int array[10]; // array declaration
	int rep[10]; // array used to count number of repeatitions
	int sw = 0; // check for repeatition if sw == 1 --> there is at least one repeatition, if sw == 0 --> nothing is repeated
	int val_agree = -1000; // value we agree to put in a specific place
	// Write your instructions here.
	
		// filling the array by the user
		for ( i = 0; i < size; i++ )
		{
			printf("Please enter number %d : ", ( i + 1 ));
			scanf("%d", &array[i]);
			rep[i] = 1; // By intuition, each number entered exists at least once, if something repeated, add 1 each time you found it.
		}
		
		// compare element 1 to 2, then 1 to 3, ... 1 to 10. Then 2 to 3 (as 2 is compared to 1), then 2 to 4, ..., 2 to 10, .... till 9 to 10 --> using the 2 for loops
		// the idea here is that choose a value (we agree on, let here val_agree = -1000) to put it at places where the number i is repeated so we dont count them repeated again as the condition
		// if (rep[j + 1] == val_agree) {continue;}  but add the repeatition number to it as rep[i] = rep[i] + 1 
		for ( i = 0; i < size; i++ )
		{	
			for (j = i; j < size - 1; j++) // -1 is because (jth + 1) element
			{
				if (array[i] == array[j + 1]) 
 				{	
					if (rep[j + 1] == val_agree)
					{
						continue;
					}
					rep[i] = rep[i] + 1;
					rep[j + 1] = val_agree;
					sw = 1; // there is a repeatition
				}
			}
			if ((rep[i] != 1) && (rep[i] != val_agree)) // there is repeatition and dont count places we put there val_agree as we skipped them by continue, we only need the place where rep[i] is more than 1
			{
				printf("Number %d is repeated %d times \n", array[i], rep[i]);
			}
						
		}
			
		if (sw == 0)
		{
			printf("Nothing is repeated");
		}			
	// Output
	
}