#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
queue* stack_new()
{
	queue * que;
	que = queue_new();
	return que;
}


void reverse(queue* q1, queue* q2){
	int x;
	x=dequeue(q1);
	if(!queue_is_empty(q1))
		reverse(q1, q2);
	enqueue(q2, x);
}

// push an element on the stack
void stack_push(queue* que, int data)
{
	if(queue_is_empty(que))
	{
		enqueue(que, data);
		return;
	}

	queue *temp=queue_new();
	int x;

	reverse(que, temp);
	enqueue(temp, data);
	reverse(temp, que);
}


// pop the que element from the stack
int stack_pop(queue* que)
{
	return dequeue(que);
}

// Check if stack is empty
bool stack_is_empty(queue* que)
{
	return queue_is_empty(que);
}

// find the size of the stack
int stack_size(queue* que)
{
	return queue_size(que);
}

// print stack element
void stack_print(queue* que)
{
	queue_print(que);
}

