// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
				Write a C code that ask the user to enter his ID and then the program will print his name. 
				Available IDs are:
				
					1234-> Ahmed 
					5678 -> Youssef 
					1145 -> Mina 
				
				Any other number, the program will print Wrong ID
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int ID;
	
	// Write your instructions here.
	printf("Please Enter Your ID: ");
	scanf("%d", &ID); // get the ID from the user
	
	switch (ID)
	{
		
		case 1234:
		printf("Welcome Ahmed \n");
		break;
		
		case 5678:
		printf("Weclome Youssef \n");
		break;
		
		case 1145:
		printf("Weclome Mina \n");
		break;
		
		default:
		printf("Wrong ID");
		break;
		
	}
	// Output
	
}