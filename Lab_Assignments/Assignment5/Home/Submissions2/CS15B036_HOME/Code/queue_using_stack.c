#include "queue_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a new queue
stack* queue_new()
{
	stack* stk = stack_new();
}

// add an element to the queue
void enqueue(stack* stk, int x)
{
	stack_push(stk,x);
}

// remove the front element from the queue
int dequeue(stack* stk)
{
	stack* P=stack_new();
	int temp;
	if(stack_size==0)
	return -1;
	while(!stack_is_empty(stk))
	{
		temp=stack_pop(stk);
		stack_push(P,temp);
	}
	int val=stack_pop(P);
	while(!stack_is_empty(P))
	{
		temp=stack_pop(P);
		stack_push(stk,temp);
	}
	return val;
}

// Check if queue is empty
bool queue_is_empty(stack* stk)
{
	if(stack_size==0)
	return true;
	else
	return false;
}

// find the size of the queue
int queue_size(stack* stk)
{
	int val=stack_size(stk);
	return val;
}

// print queue element
void queue_print(stack* stk)
{	
	stack* P=stack_new();
	int temp;
	if(stack_size(stk)==0)
	return;
	while(!stack_is_empty(stk))
	{
		temp=stack_pop(stk);
		stack_push(P,temp);
	}
	stack_print(P);
	while(!stack_is_empty(P))
	{
		temp=stack_pop(P);
		stack_push(stk,temp);
	}

}
