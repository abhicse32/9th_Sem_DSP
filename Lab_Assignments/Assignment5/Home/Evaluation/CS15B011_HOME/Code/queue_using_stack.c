#include "queue_using_stack.h"
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* queue_new()
{
	stack* s = stack_new();
	return s;
}

void enqueue(stack* s, int data)
{
	int x;
	stack* temp = stack_new();
	while(!stack_is_empty(s))
	{
		x = stack_pop(s);
		stack_push(temp, x);
	}
	stack_push(s,data);
	while(!stack_is_empty(temp))
	{
		x = stack_pop(temp);
		stack_push(s , x);
	}
}

int dequeue(stack* s)
{
	return stack_pop(s);
}

bool queue_is_empty(stack* s)
{
	return stack_is_empty(s);
}

int queue_size(stack* s)
{
	return stack_size(s);
}

void queue_print(stack* s)
{
	stack_print(s);
}