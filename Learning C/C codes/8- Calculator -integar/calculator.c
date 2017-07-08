#include<stdio.h>

main()
{

	// declaration
		int no_1;
		int no_2; 
		int sum, sub, multp, div, rem;
		
	// General Message
	printf("This is a Simplified Calculator \n \n");

		
	// get the values from the user
		printf("Please enter no.1:");
		scanf("%d", &no_1);
		printf("Please enter no.2:");
		scanf("%d", &no_2);

	// Summation operation
		sum = no_1 + no_2;
		printf("Summation equal to %d \n \n", sum);

	// Subtraction operation
		sub = no_1 - no_2;
		printf("Subtraction equal to %d \n \n", sub);

	// Multiplication operation
		multp = no_1 * no_2;
		printf("Multiplication equal to %d \n \n", multp);

	// Division operation
		div = no_1 / no_2;
		printf("Division 1/2 equal to %d \n \n", div);
		
	// Modulus (Remainder) operation
		rem = no_1 % no_2;
		printf("Remainder equal to %d", rem);
			
}