#include<stdio.h>

main()
{

	// declaration
		float no_1;
		float no_2; 
		float sum, sub, multp, div, rem;
		
	// General Message
	printf("This is a Simplified Calculator \n \n");

		
	// get the values from the user
		printf("Please enter no.1:");
		scanf("%f", &no_1);
		printf("Please enter no.2:");
		scanf("%f", &no_2);

	// Summation operation
		sum = no_1 + no_2;
		printf("Summation equal to %f \n \n", sum);

	// Subtraction operation
		sub = no_1 - no_2;
		printf("Subtraction equal to %f \n \n", sub);

	// Multiplication operation
		multp = no_1 * no_2;
		printf("Multiplication equal to %f \n \n", multp);

	// Division operation
		div = no_1 / no_2;
		printf("Division 1/2 equal to %f \n \n", div);
		
	// Modulus (Remainder) operation (only for integar)
		rem = (int)no_1 % (int)no_2;
		printf("Remainder equal to %f", rem);
			
}