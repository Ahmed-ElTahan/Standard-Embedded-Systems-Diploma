// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code explains how to use array as a function argument (input). Note that:
		1- when defining an array as an input to a function, it is not passed by value. In
		other words, not all the elements of the array input are passed to the stack of the 
		function, but it is passed by reference --> int arr[] == int* arr
		2- As the array input is passed by reference --> int arr[] == int* arr = array
		arr is pointing to the first element of the array as the same as if we say
		int* arr = &array[0].
		3- number of elements of the array is passed to the function for the for loop to
		do the summation --> summation will take place with the passed noe which is 5 times
		4- In conclusion: the code gives the right summation result as we passed noe to it
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define
// Type definition
// Function prototype
int Sum_of_Elements(int noe, int arr[]);

// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	int total = 0;
	int array[] = {1, 2, 3, 4, 5};
	int noe = sizeof(array) / sizeof(array[0]); // number of elements = 5
	
	// Write your instructions here.
	total = Sum_of_Elements(noe, array); // (int noe = noe), (int arr[] = array),but (int arr[] == int* arr)
										 //so, (int* arr = array) == (int* arr = &array[0])
	printf("Total is %d \n", total);
	printf("Always pass the number of elements of the array you want to pass to a fucntion");
	
	// infinite loop  while(1){}
	// Output
	
}

int Sum_of_Elements(int noe, int arr[])
{
	int i; // counter
	int sum = 0; // summation variable
	for (i = 0; i < noe; i++) // 5 loops
	{
		sum = sum + arr[i]; // arr is a pointer, arr[i] can access the array values
	}
	return sum;
}