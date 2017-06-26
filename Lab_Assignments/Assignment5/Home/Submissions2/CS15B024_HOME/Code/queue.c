#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
queue* queue_new()
{
	queue *q=(queue*)malloc(sizeof(queue));
	q->lst=llist_new();
	return q;
}
// add an element in the queue
void enqueue(queue* q, int p)
{
	llist_append(q->lst,p);
}
// remove the first element from the queue
int dequeue(queue* q)
{
	int x;
	x=llist_get(q->lst,0);
	llist_remove_first(q->lst);
	return x;
}
// Check if queue is empty
bool queue_is_empty(queue* q)
{
	if(q->lst->head==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
// find the size of the queue
int queue_size(queue* q)
{
	return llist_size(q->lst);
}
// print queue element
void queue_print(queue* q)
{
	llist_print(q->lst);
}

