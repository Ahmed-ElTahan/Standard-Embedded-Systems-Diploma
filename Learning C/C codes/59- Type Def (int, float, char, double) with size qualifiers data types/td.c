// This code is created by Ahmed A. Eltahan

/* 
	----------------------------- Program Description -----------------------------------------
	This program shows how to use type def to define new name for data types (int, float, char, double)
	with size qualifiers in order to ease change the data type in sake of stick with designed (chose) data
	type sizes
*/

// Libraries
#include<stdio.h> // Library to include c functions for the compiler.


// Type definition
typedef unsigned char 			u8; 
typedef unsigned short int 		u16;
typedef unsigned int 			u32;
typedef signed char 			s8;
typedef signed short int 		s16;
typedef signed int 				s32;
typedef signed long int 		s64;
typedef signed long long int 	s128;
typedef float 					f32;
typedef double 					f64;
typedef long double				f96;

// Function prototype
// Declared Structures
// Declared Functions
// Global variables (Declaration and Inintialization)
// Enum

void main(void)
{	
	// Declaration and Inintialization
	// Write your instructions here.
	// infinite loop  while(1){}
	// Output
	printf("The size of u8  is %d bytes \n", sizeof(u8));
	printf("The size of u16 is %d bytes \n", sizeof(u16));
	printf("The size of u32 is %d bytes \n", sizeof(u32));
	printf("The size of s8  is %d bytes \n", sizeof(s8));
	printf("The size of s16 is %d bytes \n", sizeof(s16));
	printf("The size of s32 is %d bytes \n", sizeof(s32));
	printf("The size of s64 is %d bytes \n", sizeof(s64));
	printf("The size of s128 is %d bytes \n", sizeof(s128));
	printf("The size of f32 is %d bytes \n", sizeof(f32));
	printf("The size of f64 is %d bytes \n", sizeof(f64));
	printf("The size of f96 is %d bytes \n", sizeof(f96));
	
}