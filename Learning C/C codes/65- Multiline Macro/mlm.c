// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code shows that a macro can be replaced with a multiline code
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.
// User-defined header files #include
// User-defined header files #define
# define print() 	printf("I"); \
					printf("Like"); \
					printf("IMT")		// No ; at the end					
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
	print(); /*  == printf("I"); \
				    printf("Like"); \
			        printf("IMT") 
			  */
	
}