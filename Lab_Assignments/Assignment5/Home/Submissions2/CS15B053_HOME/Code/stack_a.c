#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000


stack* stack_new()
{
	stack *newstack;
	newstack = (stack *)malloc(sizeof(stack));
	newstack->arr = (int *)malloc(size * sizeof(int));
	newstack->top = -1;
	return newstack;
}


void stack_push(stack *s, int ele)
{
	if(!stack_is_full(s))
		s->arr[++(s->top)] = ele;
}


int stack_pop(stack *s)
{
	int x = -1;
	if(!stack_is_empty(s))
		x = s->arr[(s->top)--];
	return x;
}


bool stack_is_empty(stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}


bool stack_is_full(stack *s)
{
	if(s->top==size)
		return 1;
	else
		return 0;
}


int stack_size(stack *s)
{
	return s->top+1;
}


void stack_print(stack *s)
{
	int i;
	for(i=s->top; i>=0; i--)
		printf("%d ", s->arr[i]);
}