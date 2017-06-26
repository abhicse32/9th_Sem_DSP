#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()
{
	stack* s = (stack*) malloc(sizeof(stack));
	s->arr = (int*) malloc(sizeof(int)*size);
	s->top = -1;
	return s;
}

void stack_push(stack* s, int data)
{
	s->top ++;
	(s->arr)[s->top] = data;
}

int stack_pop(stack* s)
{
	int a = (s->arr)[s->top];
	s->top --;
	return a;
}

bool stack_is_empty(stack* s)
{
	if(s->top == -1)
		return true;
	else 
		return false;
}

bool stack_is_full(stack* s)
{
	if(s->top == size-1)
		return true;
	else
		return false;
}

int stack_size(stack* s)
{
	return s->top + 1;
}

void stack_print(stack* s)
{
	int i;
	for(i = s->top; i >= 0; i--)
		printf("%d ",(s->arr)[i] );
}