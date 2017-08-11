// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code used to show how to use conditional statements with macros (#define) (Conditional Directives)
	#if --- #elif (else if) --- #else --- #endif
	
						Macros								Variables
					#define x 10						int x = 10;
					#if x > 0							if ( x > 0)
						// code						 	{ 		}
					#elif x < 0							else if ( x < 0 )
						// code							{ 		}
					#else								else 
						// code							{ 		}
					#endif
					
					
					
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.
// User-defined header files #include
// User-defined header files #define 
#define x 10 
						// used to end #if.


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
		// Conditional Directives (inside main)
		#if x > 0
			printf("x i greater than"); // no need for curly brackets
			printf(" 0 ");				// no need for curly brackets
		#elif x < 0
			printf("x i less than");	// no need for curly brackets
			printf(" 0 ");				// no need for curly brackets
		#else
			printf("x i equal to");		// no need for curly brackets
			printf(" 0 ");				// no need for curly brackets
		#endif	
	
}