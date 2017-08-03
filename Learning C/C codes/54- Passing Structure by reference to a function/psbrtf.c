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
void Printing(struct students* ID_Age)
{
	printf("Ahmed's ID is %d \n", ID_Age->ID); // (*ID_Age).ID == ID_Age->ID
	printf("Ahmed's Age is %f", ID_Age->Age); // (*ID_Age).Age == ID_Age->Age
}
// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	struct students Ahmed; // declare a structure	
	
	printf("Please assign Ahmed's ID: ");
	scanf("%d", &Ahmed.ID); 
	
	printf("Please assign Ahmed's Age: ");
	scanf("%f", &Ahmed.Age); 
	
	Printing(&Ahmed); // pass all elements of Ahmed structure to ID_Age structure (struct students* ID_Age = &Ahmed)
	

	// Write your instructions here.
	
	// infinite loop  while(1){}

	
	// Output
	
}