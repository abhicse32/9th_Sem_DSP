/*To find the next maximum of each element in the array
  Author: CS15B046 Jahnvi Patel
  September 16th, 2016*/
#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>



void findNextMax(int arr[],int n)
{
	int i;
	stack* s=stack_new();
	/*stack s stores the indices of array elements that have not been assigned next_max yet*/
	stack_push(s,0);
	for(i=1;i<n;i++)
	{
		/*If current element<arr[top] then push it's index*/
		/*Else pop till current element<arr[top]
		 then push index of current element
		 For all the popped entries, the current element will be next_max*/

		if(arr[i]>arr[s->top->head->data])
		{
		while(arr[i]>arr[s->top->head->data] && !stack_is_empty(s))
		{
			int ind=stack_pop(s); //popping the indices for which value<current element
			arr[ind]=arr[i];
			if (stack_is_empty(s))
				break;
			

		}
		stack_push(s,i); //push current element

		}
		else stack_push(s,i);
		

	}
	/*Assign -1 to all the elements who do not have next_max*/
	while(!stack_is_empty(s))
	{
		int ind=stack_pop(s);
			arr[ind]=-1;
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int i=0;
	//Runs for t testcases
	for(i=0;i<t;i++)
	{
		int n;
		scanf("%d",&n);
		int arr[n];
		int j;
		for(j=0;j<n;j++)
			scanf("%d",&arr[j]);
		findNextMax(arr,n);
		for(j=0;j<n;j++)
			printf("%d ",arr[j]);
		printf("\n");
	}
	return 0;
}