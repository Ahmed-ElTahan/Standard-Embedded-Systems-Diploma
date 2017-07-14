// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
			Write a login program in C that ask the user to enter his ID and his password, if
			the ID is correct the system will ask the user to enter his password up to 3 times,
			if he enters the password right the systems welcomes him, if the three times
			are incorrect, the system print No more tries. If the user ID is incorrect the
			system print You are not registered 

			User 		ID 			Password 
			Ahmed 		1234 		7788 
			Amr 		5678 		5566 
			Wael 		9870 		1122 
*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
// Declaration and Inintialization
	int ID;
	int pass; // password
	int i; // counter
	
	// Write your instructions here.
	printf("Please entere your ID: ");
	scanf("%d", &ID);
	

		
		switch (ID) // check password
		{
			// user 1
			case 1234:
			printf("Please enter your password: ");
			scanf("%d", &pass); // get pass for the first time
			
				for (i = 0; i<=1; i++)
				{
					if (pass == 7788)
					{
						break; // if pass typed --> exit from the loop of 2 times, no need to type it any more
					}
					printf("Try again: ");
					scanf("%d", &pass);

				}
				
				if (pass != 7788) // after getting out form the for loop, check on last trial. check if you typed correct or incorrect pass and hence print message depending on state
				{
					printf("Incorrect Password for 3 times. No more tries. ");
				}
				
				else
				{
					printf("Welcome Ahmed");
				}
			break;

			// user 2
			case 5678:
			printf("Please enter your password: ");
			scanf("%d", &pass);
			
				for (i = 0; i<=1; i++)
				{
					if (pass == 5566)
					{
						break;
					}
					printf("Try again: ");
					scanf("%d", &pass);

				}
				
				if (pass != 5566)
				{
					printf("Incorrect Password for 3 times. No more tries. ");
				}
				
				else
				{
					printf("Welcome Amr");
				}
			break;
			
			// user 3
			case 9870:
			printf("Please enter your password: ");
			scanf("%d", &pass);
			
				for (i = 0; i<=1; i++)
				{
					if (pass == 1122)
					{
						break;
					}
					printf("Try again: ");
					scanf("%d", &pass);

				}
				
				if (pass != 1122)
				{
					printf("Incorrect Password for 3 times. No more tries. ");
				}
				
				else
				{
					printf("Welcome Wael");
				}
			break;
			
			// id not listed
			default:
			printf("Incorrect ID"); // incorrect ID
			break;
			
		}	



	
	// Output
	
}