#include<stdio.h>

main()
{
	// declaration
	int x;
	float y;
	double z;
	
// integar	
	// message
	printf("Please input an integar number: ");
	// receiving value function
	scanf("%d", &x);
	
// float	
	// message
	printf("Please input a float number: ");
	// receiving value function
	scanf("%f", &y);

// double	
	// message
	printf("Please input a double number: ");
	// receiving value function
	scanf("%lf", &z);	
	
	
	// Output
	printf("Integar number is: %d \n", x);
	printf("Float number is: %f \n", y);
	printf("Double number is: %lf \n", z);


}