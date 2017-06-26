#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
#include<stdbool.h>
stack* stack_new()

{
	stack *stack_new = (stack*)malloc(sizeof(stack));
	stack_new->arr = (int *)malloc(size*(sizeof(int)));
	stack_new->top = -1;
	return stack_new;
}
void stack_push(stack *stack, int a)
{
	stack->top = stack->top + 1;
	(stack->arr)[stack->top] = a;
}
int stack_pop(stack *stack)
{	if(stack->top > -1)
	{
		int i = (stack->arr)[stack->top];
		stack->top = stack->top - 1;
		return i;
	}
	else 
	return -1;
}
bool stack_is_empty(stack *stack)
{
	bool i;
	if(stack->top == -1)
	{
		i = true;
	}
	else
	{
		i = false;
	}
	return i;
}
bool stack_is_full(stack *stack)
{
	bool i;
	if(stack->top == size - 1)
	{
		i = true;
	}
	else
	{
		i = false;
	}
	return i;
}
int stack_size(stack *stack)
{
	return (stack->top+1);
}
void stack_print(stack *stack)
{
	int i = stack->top;
	for(i = stack->top;i>=0;i--)
	{
		printf("%d ",(stack->arr)[i]);
	}
}

	
