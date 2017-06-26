// Home Assignement 1 Question 1
// Finding max and next max integers from an array of n integers
// Author : Milind Srivastava
// Date : 9 Aug 2016

#include <stdio.h>
#include <limits.h> // For INT_MIN
#include <stdlib.h>

int main()
{
	int n;

	scanf("%d",&n);

	int* arr = (int*)malloc(n*sizeof(int)); // Dynamic memory allocation

	int i;

	int max,nmax;
	max = nmax = INT_MIN;

	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);

		if(arr[i] > max) // If element scanned is greater than current max
		{
			nmax = max;
			max = arr[i];
		}
		else if(arr[i] > nmax) // If element scanned is lesser than current max but greater than current nextMax
		{
			nmax = arr[i];
		}
	}

	printf("%d %d\n", max, nmax);

	free(arr); // Freeing dynamically allocated memory

	return 0;
}
