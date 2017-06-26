//program to find number of reversals required to balance by Akshay Kumar


#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void main()
{
	int t,i,j,flip=0,z;																//declaration of variables
	scanf("%d",&t);																	//number of test cases
	for(i = 0; i < t; i ++)
	{
		flip = 0;
		char a[1000];
		scanf("%s",a);																//input of string
		stack* st = stack_new();													//creating new stack
		
		for(j = 0; a[j] != '\0'; j ++)
		{
			if(a[j] == '{') stack_push(st,1);										//if open bracket pushes
			
			if(a[j] == '}')															//if empty stack increments flip and pushes
			{
				if(stack_is_empty(st))
				{
					stack_push(st,1);
					flip++;
					continue;
				}
				if(st->top->head->data == 1) stack_pop(st);							//open and closed matches pops
				
			}
			
		}
		z=stack_size(st);
		if((z%2) == 1) printf("-1\n");												//if z is odd it can't be balanced
		else printf("%d\n",flip+(z/2));
		
	}
}