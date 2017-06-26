#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#define int_min -10

stack* stack_new()
{
	stack *new;
	new=(stack *)malloc(sizeof(stack));
	new->top=llist_new();
	return new;
}

void stack_push(stack* stk, int data)
{
	LList *llist;
	llist=stk->top;
	llist_prepend(llist,data);
}

int stack_pop(stack* stk)
{
	LList *llist;
	int i;
	llist=stk->top;
	if (llist->head==NULL)
		return int_min;
	else
	{
		i=llist->head->data;
		llist_remove_first(llist);
		return i;
	}
}

bool stack_is_empty(stack* stk)
{
	LList *llist;
	llist=stk->top;
	if (llist_size(llist)==0)
		return true;
	else
		return false;
}

int stack_size(stack* stk)
{
	LList *llist;
	llist=stk->top;
	return llist_size(llist);
}

void stack_print(stack* stk)
{
	LList *llist;
	llist=stk->top;
	llist_print(llist);
}
	



