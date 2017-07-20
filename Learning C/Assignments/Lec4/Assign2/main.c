// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C program to act as simple calculator, first it will ask the user to enter the 
	operation ID, depending on the operation, the program will ask the user either to 
	enter 1 operand or 2 operands and the program will execute the operation and print 
	the result. Each operation should be implemented in a stand a long function. 

	ID 		Operation 		Number of Operands
	
	1 		Add 					2 
	2 		Subtract 				2 
	3 		Multiply				2 
	4 		Divide 					2 
	5 		And 					2 
	6 		Or 						2 
	7 		Not 					1 
	8 		Xor 					2 
	9 		reminder 				2 
	10 		Increment 				1 
	11 		Decrement 				1 
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype
int Add();
int Subtract();
int Multiply();
int Divide();
int And();
int Or();
int Not();
int Xor();
int reminder();
int Increment();
int Decrement();

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	
	int O_ID; // operation ID
	int x, y; // inputs
	int result; // function output
	
	// Write your instructions here.
	
		// get the operation ID
		printf("Pleasd Enter the Operation's ID: ");
		scanf("%d", &O_ID);
		
		// Switch case on the operation
		switch(O_ID)
		{
			case 1:
			result = Add();
			break;
			
			case 2:
			result = Subtract();
			break;
			
			case 3:
			result =  Multiply();
			break;
			
			case 4:
			result = Divide();
			break;
			
			case 5:
			result = And();
			break;
			
			case 6:
			result = Or();
			break;
			
			case 7:
			result = Not();
			break;
			
			case 8:
			result = Xor();
			break;
			
			case 9:
			result = reminder();
			break;
			
			case 10:
			result = Increment();
			break;
			
			case 11:
			result = Decrement();
			break;
			
			default:
			printf("Please enter a valid ID between 1 and 11 up to the program description table");
			break;
		}
	
	// Output
	printf("The result of the operation is: %d", result);
}