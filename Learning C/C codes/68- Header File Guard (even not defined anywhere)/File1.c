// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code illustrates the concept of using header file guard to avoid multiple inculsion of
	user-defined header files. Note: the name of the header file (with _h ) is not refered to the
	corresponding same name header file (with .h) as we inculde the contents of the header file 
	after #define each time we write the header file guard.
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// header file guard
	#ifndef header_h
	#define header_h
	int x; // header file content
	#endif

// User-defined header files #include
// User-defined header files #define
// Type definition
// Function prototype
void print();
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	
	// Declaration and Inintialization
	// Write your instructions here.
	x = 10; // defined in the header file guard
	print(); // declared in File2.c
	// infinite loop  while(1){}
	// Output
	
}
