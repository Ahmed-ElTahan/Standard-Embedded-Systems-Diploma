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
		3- number of elements of the array is calculated inside the function for the for loop to
		do the summation --> summation will take place with the calculated noe which is 1 time
		because as int arr[] == int* arr --> arr is an int pointer and hence sizeof(arr) == sizeof(int)
		4- In conclusion: the code gives a wrong summation result because we calculate noe inside it.
		
		Always pass the number of elements of the array you want to pass to a fucntion
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define
// Type definition
// Function prototype
int Sum_of_Elements(int arr[]);

// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	int total = 0;
	int array[] = {1, 2, 3, 4, 5};
	
	// Write your instructions here.
	total = Sum_of_Elements(array); // (int noe = noe), (int arr[] = array),but (int arr[] == int* arr)
										 //so, (int* arr = array) == (int* arr = &array[0])
	
	printf("Total is %d \n", total);
	printf("Always pass the number of elements of the array you want to pass to a fucntion");
	
	// infinite loop  while(1){}
	// Output
	
}

int Sum_of_Elements(int arr[])
{
	int i; // counter
	int sum = 0; // summation variable
	int noe = sizeof(arr) / sizeof(arr[0]); // arr is an int pointer and hence sizeof(arr) == sizeof(int) --> noe = 1

	for (i = 0; i < noe; i++)
	{
		sum = sum + arr[i]; // arr is a pointer, arr[i] can access the array values
	}
	
	return sum;
}