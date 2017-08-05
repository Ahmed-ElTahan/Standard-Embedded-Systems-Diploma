// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code illustrates the main function of using header files. Header file is just a text
	replacemnt (without check), so it can contain any text. Here, func1_declaration.h has a declaration
	of a function. func2_prototype.h contains a function prototype. Finally, miscellaneous.h contains 
	declaration of a variable x
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.
// User-defined header files
#include"func1_declaration.h"
#include"func2_prototype.h"
#include"miscellaneous.h"

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
	func1(); // Declaration and Body in func1_declaration.h
	func2(); // Declaration and Body after main(). Its prototype in func2_prototype.h
	printf("x = %d", x); // x is declared in miscellaneous.h (will be global variable)
	
}

 void func2()
 {
	 printf("My name is Ahmed A. Eltahan \n");
 }