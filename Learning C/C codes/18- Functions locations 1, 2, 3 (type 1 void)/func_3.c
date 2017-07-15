// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program is used to show how to use functions by method 3 (define function and body after main() and use function prototype for the compiler)
*/


#include<stdio.h> // Library to include c functions for the compiler.	

void hash_star(); // function prototype in order to attent the compiler when it sees the function call and it did not see its declaration and body (C sequential)

main()
{	

	// Declaration and Inintialization

	// Write your instructions here.
	
	// Message 1
	hash_star(); // function call
	printf("\n \n ");
	printf("\t Welcome to our program \n \n");

	// Message 2
	hash_star(); // function call
	printf("\n \n ");
	printf("\t Programing course is so boring! \n \n");

	// Message 3
	hash_star(); // function call
	printf("\n \n ");
	printf("\t I will go to sleep now, Goodbye! \n \n");

	hash_star(); // function call

	// Output
	
}


// function definintion and body
	void hash_star()
	{
			int i; // counter
			for (i = 1; i<=50; i++)
			{
				printf("#");
			}
			
			printf("\n");
			
			for (i = 1; i<=50; i++)
			{
				printf("*");
			}
	}