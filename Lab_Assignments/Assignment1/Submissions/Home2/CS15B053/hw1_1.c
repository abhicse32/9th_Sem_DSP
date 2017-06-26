#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void findtopmax(int n, int *numbers, int *topmax)
{
	if(numbers[0]>numbers[1])
	{
		topmax[0] = numbers[0];
		topmax[1] = numbers[1];
	}
	else
	{
		topmax[0] = numbers[1];
		topmax[1] = numbers[0];
	}
	
	int i;	
	for(i=2; i<n; i++)
	{
		if(numbers[i]>topmax[0])
		{
			topmax[1] = topmax[0];
			topmax[0] = numbers[i];
		}
		else if(numbers[i]>topmax[1])
		{
			topmax[1] = numbers[i];
		}
	}		
}
		
void main()
{
	int n;
	scanf("%d", &n);
	
	int *numbers;
	numbers = (int*)malloc(n * sizeof(int));
	
	int topmax[2];
	
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &numbers[i]);
	}
	
	findtopmax(n, numbers, topmax);
	
	printf("%d %d", topmax[0], topmax[1]);	
}
