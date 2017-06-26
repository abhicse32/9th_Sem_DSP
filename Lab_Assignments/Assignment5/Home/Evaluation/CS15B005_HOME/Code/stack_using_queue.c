#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


// create a new stack
queue* stack_new()
{
	queue* Q = queue_new();
	return Q;
}

// push an element on the stack
void stack_push(queue* Q, int data)
{
	int temp;
	
	queue* Q2 = queue_new();
	
	enqueue(Q2, data);
	
	while(!stack_is_empty(Q))
	{
		temp = dequeue(Q);
		enqueue(Q2 , temp);
	}
	
	while(!stack_is_empty(Q2))
	{
		temp = dequeue(Q2);
		enqueue(Q , temp);
	}
	return;
}

// pop the top element from the stack
int stack_pop(queue* Q)
{
	int temp = dequeue(Q);
	return temp;
}

// Check if stack is empty
bool stack_is_empty(queue* Q)
{
	int temp = queue_is_empty(Q);
	return temp;
}

// find the size of the stack
int stack_size(queue* Q)
{
	int size;
	size = queue_size(Q);
	return size;
}

// print stack element
void stack_print(queue* Q)
{
	queue_print(Q);
	return;
}

