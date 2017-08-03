// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program shows how pointers are strongly typed. data type of pointer look at the same size of its data type bytes on the value which it points to.
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	//					byte#3      byte#2     byte#1     byte#0
 	int a = 1025; // [00000000]   [00000000] [00000100]  [00000001]
	
	int* ptr1;
	ptr1 = &a;
	printf("Value of a (integar 4 bytes) using pointer 1 (integar 4 bytes) is %d \n", *ptr1);
	
	char* ptr2;
	ptr2 = &a;
	printf("Value of a (integar 4 bytes) using pointer 2 (character 1 byte) is %d \n", *ptr2); // get data of 1st byte#0 (pointer char) of a (4 bytes) = 1
	
	ptr2++; // move one step (char 1 byte) --> 2nd byte of the a byte#1  = 4
	printf("Value of a (integar 4 bytes) using pointer 2 (character 1 byte) is after moving a step (1 byte) %d", *ptr2); // get data of 2nd byte#1 (pointer char) of a (4 bytes) = 4
	
	// Write your instructions here.
	
	// Output
	
}