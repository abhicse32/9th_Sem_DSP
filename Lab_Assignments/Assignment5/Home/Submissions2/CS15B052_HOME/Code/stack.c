// Defines functions defined in stack.h
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
stack* stack_new()
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp->top = llist_new();
	return temp;
}

// push an element on the stack
void stack_push(stack* st, int x)
{
	llist_prepend(st->top, x);
}

// pop the top element from the stack
int stack_pop(stack* st)
{
	int temp = llist_get(st->top, 0);
	llist_remove_first(st->top);
	return temp;
}

// Check if stack is empty
bool stack_is_empty(stack* st)
{
	return (llist_size(st->top) == 0);
}

// find the size of the stack
int stack_size(stack* st)
{
	return llist_size(st->top);
}

// print stack element
void stack_print(stack* st)
{
	llist_print(st->top);
}