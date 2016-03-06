
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void  *studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) {

	if (Arr == NULL)return NULL;
	if (len <= 0) return NULL;
	int i = 0;

	if (len == 1)
	{
		if (Arr[i] < score)
		{
			*lessCount = 1;
			*moreCount = 0;
			return Arr;
		}

		if (Arr[i] > score)
		{
			*lessCount = 0;
			*moreCount = 1;
			return Arr;
		}
		if (Arr[i] == score)
		{
			*lessCount = 0;
			*moreCount = 0;
			return Arr;
		}
	}

	for (i = 0; i < len-1; i++)
	{
	
		if (Arr[i] == score)
		{
			int start_index = i;
			int end_index = i;

			while ((Arr[start_index] == score) && (start_index>0))
			{
				start_index--;
			}
			while ((Arr[end_index] == score) && (end_index<len))
			{
				end_index++;
			}

			if (start_index == 0)
				*lessCount = start_index;
			else
				*lessCount = start_index + 1;

			*moreCount = len - end_index;
			return Arr;
		}

		if ((Arr[i]<score) && (Arr[i + 1]>score))
		{
			
			*lessCount = i+1;
			*moreCount = len-i-1;
			return Arr;
		}

	}
	*lessCount = 0;
	*moreCount = 0;
	return Arr;

	
}
