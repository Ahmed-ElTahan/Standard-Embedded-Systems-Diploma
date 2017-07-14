// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a code that will ask the user to enter 3 numbers, the program will print the maximum number of them.
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int no_1, no_2, no_3;
	int max_1; // maximum found by method 1
	int max_2; // maximum found by method 2
	
	// Write your instructions here.
	printf("Enter number 1: ");
	scanf("%d", &no_1); // get number 1 from the user
	
	printf("Enter number 2: ");
	scanf("%d", &no_2); // get number 2 from the user
	
	printf("Enter number 3: ");
	scanf("%d", &no_3); // get number 3 from the user
	
	// Method 1
		max_1 = no_1; // initially
		
		if (max_1<=no_2) // compare max_1 = no_1 to no_2
		{
			max_1 = no_2; 		
		}
		
		if (max_1<=no_3) // compare max_1 = max_1(no_1 or no_2) to no_3
		{
			max_1 = no_3;
		}
	
	// Method 2
		if( (no_1>=no_2) && (no_1>=no_3) ) // compare no_1 to both no_2 & no_3
		{
			max_2 = no_1;
		}
	
		else if( (no_2>=no_3) && (no_2>=no_1) ) // if previous not correct, compare no_2 to both no_1 and no_3
		{
			max_2 = no_2;
		}
		
		else // if previous not correct, then no_3 is the maximum
		{
			max_2 = no_3;
		}
	
	// Output
	printf("Maximum number using method 1 is %d \n", max_1); // maximum found by method 1
	printf("Maximum number using method 2 is %d \n", max_2); // maximum found by method 2
}