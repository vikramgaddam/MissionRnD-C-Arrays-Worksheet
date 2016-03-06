/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr == NULL)return NULL;
	if (len <= 0)return NULL;

	int i, index1=-1, index2;

	for (i = 0; i < len-1; i++)
	{
		if (Arr[i]>Arr[i + 1])
		{
			if (index1 == -1)
			{
				index1 = i;
			}
			else
			{
				index2 = i+1;

				int temp = Arr[index1];
				Arr[index1] = Arr[index2];
				Arr[index2] = temp;

				return Arr;
			}
			

		}
	}
}