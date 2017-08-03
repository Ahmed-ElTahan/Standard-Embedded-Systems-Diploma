// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code intends to 
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int choice;
	unsigned char chr;
	
	// Write your instructions here.
	printf("This program converts between ASCII <-> Decimal \n");
	printf("Choose: \n");
	printf("1- Convert from Decimal to ASCII \n");
	printf("2- Convert from ASCII to Decimal \n \n");
	printf("Your choice: ");
	scanf("%d", &choice);
	
	switch (choice)
	{
		// Convert from Decimal to ASCII
		case 1:
		printf("Please enter an ASCII symbol (without quotation): ");
		fflush(stdin); // used to enforce the compiler not to pass scanf with %c, put before scanf
		scanf("%c", &chr);
		printf("Your decimal according to ASCII table %d", chr);
		break;
		
		// Convert from ASCII to Decimal
		case 2:
		printf("Please enter a decimal number: ");
		scanf("%d", &chr);
		printf("Your ASCII symbol according to ASCII table %c", chr);
		break;
		
		// Other than 1 or 2
		default:
		printf("Please enter 1 or 2: ");
		break;
			
	}
	
	// Output
	
}