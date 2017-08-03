// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------

*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Declared Structures
struct students{
	// elements
	int ID;
	float Age;
	
};
// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	struct students Eslam; // declare a structure
	struct students* ptr_to_Eslam; // declare a pointer to Eslame structure
	
	ptr_to_Eslam = &Eslam; // let the pointer points to Eslam's structure
	
	
	printf("Please assign Eslam's ID: ");
	scanf("%d", &(*ptr_to_Eslam).ID); // == scanf("%d", &ptr_to_Eslam->ID) (using arow operator) == scanf("%d", &Eslam.ID)
	
	printf("Please assign Eslam's Age: ");
	scanf("%f", &(*ptr_to_Eslam).Age); // == scanf("%d", &ptr_to_Eslam->Age) (using arow operator) == scanf("%d", &Eslam.Age)
	
	printf("Eslam's ID is %d \n", (*ptr_to_Eslam).ID); //  (*ptr_to_Eslam).ID == ptr_to_Eslam->ID == Eslam.ID
	printf("Eslam's Age is %f", (*ptr_to_Eslam).Age);  //  (*ptr_to_Eslam).ID == ptr_to_Eslam->ID == Eslam.ID
	// Write your instructions here.
	
	// infinite loop  while(1){}

	
	// Output
	
}