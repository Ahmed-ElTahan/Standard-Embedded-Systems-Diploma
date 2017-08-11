// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code illustrates how to return an address of a function and using pointer to store 
	the output of this function. ( Pointer as function return )
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define
// Type definition
// Function prototype
int* Add (int x, int y);
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	int* sum; // create a pointer variable to store the address returned from the function, must be the same as data type output of the function at the function declaration
	sum = Add(3, 4); // function call by itself
	printf("Result from calling the function using concept of (Pointer as function return) is: %d \n", *sum);
	
	
}

int* Add (int x, int y) 
{
	int z = x + y;
	int *ptr; // create a pointer to store the address of z
	ptr = &z; // let the pointer points to the var z
	return ptr; // return the address of z
}