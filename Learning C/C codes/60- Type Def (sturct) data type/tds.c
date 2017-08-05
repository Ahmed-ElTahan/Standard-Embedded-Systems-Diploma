// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program shows how to use type def to define new name for struct data type
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Type definition
// Function prototype
// Declared Structures
typedef struct students 
{
	int ID;
	float Age;
}student;

// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	student Ahmed;
	Ahmed.ID = 10;
	Ahmed.Age = 22.5;
	
	printf("Ahmed's ID is %d \n", Ahmed.ID);
	printf("Ahmed's Age is %f \n", Ahmed.Age);
	// Write your instructions here.
	// infinite loop  while(1){}
	// Output
	
}