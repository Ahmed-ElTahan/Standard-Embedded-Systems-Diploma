// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program used to show the usage of (continue) and (break)
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int i;
	
	// Write your instructions here.
	printf("Printing numbers from 1 to 10 skipping (continue) 5 and break at 7 \n");
	for (i = 1; i<=10; i++)
	{
		if (i==5)
		{
			continue;
		}
		
		if (i==8)
		{
			break;
		}
		printf("%d \t", i);
	}
	// Output
	
}