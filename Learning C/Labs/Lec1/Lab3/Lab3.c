// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------

*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int no_1;
	int no_2;
	int sum, multp;
	
	// Write your instructions here.
	printf("Please enter number 1: ");
	scanf("%d", &no_1); // get number 1
	
	printf("Please enter number 2: ");
	scanf("%d", &no_2); // get number 2
	
	sum = no_1 + no_2; // summation
	multp = no_1 * no_2; // multiplication
	
	// Output
	printf("a + b = %d \n", sum);
	printf("a * b = %d \n", multp);
}