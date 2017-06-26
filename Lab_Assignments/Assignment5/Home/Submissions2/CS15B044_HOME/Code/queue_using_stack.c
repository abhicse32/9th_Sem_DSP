#include "stack.h"
#include <stdbool.h>
#include "queue_using_stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
// create a new queue
stack* queue_new()
{
	stack *s;
	s=stack_new();
	return s;
}

// add an element to the queue
void enqueue(stack* s, int a)
{
	stack *temp;
	temp=stack_new();
	int b;
	while(!stack_is_empty(s))
	{
		b=stack_pop(s);
		stack_push(temp,b);
	}
	stack_push(s,a);
	while(!stack_is_empty(temp))
	{
		b=stack_pop(temp);
		stack_push(s,b);
	}
	free(temp);
}

// remove the front element from the queue
int dequeue(stack* s)
{
	return stack_pop(s);
}

// Check if queue is empty
bool queue_is_empty(stack* s)
{
	return stack_is_empty(s);
}

// find the size of the queue
int queue_size(stack* s)
{
	return stack_size(s);
}
// print queue element
void queue_print(stack* s)
{
	stack_print(s);
}

