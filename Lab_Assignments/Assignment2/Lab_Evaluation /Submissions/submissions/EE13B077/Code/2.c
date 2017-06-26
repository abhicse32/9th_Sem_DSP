/*

Author Name: Gudur Phani Karan Reddy (EE13B077)
Time: Thu Aug  18 2:55:38 IST 2016

Description:
This program takes a list of integers as an input and outputs the permutations of the list using recursion, 
treating each integer(>1 digits) as a single entity.

*/

#include <stdio.h>
#include <malloc.h>




void swap(int* a, int* b)
{
/*
	Swaps integers, passed by reference.
*/

	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}


void permute(int* well, int p, int n)
{
/*
	Input - base address of an integer array, start point, length
	Output - prints the permutations of all the elements in the array
*/
	int i, j, k;
	
	for(i=p; i<n-1; i++)
		for(j=i+1; j<n; j++)
	{
		swap(well+i, well+j);
		permute(well, i+1, n);
		swap(well+i, well+j);
	}

	for(k=0; k<n; k++)
		printf("%d", *(well+k));
		printf(" ");
	
}



int main()
{
	int n, i;
	scanf("%d", &n);

	int nums[n];
	for(i=0; i<n; i++)
		scanf("%d", &nums[i]);
		
	permute(nums, 0, n);

	printf("\n");

	return 0;

}
