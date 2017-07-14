// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program uses for loop to print numbers from 1 to 10 (incrementaion) & numbers from 10 to 1 (decrementation)
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int i;
	
	// Write your instructions here.
	printf("Printing numbers from 1 to 10 \n");
	for (i = 1; i<=10; i++)
	{
		printf("%d \t", i);
	}
	
	printf("\n \nPrinting numbers from 10 to 1 \n");
	for (i = 10; i>0; i--)
	{
		printf("%d \t", i);
	}
	// Output
	
}