#include "queue_using_stack.h"
#include "List.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
stack* queue_new()
{
	stack* S = stack_new();
	return S;
}

// add an element to the queue
void enqueue(stack* S, int data)
{
	stack* S2 = stack_new();
	
	while(!stack_is_empty(S))
	{
		stack_push( S2, stack_pop(S));
	}
	
	stack_push(S2, data);
	
	while(!stack_is_empty(S2))
	{
		stack_push( S, stack_pop(S2));
	}
	
	return;
}

// remove the front element from the queue
int dequeue(stack* S)
{
	return stack_pop(S);
}

// Check if queue is empty
bool queue_is_empty(stack* S)
{
	return stack_is_empty(S);
}

// find the size of the queue
int queue_size(stack* S)
{
	return stack_size(S);
}

// print queue element
void queue_print(stack* S)
{
	stack_print(S);
	return;
}
