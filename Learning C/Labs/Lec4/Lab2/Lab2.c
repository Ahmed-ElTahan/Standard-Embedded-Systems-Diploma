// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write C code implement a function to swap 2 global variables.
*/




#include<stdio.h> // Library to include c functions for the compiler.

// Global variables (Declaration and Inintialization)
int x = 5;
int y = 10;

void Swap (int a, int b)
{
	int interchange;
	interchange = a; // first store x in another variable (interchange)
	a = b; // put y in x
	b = interchange; // return stored x value and store it in y
	
	// after swap
	printf("after swap, x = %d and y = %d", a, b);
		
}

main()
{	
	// Declaration and Inintialization
	
	// Write your instructions here.
	
	// before swap
	printf("before swap, x = %d and y = %d \n", x, y);
	Swap(x, y);


	// Output
	
}
