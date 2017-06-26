#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()
{
	stack *stk = malloc(sizeof(stack));
	stk->top = llist_new();
	return stk;
}

// push an element on the stack
void stack_push(stack* stk, int elm)
	{llist_prepend( stk->top, elm);}

// pop the top element from the stack
int stack_pop(stack* stk)
	{llist_remove_first( stk->top);}

// Check if stack is empty
bool stack_is_empty(stack* stk)
{
	if( llist_size( stk->top) == 0)
		return true;
	return false;
}

// find the size of the stack
int stack_size(stack* stk)
	{
		int l = llist_size( stk->top);
		return l;
	}

// print stack element
void stack_print(stack* stk)
	{llist_print( stk->top);}