#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()
{
	stack* stk;
	stk = (stack*)malloc(sizeof(stack));
	stk->top = llist_new();
	return stk;
}

bool stack_is_empty(stack* stk)
{
	return (stk->top->head == NULL);
}

void stack_push(stack* stk,int num)
{
	llist_prepend(stk->top,num);
}

int stack_pop(stack* stk)
{
	int x = stk->top->head->data;
	llist_remove_first(stk->top);
	return x;
}

int stack_size(stack* stk)
{
	return llist_size(stk->top);
}

void stack_print(stack* stk)
{
	llist_print(stk->top);
}