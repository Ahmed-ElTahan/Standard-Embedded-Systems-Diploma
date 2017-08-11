// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code is used to show how to use static storage	class.
	Static is used to make a variable (global or local) is defined only where the static is written.
	Cases:
	
			File1.c				File2.c				File3.c
			static int x; 		extern int x;		---------			compilation error
			static int x; 		int x;				---------			OK (the 2 x's are different)
			static int x; 		static int x;		int x;				OK
			static int x;		int x;				extern int x;		OK
			
	Application: used with recursive function to avoid re-initialization variables that declared at the beginning of the function (factorial)
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define
// Type definition
print2();
print3();
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
static int x = 1; // global static variable
// Enum

void main(void)
{	
	// Declaration and Inintialization
	// Write your instructions here.
	// infinite loop  while(1){}
	// Output
	printf("static global x from File1.c is %d \n", x);
	print2();
	print3();
}