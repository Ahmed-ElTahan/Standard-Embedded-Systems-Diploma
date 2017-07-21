// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	this is a function used to get the minimum of a given array, its inputs are the size of the array and the array itself

*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

int Get_min(int size, int array[])
{
	int i; // counter
	int min = array[0]; // initially
	
	for (i = 0; i < size - 1; i++)
	{
			if (array[i+1] < min)
			{
				min = array[i+1];
			}
	}
	
	return min;
}