// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program shows the usage of structures, how to define, declare, access elements, assign values, and print their data 
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions

// Declared Structures
struct employees
{
	// elements
	int ID;
	float salary;
	float age;
};
	

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	struct employees Ahmed; // declare Ahmed to employees structure and reserve a place in the memory for (4+4+4) = 12 bytes
	struct employees Mohamed; // declare Mohmamed to employees structure and reserve a place in the memory for (4+4+4) = 12 bytes
	
	// Write your instructions here.
		// Assign values to structure
		Ahmed.ID = 3;
		Ahmed.salary = 2000.6;
		Ahmed.age = 28.5;
		
		// use scanf to assign Mohamed's data
		printf("Please enter Mohamed's ID: ");
		scanf("%d", &Mohamed.ID);
		printf("Please enter Mohamed's salary: ");
		scanf("%f", &Mohamed.salary);
		printf("Please enter Mohamed's age: ");
		scanf("%f", &Mohamed.age);
	
		// printing Ahmed's and Mohamed's structure data uing printf
		printf("Ahmed's ID is %d, Mohmamed's ID is %d \n", Ahmed.ID, Mohamed.ID);
		printf("Ahmed's salary is %f, Mohmamed's salary is %f \n", Ahmed.salary, Mohamed.salary);
		printf("Ahmed's age is %f, Mohmamed's age is %f \n \n", Ahmed.age, Mohamed.age);
		
		printf("The size of the employees structure is %d", sizeof(Ahmed)); // or Mohamed
		
		// note: if write Mohamed = Ahmed --> all data elemets of Ahmed will be assigned to Mohamed
		
	// infinite loop  while(1){}
	
	
	// Output
	
}