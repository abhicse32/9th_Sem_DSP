// Defines functions defined in queue_using_stack.h
// Author : Milind Srivastava
// Date : 16 Sep 2016

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "queue_using_stack.h"

// create a new queue
stack* queue_new()
{
	stack* temp = stack_new();
	return temp;
}

// add an element to the queue
void enqueue(stack* st, int x)
{
	if(stack_size(st) == 0)
	{
		stack_push(st, x);
		return;
	}
	int temp = stack_pop(st);
	enqueue(st, x);
	stack_push(st, temp);	
}

// remove the front element from the queue
int dequeue(stack* st)
{
	if(stack_size(st) == 0)
	{
		return INT_MIN;
	}
	/*if(stack_size(st) == 1)
	{*/
		return stack_pop(st);
	//}
	/*int temp = stack_pop(st);
	int returnValue = dequeue(st);
	stack_push(st, temp);
	return returnValue;*/
}

// Check if queue is empty
bool queue_is_empty(stack* st)
{
	return stack_is_empty(st);
}

// find the size of the queue
int queue_size(stack* st)
{
	return stack_size(st);
}

// print queue element
void queue_print(stack* st)
{
	stack_print(st);
}