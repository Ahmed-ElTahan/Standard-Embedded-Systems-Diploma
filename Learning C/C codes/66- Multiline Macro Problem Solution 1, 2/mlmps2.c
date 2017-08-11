// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Problem of Multiline code:
	cosider the following piece of code:
		if(x == 10)
			printf();
		
		else 
			printf("I am in else");
		
	After the preprocessing step will be:
		if(x == 10)
			printf("I"); 
			printf("Like"); 
			printf("IMT"); 
		
		else 
			printf("I am in else");
		
		will give a compilation error: else without if
		
	Solution number 2: use do while(0) to convert multiline code into one statement, 0 is a false condition, but do while will do it once (do while(false) rule)
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.
// User-defined header files #include
// User-defined header files #define
# define print() 	do { printf("I"); \
						 printf("Like"); \
						 printf("IMT"); \
					   } while(0) // no semicolon at the end
					
// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	int x = 10;
	// Write your instructions here.
	// infinite loop  while(1){}
	// Output
	if (x == 10) // if these 2 brackets after if are not here, put do while(0). Otherwise, compilation error: else without if
		print(); /* do { printf("I"); \
						 printf("Like"); \
						 printf("IMT"); \
					   } while(0)
				 */

	else
	{
		printf("I am in else");
	}
}