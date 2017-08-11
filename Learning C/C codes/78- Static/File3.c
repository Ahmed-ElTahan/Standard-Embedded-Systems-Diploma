void print3()
{
	extern int x; // extern global var from File2.c
	x = 3;
	printf("x from File3.c, extern from File2.c, other than static x in File1.c, is %d \n", x);
}