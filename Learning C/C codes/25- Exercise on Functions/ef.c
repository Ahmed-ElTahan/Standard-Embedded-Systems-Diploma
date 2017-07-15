// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	Write a C function check(x, y, n) that returns 1 if x & y are lying between 0 and n-1, inclusive
	and return 0 otherwise.
*/


#include<stdio.h> // Library to include c functions for the compiler.

int check(int x, int y, int n); // function prototype

main()
{	
	// Declaration and Inintialization
	int a, b, c;
	int func_output;
		
	// Write your instructions here.
	// no_1
	printf("Please enter no_1: ");
	scanf("%d", &a);

	// no_2
	printf("Please enter no_2: ");
	scanf("%d", &b);
	
	// no_3
	printf("Please enter no_3: ");
	scanf("%d", &c);

	func_output = check(a, b, c);
	
	
	// Output
	printf("result is %d", func_output);
}


// function check declaration and body
int check(int x, int y, int n)
{
	
	if((x >= 0) && (x <= (n - 1)) && (y >= 0) && ( y <=(n - 1))) // check condition
	{
		return 1;
	}
	
	else
	{
		return 0;
	}
}