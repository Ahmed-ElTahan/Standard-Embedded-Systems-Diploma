// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
   Write a C code to calculate employee salary in a week based on his working hours, hour rate is 50.
   The program will ask the user to enter the working hoursm then it will print his salary.
   But if the working hours are less than 40 hours, a 10% deduction will be applied.
*/


#include<stdio.h> // Library to include c functions for the compiler.

main()
{	
	// Declaration
	int WH; // working hours
	int salary;
	int HR = 50; // hour rate
	float DP = 10; // deduction percent
	
	// write your instructions here.
	printf("This program is designed to calculate the salary of an employee based on working hours \n \n");
	printf("Please Enter Your Working Hours: ");
	scanf("%d", &WH);
	if(WH >=40)
	{
		salary = HR*WH;
	}

	else
	{
		salary = HR*WH*(1-DP/100);
	}
	
	printf("Your Salary is %d", salary);
	
}