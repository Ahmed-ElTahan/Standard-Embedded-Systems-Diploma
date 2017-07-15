// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	It is required to use recursive function in order to calculate the factorial of a number to be entered by the user 
	v2 : no global variable, but with dummy input variable
*/


#include<stdio.h> // Library to include c functions for the compiler.

int Rec_Fact(int no, int dum)
{
	dum *= no; // as dum is an input, no declaration of it at the beginning, it saves its value
	no -= 1;

	if (no != 1) // as the number multiplied with dum, it decreases then till we reach 1 we recursive the function
	{
		dum = Rec_Fact(no, dum);
	}
	
	else
	{
		return dum;
	}

}

main()
{	
	// Declaration and Inintialization
	int input;
	int fact; // Rec_Fact function factorial output
	int dum = 1; // dummy variavble used in order to not to use declaration of the factorial storage at the beginning
	
	// Write your instructions here.
	
	
	printf("Please enter the number to get its factorial: ");
	scanf("%d", &input); // get the number
	
	fact = Rec_Fact(input, dum); // function call and get factorial
	
	// Output
	
	printf("Factorial of %d is %d", input, fact);
}