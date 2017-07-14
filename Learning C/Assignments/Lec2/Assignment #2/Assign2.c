// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C code that ask the user to enter his ID, if the ID is valid it will ask the user to enter his password, if the password is correct the 
	program will print the user name, if the password is incorrect the program will print Incorrect Password. 
	In case of not existing ID, the program will print Incorrect ID

	my ID = 1234
	my password = 5678
	my username = Ahmed A. Eltahan
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	int ID;
	int pass; // password
	
	// Write your instructions here.
	printf("Please entere your ID: ");
	scanf("%d", &ID);
	
	if(ID == 1234) // check ID
	{
		printf("Please enter your password: ");
		scanf("%d", &pass);
		
		if (pass == 5678) // check password
		{
			printf("Your username is : Ahmed A. Eltahan"); // print username after correct ID and password
		}
		
		else
		{
			printf("Incorrect Pasword"); // correct id but incorrect password
		}
	}
	
	else
	{
		printf("Incorrect ID"); // incorrect ID
	}
	
	// Output
	
}