// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code shows the relationship between pointers and arrays
	In conculsion: when pointer to array, we deal with both by the same use.
	
					Values (method 1)	Values (method 2)		Address
	Pointer				*(ptr + i)			ptr[i]				ptr + i		
	Array				*(arr + i)			arr[i]				arr + i
*/

// Libraries
#include<stdio.h> // Library to include Basic C functions for the compiler.

// User-defined header files #include
// User-defined header files #define
// Type definition
// Function prototype
// Declared Structures (if Type definition)
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
		int i; // counter
		int arr[5] = {1, 2, 3, 4, 5};
		int noe = sizeof(arr) / sizeof(arr[0]);
		int* ptr;
		ptr = &arr[0]; // == (ptr = arr;) --> this means let the ptr points to the 1st location of arr
		
	// Write your instructions here.
		// Getting / Accessing the values of The array using ptr
			// method 1 --> *(ptr + i)
				printf("Values of The array using pointer ptr method 1 --> *(ptr + i) is: \n");
				for (i = 0; i < noe; i++)
				{
					printf("%d \t", *(ptr + i));
				} 
				printf("\n");
			
			// method 2 --> ptr[i]
				printf("Values of The array using pointer ptr method 2 --> ptr[i] is: \n");
				for (i = 0; i < noe; i++)
				{
					printf("%d \t", ptr[i]);
				}
				printf("\n");
				
		// Getting / Accessing the values of The array using arr
			// method 1 --> *(arr + i)
				printf("Values of The array using array arr method 1 --> *(arr + i) is: \n");
				for (i = 0; i < noe; i++)
				{
					printf("%d \t", *(arr + i));
				} 
				printf("\n");
			
			// method 2 --> arr[i]
				printf("Values of The array using array arr method 2 --> arr[i] is: \n");
				for (i = 0; i < noe; i++)
				{
					printf("%d \t", arr[i]);
				}
				printf("\n");
					
		// Getting the address of The array 
			// Using Pointer ptr --> ptr + i
				printf("Address of The array using pointer ptr method 1 --> ptr + i is: \n");
				for (i = 0; i < noe; i++)
				{
					printf("%p \t", ptr + i);
				} 
				printf("\n");
			
				// Using  Array arr --> arr + i
				printf("Address of The array using array arr method 1 --> arr + i is: \n");
				for (i = 0; i < noe; i++)
				{
					printf("%p \t", arr + i);
				} 
				printf("\n");
				
	printf("In conculsion: when pointer to array, we deal with both by the same use \n");
			
				
	// infinite loop  while(1){}
	// Output
	
}