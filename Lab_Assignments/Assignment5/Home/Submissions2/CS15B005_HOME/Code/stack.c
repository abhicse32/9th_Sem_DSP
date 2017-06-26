#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
stack* stack_new()
{
	stack* S = (stack*)malloc(sizeof(stack));
	S->top = llist_new();
	return S;
}

// push an element on the stack
void stack_push(stack* S, int data)
{
	llist_prepend( S->top, data);
	return;
}

// pop the top element from the stack
int stack_pop(stack* S)
{
	int pop = S->top->head->data;
	llist_remove_first( S->top );
	return pop;
}

// Check if stack is empty
bool stack_is_empty(stack* S)
{
	if ( stack_size(S) == 0)	return 1;
	return 0;
}

// find the size of the stack
int stack_size(stack* S)
{
	int size;
	size = llist_size( S->top );
	return size;
}

// print stack element
void stack_print(stack* S)
{
	llist_print( S->top );
	return;
}

