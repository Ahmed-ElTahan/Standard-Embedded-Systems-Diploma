// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
		Write a C code that ask the user to enter 10 numbers, then ask him to enter another number to search on it in the 10 numbers and print its 
		location in case it is found. In case the number is not found, it will print number no exist 
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int no_1, no_2, no_3, no_4, no_5, no_6, no_7, no_8, no_9, no_10;
	int no_se; // number to be entered for search
	
	// Write your instructions here.
	
	printf("Enter number 1: ");
	scanf("%d", &no_1); // get number 1 from the user
	
	printf("Enter number 2: ");
	scanf("%d", &no_2); // get number 2 from the user
	
	printf("Enter number 3: ");
	scanf("%d", &no_3); // get number 3 from the user
	
	printf("Enter number 4: ");
	scanf("%d", &no_4); // get number 4 from the user
	
	printf("Enter number 5: ");
	scanf("%d", &no_5); // get number 5 from the user
	
	printf("Enter number 6: ");
	scanf("%d", &no_6); // get number 6 from the user
	
	printf("Enter number 7: ");
	scanf("%d", &no_7); // get number 7 from the user
	
	printf("Enter number 8: ");
	scanf("%d", &no_8); // get number 8 from the user
	
	printf("Enter number 9: ");
	scanf("%d", &no_9); // get number 9 from the user
	
	printf("Enter number 10: ");
	scanf("%d", &no_10); // get number 10 from the user
	
	
	printf("Enter the value to search: ");
	scanf("%d", &no_se);
		

	// Compare using if condition
	if (no_1 == no_se)
	{
		printf("Value exists at element number: 1 ");
	}
	
	else if (no_2 == no_se)
	{
		printf("Value exists at element number: 2 ");
	}
	
	else if (no_3 == no_se)
	{
		printf("Value exists at element number: 3 ");
	}
	
	else if (no_4 == no_se)
	{
		printf("Value exists at element number: 4 ");
	}
	
	else if (no_5 == no_se)
	{
	printf("Value exists at element number: 5 ");
	}
	
	else if (no_6 == no_se)
	{
		printf("Value exists at element number: 6 ");
	}
	
	else if (no_7 == no_se)
	{
	printf("Value exists at element number: 7 ");
	}
	
	else if (no_8 == no_se)
	{
		printf("Value exists at element number: 8 ");
	}
	
	else if (no_9 == no_se)
	{
		printf("Value exists at element number: 9 ");
	}
	
	else if (no_10 == no_se)
	{
		printf("Value exists at element number: 10 ");
	}
	
	else
	{
		printf("The value you entered in not listed");
	}
	// Output
	
}