// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
			Write a C program the implement 2 function: 

				1- Function to get the maximum of 4 values 
				2- Function to get the minimum of 4 values 

			The program will ask the user first to enter the 4 values, then print the maximum number and minimum number of them. 
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.


// Declared Functions
int Get_max(int w, int x, int y, int z)
{
	int max;
	if ( (w > x) && ( w > y ) && ( w > z ) )
	{
		max = w;
	}
	
	else if ( (x > w) && ( x > y ) && ( x > z ) )
	{
		max = x;
	}
	
	else if ( (y > w) && ( y > x ) && ( y > z ) )
	{
		max = y;
	}
	
	else
	{
		max = z;
	}
	
	return max;
}
