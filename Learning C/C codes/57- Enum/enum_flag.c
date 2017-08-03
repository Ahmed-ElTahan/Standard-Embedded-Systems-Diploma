// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program is used to show an example of enum as a flag in C
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype
// Declared Structures
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum
	enum designFlags {
		BOLD = 1,
		ITALICS = 2,
		UNDERLINE = 4
	};
void main(void)
{	
	// Declaration and Inintialization
    
	// Write your instructions here.
	int myDesign = BOLD | UNDERLINE; 

        //    00000001
        //  | 00000100
        //  ___________
        //    00000101

	printf("%d means both bold and underline are used", myDesign);		
	// infinite loop  while(1){}
	// Output
	
}