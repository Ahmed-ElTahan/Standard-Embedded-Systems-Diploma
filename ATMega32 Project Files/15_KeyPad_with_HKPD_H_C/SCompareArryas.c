/*
 * compareArryas.c
 *
 *  Created on: Aug 27, 2017
 *      Author: Ahmed A. Eltahan
 */

/*
 */
/*This c file includes SCompareArrays(int Arr1[ ], int Arr2[ ], int Arr_Size) which compares the
 elements of 2 input arrays (element by element) and returns 1 if they are equal. The 2 matrices must be
 the same size and that size is an input to the function.
 */
#include"SCompareArrays.h"// This header file contains the function prototype of SCompareArrays(int Arr1[ ], int Arr2[ ], int Arr_Size) function

int SCompareArrays(int Arr1[ ], int Arr2[ ], int Arr_Size)
{
	int j;
	for (j = 0; j<Arr_Size; j++)
	{
		if (Arr1[j] != Arr2[j])
		{
			return 0;
			break;
		}


	}
	return 1;
}

