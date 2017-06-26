#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
stack* stack_new()
{
	stack* st = (stack*) malloc(sizeof(stack));
	st -> top = llist_new();
	return st;
}

// push an element on the stack
void stack_push(stack* st, int num)
{
	llist_prepend(st -> top, num);
}

// pop the top element from the stack
int stack_pop(stack* st)
{
	int pop = llist_get(st -> top, 0);
	llist_remove_first(st -> top);
	return pop;
}

// Check if stack is empty
bool stack_is_empty(stack* st)
{
	if(st -> top -> head)	return 0;
	else			return 1;
}

// find the size of the stack
int stack_size(stack* st)
{
	return llist_size(st -> top);
}

// print stack element
void stack_print(stack* st)
{
	llist_print(st -> top);
}

