// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a code that scan 3 numbers from the user and print them in reversed order
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int no_1;
	int no_2;
	int no_3;
	
	// Write your instructions here.
	printf("Please enter number 1:");
	scanf("%d", &no_1); // get number 1
	
	printf("Please enter number 2:");
	scanf("%d", &no_2); // get number 2
	
	printf("Please enter number 3:");
	scanf("%d", &no_3); // get number 3
	
	// Output in a reversed order
	printf("number 3 is: %d \n", no_3);
	printf("number 2 is: %d \n", no_2);
	printf("number 1 is: %d \n", no_1);
	
	
}