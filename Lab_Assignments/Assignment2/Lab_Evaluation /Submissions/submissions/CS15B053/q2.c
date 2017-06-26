#include<stdio.h>
#include<stdlib.h>


void swap(int numbers[], int i, int j) 
{
	int temp;
	temp = numbers[i];
	numbers[i] = numbers[j];
	numbers[j] = temp;
}

void print_permutations(int numbers[], int n, int i)
{

	int j;

	if (i == n) 
	{
		for (j=0; j<n; j++) 
			printf ("%d ", numbers[j]);
		printf ("\n");
	}
	else
	{
		for (j=i; j<n; j++)
		{

			swap (numbers, i, j);
			print_permutations(numbers, n, i+1);
			swap (numbers, i, j);
		}
	}
}

void main()
{
	int n;
	scanf("%d", &n);
	int *numbers;
	numbers = (int*)malloc(n * sizeof(int));
	
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &numbers[i]);
	}
	print_permutations(numbers, n, 0);
}
		
	
