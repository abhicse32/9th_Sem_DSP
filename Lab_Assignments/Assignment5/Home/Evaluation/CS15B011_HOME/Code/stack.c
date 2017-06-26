#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()
{
	stack* s = (stack*) malloc(sizeof(stack));
	s->top = llist_new();
	return s;
}

void stack_push(stack* s, int data)
{
	LList *lst = s->top;
	llist_prepend( lst, data );
}

int stack_pop(stack* s)
{
	LList * lst = s->top;
	int a = lst->head->data;
	lst->head = (lst->head)->next;
	return a;
}

bool stack_is_empty(stack* s)
{
	if(s->top->head == NULL)
		return true;
	else
		return false;
}

int stack_size(stack* s)
{
	LList * lst = s->top;
	llist_size( lst );
}

void stack_print(stack* s)
{
	LList * lst = s->top;
	llist_print( lst );
}
