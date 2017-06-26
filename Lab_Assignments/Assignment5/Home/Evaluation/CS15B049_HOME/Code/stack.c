#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


// Check if stack is empty
bool stack_is_empty(stack* a)
{
	if( (a->top)->head == NULL )
	{
		return true;
	}
	else 	
	{
		return false;
	}
}


// create a new stack
stack* stack_new()
{
	stack* ptr = (stack*)malloc(sizeof(stack));

	if(ptr!=NULL)
	{
		ptr->top = llist_new();
	}
	else
	{
		exit(1);
	}

	return ptr;
}

// push an element on the stack
void stack_push(stack* s, int data)
{
	llist_prepend(s->top,data );
}

// pop the top element from the stack
int stack_pop(stack* s)
{
	if(stack_is_empty(s)==false)
	{
		int k;
		k = ( (s->top)->head)->data;
	
		llist_remove_first(s->top);
		
		return k;		
	}
}

// find the size of the stack
int stack_size(stack* s)
{
	return llist_size(s->top);
}

// print stack element
void stack_print(stack* s)
{
	if(stack_is_empty(s)==false)
	{
		llist_print(s->top);
	}
}


