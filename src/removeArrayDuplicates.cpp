/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

int removeArrayDuplicates(int *Arr, int len)
{
	if (len <= 0)return -1;

	if (Arr == NULL)return -1;

	
	int i, j, size=1,key,bol=0;

	for (i = 1; i < len; i++)
	{
		key = Arr[i];
		for (j = 0; j < size; j++)
		{
			if (Arr[j] == key)
			{
				bol = 1;
				break;
			}
		}
		if (bol == 0)
		{
			Arr[size++] = key;
		}
		bol = 0;
	}
	return size;


}