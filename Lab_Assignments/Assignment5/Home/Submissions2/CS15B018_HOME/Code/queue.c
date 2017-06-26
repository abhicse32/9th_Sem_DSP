#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue* queue_new()
{
	queue* q = (queue*) malloc(sizeof(queue));
	q -> front = llist_new();
	q -> rear  = llist_new();
	return q;
}

// Check if queue is empty
bool queue_is_empty(queue* q)
{
	if(q -> rear -> head)	return 0;
	else			return 1;
}

// add an element to the queue
void enqueue(queue* q, int num)
{
	if (queue_is_empty(q))
    	{
		llist_append(q -> front, num);
		llist_append(q -> rear, num);
	}

    	else
    	{
		llist_append(q -> rear, num);
	}  
}

// find the size of the queue
int queue_size(queue* q)
{
	return llist_size(q -> rear);
}

// remove the front element from the queue
int dequeue(queue* q)
{

	int l = queue_size(q);
	if(queue_is_empty(q));
	else if(l == 1)	printf("\n");
	else
	{
		int pop = llist_get(q -> rear, 0);
		llist_remove_first(q -> rear);
		return pop;
	}
}

// print queue element
void queue_print(queue* q)
{
	llist_print(q -> rear);
}
