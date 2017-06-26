#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// create a new stack
queue* stack_new()
{
	queue* st=queue_new();
	return st;
}

// push an element on the stack
void stack_push(queue* stck, int data)
{
	int oldsize=queue_size(stck); 
	int i;
	enqueue(stck,data);					//first we enqueue new element
	for(i=0;i<oldsize;i++) 				//we then enqueue and dequeue repeatedly for other elements
	{
		enqueue(stck,dequeue(stck));
	}
}

// pop the top element from the stack
int stack_pop(queue* stck)				//dequeue does the same as pop
{
	dequeue(stck);
}

// Check if stack is empty
bool stack_is_empty(queue* stck)	
{
	return queue_is_empty(stck);
}

// find the size of the stack
int stack_size(queue* stck)
{
	return queue_size(stck);
}

// print stack element
void stack_print(queue* stck)
{
	queue_print(stck);	
}