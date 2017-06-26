#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
stack* stack_new()
{
	stack* stk = (stack*) malloc (sizeof(stack));
	stk -> top = llist_new();
	return stk;
}

// push an element on the stack
void stack_push(stack* stk, int data)
{
	llist_prepend( stk -> top, data );
}

// pop the top element from the stack
int stack_pop(stack* stk)
{
	int size = llist_size( stk -> top );
	int val = stk -> top -> head -> data;
	llist_remove_first( stk -> top );
	return val;
}

// Check if stack is empty
bool stack_is_empty(stack* stk)
{
	if(stk -> top -> head == NULL)      // CHECK
		return true;
	else
		return false;
}

// find the size of the stack
int stack_size(stack* stk)
{
	int size = llist_size( stk -> top );
	return size;
}

// print stack element
void stack_print(stack* stk)
{
	llist_print( stk -> top );
}

//returns the rop element of the stack
int stack_top(stack* st)
{
    int x= stack_pop(st);
    stack_push(st,x);
    return x;
}



