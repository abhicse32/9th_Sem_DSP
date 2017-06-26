/*To simulate a queue using stack
  Author: CS15B046 Jahnvi Patel
  September 11th, 2016
*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue_using_stack.h"

stack* queue_new()
{
	return stack_new();
}

// add an element to the queue
void enqueue(stack* s, int val)
{
	stack* temp=stack_new();
	
	int p;
	
	
	while(!stack_is_empty(s))
	{

		p=stack_pop(s);
		stack_push(temp,p);
	}
	stack_push(temp,val);
	
	while(!stack_is_empty(temp))
	{

		p=stack_pop(temp);
		stack_push(s,p);
	}
	
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


	