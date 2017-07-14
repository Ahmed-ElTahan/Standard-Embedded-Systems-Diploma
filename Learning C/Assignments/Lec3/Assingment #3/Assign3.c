// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a c program that draw a pyramid of stars with height entered by the user
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int height; // height of pyramid
	int i; // row counter 
	int j; // column conter
	
	// Write your instructions here.
	printf("Please enter the height of the pyramid: ");
	scanf("%d", &height);
	
	for ( i = 1; i<= height; i++)
	{
		// printing empty places depending on the column and height, note at ith row = jth column there is a star. as we move to next row we leave less empty places and that is why we start j = 1 and end for before j = height
		for (j = i; j<height; j++)
		{
			printf(" ");
		}

		// printing stars
		for (j = 1; j<=(2*i-1); j++) // ith row corresponding to (2*i-1) stars
		{
			printf("*");
		}
		
		printf("\n");
	}		
	// Output
	
}