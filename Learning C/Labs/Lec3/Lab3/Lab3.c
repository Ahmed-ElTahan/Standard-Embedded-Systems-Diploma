// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a program in C to get the number of numbers from the user to be processed then, find their summation and average
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int i; // counter
	int no_inputs; // number of inputs
	int no; // input number
	int sum = 0; // summation
	float avg = 0.0; // average number
	
	// Write your instructions here.
	printf("Please enter how many numbers you want to get their sum and average: ");
	scanf("%d", &no_inputs); // get the number from the user

	for (i=1; i<=no_inputs; i++)
	{	
		printf("Please enter number %d: ", i);
		scanf("%d", &no); // get the number from the user
		sum = sum + no; // each loop add the number you get to the previous numbers in sum
	}
	
	avg = sum / (i-1.0); // or avg = sum / no_inputs
	
	// Output
	printf("summation = %d \n", sum); // print summation result
	printf("average = %f", avg); // print average result
	
	
}