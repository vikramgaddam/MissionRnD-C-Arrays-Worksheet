/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int K) {
	if (students == NULL)return NULL;
	if (len <= 0)return NULL;
	if (K <= 0)return NULL;

	int i, j,position;

	for (i = 0; i < len; i++)
	{
		position = i;

		for (j = i + 1; j < len; j++)
		{
			if (students[j].score > students[position].score)
			{
				position = j;
			}
		}
		if (position != i)
		{

			struct student temp;

			temp = students[i];


			students[i] = students[position];

			students[position] = temp;


		}
	}

	struct student **new_list= (struct student **)malloc(sizeof(struct student)*K);

	for (i = 0; i < K; i++)
	{
		new_list[i] = &students[i];
	}
	return new_list;

}