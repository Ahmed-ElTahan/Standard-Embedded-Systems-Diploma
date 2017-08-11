// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code used macros to show set, clear, or toggle a bit
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define (Macros: Object / Fuction)
#define set_bit(x, pn)	x = x | ( 1 << pn )  		// set bit #pn at register x
#define clr_bit(x, pn)	x = x & ( ~ ( 1 << pn ) )  	// clear bit #pn at register x
#define tog_bit(x, pn)	x = x ^ ( 1 << pn )  		// toggle bit #pn at register x

// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	unsigned char x;
	
	// Write your instructions here.
		// set bit
			x = 4; // 0000 0100
			set_bit(x, 3); // 0000 1100 == 12
			printf("x=4 after setting bit  #3 is: %d \n", x);
			
		// clear bit
			x = 4; // 0000 0100
			clr_bit(x, 2); // 0000 0000 == 0
			printf("x=4 after clearing bit #2 is: %d \n", x);
			
		// toggle bit
			x = 4; // 0000 0100
			tog_bit(x, 0); // 0000 0101 == 5
			printf("x=4 after toggling bit #0 is: %d \n", x);
			
			
	// infinite loop  while(1){}
	// Output
	
}