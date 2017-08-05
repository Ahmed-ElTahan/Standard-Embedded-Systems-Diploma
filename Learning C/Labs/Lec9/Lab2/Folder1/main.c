// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	case 4: the header file 1 is outer of the source file while header file 2 is inner of the 
	source file. 
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.
// User-defined header files
#include"../function1.h" // inculde outer header file
#include"Folder2/function2.h" // include inner header file

// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	// Write your instructions here.
	// infinite loop  while(1){}
	// Output
	print1(); // declared in function1
	print2(); // declared in function2
	
}