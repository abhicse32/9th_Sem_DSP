#include<stdio.h>
#include"stack.h"

int main()
{
	int t;
	int i;
	//Take no. of testcases
	scanf("%d",&t);
	//Initialize stack
	//Stack stores indices of elements who havent found next larger till now
	stack *S = stack_new() ;
	//Iterate through all testcases
	for(i=0;i<t;i++)
	{
		//Take size of array
		int n;
		scanf("%d",&n);
		
		int num[n] ;
		int count[n] ;
		int j;		
		//Take array
		for(j=0;j<n;j++)
			scanf("%d",&num[j]);
		//Push index of 1st element on stack
		stack_push(S,0);
		count[0] = -1 ;
		
		/*
		Compare num[stack_top] with current element:
		If num[stack_top] >= num[j]
		-->  push current element while initializing count to -1
		Else
		--> Pop elements off the stack & assign count[stack_top(index)] to current element 
		*/		
		for(j=1;j<n;j++)
		{
			while(stack_is_empty(S) == false)
			{
				if(num[S->top->head->data] < num[j])
					count[stack_pop(S)] = num[j] ;
				else
					break ;
			}
			stack_push(S,j) ;
			count[j] = -1 ;
		}
		//Print Answer
		for(j=0;j<n;j++)
			printf("%d ",count[j]);
		printf("\n");
		//Empty Stack
		while(stack_is_empty(S) == false)
			stack_pop(S) ;
	}
}
