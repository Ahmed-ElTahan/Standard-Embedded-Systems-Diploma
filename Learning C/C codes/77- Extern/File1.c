// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code is used to show the usage of extern storage class
	extern is used with global variables only. It is used when we want to use a variable defined in 
	, for example File1.c in, for example, File2.c and File3.c --> you define it once and extern it 
	where you want to use at.
	Suppose, a global variable is declared in file1. If you try to use that variable in a different file file2,
	the compiler will complain. To solve this problem, keyword extern is used in file2 to indicate that the external
	variable is declared in another file
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define
// Type definition
// Function prototype
print2();
print3();
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
int x = 10; // to be extern, must be a global variable
// Enum


void main(void)
{	
	// Declaration and Inintialization
	// Write your instructions here.
	// infinite loop  while(1){}
	// Output
	printf("x from File1.c is %d \n", x);
	print2();
	print3();
	
}