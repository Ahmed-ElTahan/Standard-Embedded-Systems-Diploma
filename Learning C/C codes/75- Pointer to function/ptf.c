// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code explains the concept of using pointer to points to a function (other name of the function)
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define
// Type definition
// Function prototype
int Add (int x, int y);
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	int sum; 
	sum = Add(3, 4); // function call by itself
	printf("Result from calling the function itself is: %d \n", sum);
	
	int (*ptr) (int, int); // Pointer to function that takes 2 int inputs
	ptr = &Add; // Assign ptr to point to the function Add  == ptr = Add;
	sum = (*ptr)(3, 4); // function call by pointer == sum = ptr(3, 4);
	printf("Result from calling the function using pointer is: %d", sum);
	// Write your instructions here.
	// infinite loop  while(1){}
	// Output
	
}

int Add (int x, int y)
{
	int z = x + y;
	return z;
}