// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
		Write C code that will ask the user to enter 2 numbers, then the main function will call a 
		function named Get_Max that takes the 2 values entered by the user then return the 
		maximum of them. The main function then will print the returned value 
*/


#include<stdio.h> // Library to include c functions for the compiler.

// function declaration and body
int Get_Max(int no_1, int no_2)
{
	int max;
	
	max = no_1; // initially
	
	if(max<=no_2)
	{
		max = no_2;
	}
	
	return max;
}

main()
{	
	// Declaration and Inintialization
	int func_output; // function output to be stored in
	int x, y;
	// Write your instructions here.
	
	// no_1
	printf("Please enter no_1: ");
	scanf("%d", &x);

	// no_2
	printf("Please enter no_2: ");
	scanf("%d", &y);
	
	
	func_output = Get_Max(x, y); // function call

	// Output
	printf("maximum of number 1 and 2 is: %d", func_output);

	
}