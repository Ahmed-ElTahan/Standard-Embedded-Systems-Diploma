// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This code shows how to create a virtual array and define the number of its elements as 
	runtime number using malloc function.
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.
#include<stdlib.h> // to include malloc/calloc function

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
	int noe; // number of elements
	int i; // counter
	int* ptr; // used to get the address output of malloc function
	
	// Write your instructions here.

	printf("Please enter the number of elements of the array: ");
	scanf("%d", &noe); // get the number of elements of the array 
	
	/* allocate (noe * sizeof(int)) bytes and make the address output
	of the malloc function points to int* data type (type casting), the
	returning address is the address of the 1st int element of the memory
	allocated in Heap --> like I defined an array (virtual array)*/
	ptr = (int*) malloc(noe * sizeof(int)); // takes 1 variable input
	
		// Outputing virtual array elements using ptr[i] Before filling (Inintialization of Garbage vaules)
			printf("Array elements using ptr[i] before filling are grabage values as: \n");
			for (i = 0; i < noe; i++)
			{
				printf("%d \t",ptr[i]);
			}
			printf("\n \n");

	// Filling the virtual array: Access the values using the defined pointer using: 1- ptr[i] || 2- *(ptr + i)     i = 0, 1, 2, ..., (noe - 1) 
	for (i = 0; i < noe; i++)
	{
		printf("Please enter number %d: ", (i +1));
		scanf("%d", &ptr[i]); // == scanf("%d", &*(ptr + i));
	}
	// infinite loop  while(1){}
	// Output
	
			// method 1 --> accessing the virtual elements using ptr[i]
			printf("Array elements using ptr[i] are: \n");
			for (i = 0; i < noe; i++)
			{
				printf("%d \t",ptr[i]);
			}
			
			printf("\n \n");
			
			// method 2 --> accessing the virtual array elements using *(ptr + i)
			printf("Array elements using *(ptr + i) are: \n");
			for (i = 0; i < noe; i++)
			{
				printf("%d \t",*(ptr + i));
			}
	free(ptr); // to deallocate Heap memory
}