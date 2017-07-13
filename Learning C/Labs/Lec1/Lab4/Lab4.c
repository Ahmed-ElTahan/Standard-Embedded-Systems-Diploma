// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------

*/


#include<stdio.h> // Library to include c functions for the compiler.


main()
{	
	// Declaration and Inintialization
	char x = 7; // 0xb 000000111
	char y = 4; // 0xb 000000100
	
	char z, k, m, L, N; 
	unsigned char l;
	// Write your instructions here.
	// Bitwise Operators And, OR, XOR, Not
		printf("Bitwise Operators (& | ^ ~ << >>) \n");
		
		// And (&)
		z = x & y; // 0xb 0000000100 = 4
		printf("And result is %d \n", z);
		
		// OR (|)
		k = x | y; // 0xb 00000111 = 7
		printf("OR result is %d \n", k);
		
		// XOR (^)
		m = x ^ y; // 0xb 00000011 = 3
		printf("XOR result is %d \n", m);
		
		// Not (~)
		l = ~x; // 0xb 11111000 = 248
		printf("Not result is %d \n", l);
		
		printf("shift left & right\n");		
		// shift left
		L = x<<2; // 0xb 00011100 = 28
		printf("shift left by 2 to x = 7 is %d \n", L);
		
		// shift right
		x = 7;
		N = x>>2; // 0xb 00000001 = 1
		printf("shift right by 2 to x = 7 is %d \n \n", N);
		
		
	// Output
	
}