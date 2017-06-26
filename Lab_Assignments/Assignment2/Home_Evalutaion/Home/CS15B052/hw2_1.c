// Home Assignment 1 Question 1
// Finding determinant of a n*n matrix
// Author : Milind Srivastava
// Date : 16 Aug 2016

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int det (int**, int); // recursive function to compute determinant

int main()
{
	int n;
	scanf("%d",&n);

	int** arr = (int**)malloc(n*sizeof(int*)); // allocation space for n rows

	int i;
	for(i = 0; i < n; i++)
	{
		arr[i] = (int*)malloc(n*sizeof(int)); // allocating space for n integers in each row
	}

	int j,k;

	for(j = 0; j < n; j++)
	{
		for (k = 0; k < n; k++)
		{
			scanf("%d",&arr[j][k]); // inputting elements of matrix
		}
	}

	printf("%ld",det(arr,n));

	// freeing dynamically allocated memory

	for(i = 0; i < n; i++)
	{
		free(arr[i]);
	}

	free (arr);

	return 0;
}

long int det (int** arr, int n)
{
	if (n==1) // base case of recursive implementation
	{
		return arr[0][0];
	}

	long int sum = 0; // final determinant value

	int i;
	for (i = 0; i < n; i++)
	{
		// dynamic allocation of memory for (n-1) order square matrix 

		int ** temp = (int**)malloc((n-1)*sizeof(int*));

		int j,k;

		for(j = 0; j < n-1; j++)
		{
			temp[j] = (int*)malloc((n-1)*sizeof(int));
		}

		// allocating elements of co-factor matrix

		for (j = 0;j < n-1; j++)
		{
			for (k = 0; k < n-1; k++)
			{
				if (k < i)
				{
					temp[j][k] = arr[j+1][k];
				}
				else
				{
					temp[j][k] = arr[j+1][k+1];
				}
			}
		}

		sum += (arr[0][i] * det(temp, n-1) * pow(-1.0f,(float)i)); //calculating determinant element by element

		// freeing dynamically allocated memory

		for(j = 0; j < n-1; j++)
		{
			free(temp[j]);
		}

		free (temp);
	}

	return sum;
}