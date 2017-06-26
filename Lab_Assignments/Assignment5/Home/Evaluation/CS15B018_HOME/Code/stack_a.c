#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()
{
	stack* st = (stack*) malloc(sizeof(stack));
	st -> arr = (int *) malloc(size * sizeof(int));
	st -> top = -1;
	return st;
}

bool stack_is_empty(stack* st)
{
	if(st -> top == -1)	return 1;
	else			return 0;
}

bool stack_is_full(stack* st)
{
	if(st -> top == size - 1)	return 1;
	else				return 0;
}

void stack_push(stack* st, int num)
{
	if(!stack_is_full(st))
	{
		st -> top = st -> top + 1;
		st -> arr[st -> top] = num;
	}	
}

int stack_pop(stack* st)
{
	while(!stack_is_empty(st))
	{
		int pop = st -> arr[st -> top];
		st -> top = (st -> top) - 1;
		return pop;
	}
}

int stack_size(stack* st)
{
	return ((st -> top) + 1);
}

void stack_print(stack* st)
{
	int i = 0;
	for(i = st -> top; i >= 0; i--)	
	printf("%d ",st -> arr[i]);
}

