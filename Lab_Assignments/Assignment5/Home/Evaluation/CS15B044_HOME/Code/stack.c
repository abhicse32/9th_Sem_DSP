#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
// create a new stack
stack* stack_new()
{
	stack *s;
	s=(stack*)malloc(sizeof(stack*));
	s->top=llist_new();
	return s;
}

// push an element on the stack
void stack_push(stack* s, int a)
{
	llist_prepend(s->top,a);
}

// pop the top element from the stack
int stack_pop(stack* s)
{
	int a;
	a=llist_get(s->top,0);
	llist_remove_first(s->top);
	return a;
}

// Check if stack is empty
bool stack_is_empty(stack* s)
{
	if(s->top->head==NULL)
	return 1;
	else
	return 0;
}

// find the size of the stack
int stack_size(stack* s)
{
	int a;
	a=llist_size(s->top);
	return a;
}

// print stack element
void stack_print(stack *s)
{
	llist_print(s->top);
}
