// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
		Write C code that ask will ask the user to enter the result of 3 x 4, In case the user entered correct answer the program will print Thanks,
		otherwise the program will print try again until the user enters the correct answer 
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int input;
	
	// Write your instructions here.
	printf("Enter the answer of 3 * 4 = ");
	scanf("%d", &input);
	
	while (input != 12) // loop will loop till correct answer 12 is typed
	{
		printf("Not correct, Please try again: ");
		scanf("%d", &input);
	}
	
	printf("Thank You :) "); // as while loop is breaked by correct answer
	// Output
	
}