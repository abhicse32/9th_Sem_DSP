#include "queue_using_stack.h"
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
/*  writing program for queue using only stack implementation*/
stack* queue_new()
{
	stack* new;
	new=stack_new();
	return new;
}

void enqueue(stack* stk, int data)
{
/* should proceed till the end push the element and then push every elements remaining*/	
	stack* new;
	new=stack_new();
	if(!stack_is_empty(stk))
	{
	while(!stack_is_empty(stk))
	{
		int x;
		x=stack_pop(stk);
		stack_push(new,x);
	}	
	stack_push(stk,data);
	while(!stack_is_empty(new))
	{
		int x;
		x=stack_pop(new);
		stack_push(stk,x);
	}
	}
	else
	{
	stack_push(stk,data);
	}
}
/* these functions are similar to stack*/
int dequeue(stack* stk)
{
	return stack_pop(stk);
}

bool queue_is_empty(stack* stk)
{
	return stack_is_empty(stk);
}


int queue_size(stack* stk)
{
	return stack_size(stk);
}

void queue_print(stack* stk)
{
	stack_print(stk);
}
