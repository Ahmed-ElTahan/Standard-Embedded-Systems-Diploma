// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	this code illustrates the idea to swap two numbers
*/


#include<stdio.h> // Library to include c functions for the compiler.



void Swap (int x, int y)
{
	int interchange;
	interchange = x; // first store x in another variable (interchange)
	x = y; // put y in x
	y = interchange; // return stored x value and store it in y
	
	// after swap
	printf("after swap, x = %d and y = %d", x, y);
		
}

main()
{	
	// Declaration and Inintialization
	int x = 5;
	int y = 10;
	
	// Write your instructions here.
	
	// before swap
	printf("before swap, x = %d and y = %d \n", x, y);
	Swap(x, y);


	// Output
	
}
