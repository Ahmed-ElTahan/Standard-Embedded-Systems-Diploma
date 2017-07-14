// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a program in C to display the multiplication table of a given integer. 
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int input;
	int multp; // mutiplcation variable store
	int i; // counter
	int fi = 12; // final multiplcation number in the multiplcation table
	// Write your instructions here.
	printf("Enter the number to display its mutliplication table: ");
	scanf("%d", &input);
	
	for (i = 1; i<= fi; i++)
	{
		multp = i*input; // multiplication result
		printf("%d * %d = %d \n", input, i, multp); // print each mutliplication process till fi
	}
	// Output
	
}