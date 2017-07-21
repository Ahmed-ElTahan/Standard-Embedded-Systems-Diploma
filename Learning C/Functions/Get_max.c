// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	this is a function used to get the maximum of a given array, its inputs are the size of the array and the array itself

*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

int Get_max(int size, int array[])
{
	int i; // counter
	int max = array[0]; // initially
	
	for (i = 0; i < size - 1; i++)
	{
			if (array[i+1] > max)
			{
				max = array[i+1];
			}
	}
	
	return max;
}