#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


stack* stack_new()
{
	stack *newstack;
	newstack = (stack *)malloc(sizeof(stack));
	newstack->top = (LList *)malloc(sizeof(LList));
	newstack->top->head = NULL;
	return newstack;
}


void stack_push(stack *s, int ele)
{
	llist_prepend(s->top, ele);
}


int stack_pop(stack *s)
{
	int x =  llist_get(s->top, 0);
	llist_remove_first(s->top);
	return x;
}


bool stack_is_empty(stack *s)
{
	if(s->top->head == NULL)
		return 1;
	else
		return 0;
}


int stack_size(stack *s)
{
	return llist_size(s->top);
}

void stack_print(stack *s)
{
	llist_print(s->top);
}

