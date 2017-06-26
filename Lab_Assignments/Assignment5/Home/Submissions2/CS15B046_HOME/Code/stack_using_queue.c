/*To simulate a stack using queue
  Author: CS15B046 Jahnvi Patel
  September 11th, 2016
*/
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include "stack_using_queue.h"

// push an element on the stack
void stack_push(queue* q, int val)
{
	queue* temp=queue_new();
	int p;
	enqueue(temp,val);
	
	while(!queue_is_empty(q))
	{

		p=dequeue(q);
		enqueue(temp,p);
	}
	
	*q=*temp;
	
}
//create a new stack

queue* stack_new()
{	
	return queue_new();
}


//pop an element from the stack

int stack_pop(queue* q)
{
	return dequeue(q);
		
}

// Check if stack is empty
bool stack_is_empty(queue* q)
{
	return queue_is_empty(q);
}

// find the size of the stack

int stack_size(queue* q)
{
	return queue_size(q);
}

// print stack element
void stack_print(queue* q)
{
	queue_print(q);
		
}

