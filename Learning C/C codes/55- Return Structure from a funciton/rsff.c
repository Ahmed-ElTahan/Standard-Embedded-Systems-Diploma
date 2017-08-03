// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------

*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype


// Declared Structures
struct students{
	// elements
	int ID;
	float Age;
};

// Declared Functions
struct students Testing() // struct students can be though as a data type, so this function returns a structure of students defined above
{
	struct students ID_Age; // create a struct students with name ID_Age
	
	printf("Please assign Ahmed's ID: ");
	scanf("%d", &ID_Age.ID); 
	
	printf("Please assign Ahmed's Age: ");
	scanf("%f", &ID_Age.Age); 
	
	return ID_Age; // return the struct value
	
}
// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	struct students Ahmed; // declare a structure students to return the output of the Testing function 
	

	
	Ahmed = Testing(); // == Ahmed = ID_Age
	
	printf("Ahmed's ID is %d \n", Ahmed.ID);
	printf("Ahmed's Age is %f", Ahmed.Age); 
	// Write your instructions here.
	
	// infinite loop  while(1){}

	
	// Output
	
}