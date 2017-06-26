#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
stack* stack_new()
{
	stack *stack_new = (stack*)malloc(sizeof(stack));
	stack_new->top = llist_new();
	(stack_new->top)->head = NULL;
	return stack_new;
}


void stack_push(stack* stack, int a)
{
	llist_prepend(stack->top,a);
}


int stack_pop(stack *stack)
{
	int i = ((stack->top)->head)->data;
	llist_remove_first(stack->top);
	return i;
}


bool stack_is_empty(stack *stack)
{
	bool i;
	if(((stack->top)->head) == NULL)
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
	return llist_size(stack->top);
}


void stack_print(stack *stack)
{
	llist_print(stack->top);
}
