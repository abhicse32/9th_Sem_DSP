#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
// create a new stack
stack* stack_new()
{
	stack* s=(stack *)malloc(sizeof(stack));
	s->top=llist_new();
	return s;
}
// push an element on the stack
void stack_push(stack* s, int n)
{

		llist_prepend(s->top,n);

}
// pop the top element from the stack
int stack_pop(stack* s)
{
	if(stack_is_empty(s)==0)
	{
		int x;
		x=llist_get(s->top,0);
		llist_remove_first(s->top);
		return x;
	}
}
// Check if stack is empty
bool stack_is_empty(stack* s)
{
	if(s->top->head==NULL)
	{
		return true;
	}
	else
	{
		return false;
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
	llist_print(s->top);
}

