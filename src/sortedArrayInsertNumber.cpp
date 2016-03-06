/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr == NULL)return NULL;
	if (len <= 0) return NULL;

	int start = 0, end = len - 1, mid;
	mid = start + (end - start) / 2;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (mid == len - 1)
		{
			if (Arr[mid] <= num)
			{
				Arr = (int *)realloc(Arr, (len)*sizeof(int));
				Arr[mid + 1] = num;
				return Arr;
			}

		}
		if (mid == 0)
		{
			if (Arr[0] >= num)
			{
				Arr = (int *)realloc(Arr, (len)*sizeof(int));
				int i,temp1,temp2;
				temp1 = Arr[0];
				for (i = 0; i < len; i++)
				{
					temp2 = Arr[i + 1];
					Arr[i + 1] = temp1;
					temp1 = temp2;
				}
				Arr[0] = num;
				return Arr;
			}
		}
		if ((Arr[mid - 1] <= num) && (Arr[mid] >= num))
		{
			Arr = (int *)realloc(Arr, (len)*sizeof(int));
			int i, temp, temp2;
			temp = num;
			for (i = mid; i <= len; i++)
			{
				temp2 = Arr[i];
				Arr[i] = temp;
				temp = temp2;
			}
			return Arr;
		}
		else
		{
			if (Arr[mid] > num)
			{
				end = mid - 1;
			}
			else
			{
				start = mid + 1;
				
			}


		}
	}
	return Arr;

}