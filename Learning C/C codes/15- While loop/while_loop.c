// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program uses while loop to print numbers from 1 to 10 (incrementaion) & numbers from 10 to 1 (decrementation)
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int i;
	
	// Write your instructions here.
	printf("Printing numbers from 1 to 10 \n");
	i = 1; // IC
	while(i<=10)
	{
		printf("%d \t", i); // instructions
		
		i++; // action inc
	}
	
	
	printf("\n \nPrinting numbers from 10 to 1 \n");
	i = 10; // IC or as i quits with 11 from previous loop we want to start i with 10 --> i = i-1;
	while (i>0)
	{
		printf("%d \t", i); // instructions
		
		i--; // action dec
	}
	// Output
	
}