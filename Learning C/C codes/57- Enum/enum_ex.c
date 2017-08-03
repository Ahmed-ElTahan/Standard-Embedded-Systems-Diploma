// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program is used to show an example of enum
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype
// Declared Structures
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum
enum week { sunday, monday, tuesday, wednesday, thursday, friday, saturday };


void main(void)
{	
	// Declaration and Inintialization
	enum week today; // enum week variable
    
	// Write your instructions here.
	today = wednesday;
    printf("Day %d \n",today+1);
	printf("Enum variable takes only one value out of many possible values. \n");
	printf("Size of enum variable = %d bytes", sizeof(today));		
	// infinite loop  while(1){}
	// Output
	
}