#include "queue_using_stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
stack* queue_new()
{
	stack* q = (stack*) malloc(sizeof(stack));
	q -> top = llist_new();
	return q;
}

// add an element to the queue
void enqueue(stack* q, int num)
{
	llist_append(q -> top, num);
}

// remove the front element from the queue
int dequeue(stack* q)
{
	int pop = llist_get(q -> top, 0);
	llist_remove_first(q -> top);
	return pop;
}

// Check if queue is empty
bool queue_is_empty(stack* q)
{
	if(q -> top -> head)	return 0;
	else			return 1;
}

// find the size of the queue
int queue_size(stack* q)
{
	return llist_size(q -> top);
}

// print queue element
void queue_print(stack* q)
{
	llist_print(q -> top);
}

