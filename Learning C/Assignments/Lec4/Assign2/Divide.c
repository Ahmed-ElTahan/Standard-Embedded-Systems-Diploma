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

// Declared Functions
int Divide()
{
	int op1, op2; // operands 1 and 2
	int div; // result
	
	// get operand 1
	printf("Please enter operand 1: ");
	scanf("%d", &op1);
	
	// get operand 2
	printf("Please enter operand 2: ");
	scanf("%d", &op2);

	div = op1 / op2;
	
	return div;
	
}


