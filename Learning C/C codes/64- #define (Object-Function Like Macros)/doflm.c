// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program is used to illustrate the usage of #define command with both (Object/Functino)
	Like Macros showing all possible cases
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.
// User-defined header files #include
// User-defined header files #define
#define x 100 // Object Like Macro, replace each standing alone x (not within quotation marks or part of var name) with 100 (no ; at the end)
#define Add(x, y) 	x + y // Function Like Macro because of round bracket (no ; at the end)
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
	
		// Object Like Macro
		printf("Object Like Macro \n");
			// example 1;
			int y = x; // == int y = 100;
			printf("y = %d \n", y);
			
			// example 2;
			printf("The value of x is %d \n", x); // == printf("The value of x is \n", 100); 
			
			// example 3;
			int yx = 50; // == int yx = 50;
			printf("y = %d \n \n", y);
			
			// example 4: compilation error
				// int x = 50; // == int 50 = 100;
		
		// Function Like Macro
		printf("Function Like Macro \n");
		int z = Add(3, 4); // == int z = 3 + 4
		printf("Addition result is %d", z);
		
		
		
	// infinite loop  while(1){}
	// Output
	
}