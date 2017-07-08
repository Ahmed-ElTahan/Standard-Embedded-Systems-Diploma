// This code is created by Ahmed A. Eltahan
#include<stdio.h> // Library to include c functions for the compiler.


/* 
	----------------------------- Program Description -----------------------------------------
   Write a C code to ask the user to enter his grade and the program will print his rating based on the following table
   
   00<= grade < 50     -------> Failed
   50<= grade < 65     -------> Normal
   65<= grade < 75     -------> Good
   75<= grade < 85     -------> Very good
   85 <= grade         -------> Excellent
   
*/

main()
{	
	// Declaration
	int grade; 
	
	// write your instructions here.
	printf("This program is intended to give student rating based on his grade \n \n");
	printf("Please enter your grade: ");
	scanf("%d", &grade);
	
	if (grade >=0 && grade <50)
	{
		printf("Your rating is Failed");
	}
	
	else if (grade >=50 && grade <65)
	{
		printf("Your rating is Normal");
	}

	else if (grade >=65 && grade <75)
	{
		printf("Your rating is Good");
	}
	
	else if (grade >=75 && grade <85)
	{
		printf("Your rating is Very good");
	}
		
	else if (grade >=85 && grade <=100)
	{
		printf("Your rating is Excellent");
	}
	
	else
	{
		printf("Please enter a value between 0 and 100");
	}
		
	
}