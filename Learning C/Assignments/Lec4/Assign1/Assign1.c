// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
			Write a C program the implement 2 function: 

				1- Function to get the maximum of 4 values 
				2- Function to get the minimum of 4 values 

			The program will ask the user first to enter the 4 values, then print the maximum number and minimum number of them. 
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.

// Function prototype

// Declared Functions
int Get_max(int w, int x, int y, int z); // Getting maximum function
int Get_min(int w, int x, int y, int z); // Getting minimum function

// Global variables (Declaration and Inintialization)


void main(void)
{	
	// Declaration and Inintialization
	int no_1, no_2, no_3, no_4;
	int maxi, mini; // maximum and minimum vars to store the 2 functions' outputs
	
	// Write your instructions here.
		
		// get number 1
		printf("Please enter number 1: ");
		scanf("%d", &no_1);
		
		// get number 2
		printf("Please enter number 2: ");
		scanf("%d", &no_2);
		
		// get number 3
		printf("Please enter number 3: ");
		scanf("%d", &no_3);
		
		// get number 4
		printf("Please enter number 4: ");
		scanf("%d", &no_4);
		
		
		maxi = Get_max(no_1, no_2, no_3, no_4); // getting max through Get_max function call
		mini = Get_min(no_1, no_2, no_3, no_4); // getting min through Get_min function call
		
	// Output
	printf("The maximum number among the 4 entered numbers is: %d \n", maxi);
	printf("The minimum number among the 4 entered numbers is: %d", mini);
}