// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code shows the concept of how to use pointer to pointer to pointer
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int a;
	a = 10;
	printf("Inintialization of a by itself = %d \n", a); // a
	printf("Address of a is %p \n", &a); // &a
	
	int* ptr1; // declaration pointer 1
	ptr1 = &a; // // put the address of a in value of pointer 1
	*ptr1 = 20; // change a uing pinter 1
	printf("Changing a by pointer 1 a = %d \n", *ptr1); // *ptr1 = a
	printf("Address of a using pointer 1 %p \n", ptr1); // ptr1 = &a
	printf("Address of pointer 1 %p \n", &ptr1); // &ptr1
	
	
	
	int** ptr2; // declaration pointer 2 to pointer 1
	ptr2 = &ptr1; // put the address of pointer 1 in value of pointer 2
	**ptr2 = 30; // change a uing pinter 2
	printf("Changing a by pointer 2 a = %d \n", **ptr2); // **ptr2 = a
	printf("Address of a using pointer 2 %p \n", *ptr2); // *ptr2 = ptr1 = &a
	printf("Address of pointer 1 using pointer 2 %p \n", ptr2); // ptr2 = &ptr1
	printf("Address of pointer 2 %p \n", &ptr2); // &ptr2
	
	int*** ptr3; // declaration pointer 3 to pointer 20
	ptr3 = &ptr2; // put the address of pointer 2 in the value of pointer 3
	***ptr3 = 40; // change the value of a using pointer 30
	printf("Changing a by pointer 3 a = %d \n", ***ptr3); // ***ptr3 = a
	printf("Address of a using pointer 3 %p \n", **ptr3); // **ptr3 = *ptr2 = ptr1 = &a
	printf("Address of pointer 2 using pointer 3 %p \n", ptr3); // ptr3 = &ptr2
	printf("Address of pointer 3 %p \n", &ptr3); // &ptr3
	
	
	// Write your instructions here.
	
	// Output
}