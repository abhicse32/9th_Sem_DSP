#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue* queue_new()
{
	queue* que = (queue*) malloc (sizeof(queue));
	que -> front = llist_new();
	que -> rear  = llist_new();
	return que;
}

// add an element to the queue
void enqueue(queue* que, Node* data)
{
	
	if(queue_is_empty(que))
	{
		llist_append( que -> front, data->data );
		que -> rear -> head = que -> front -> head;
	}
	else
	{
		llist_append( que -> front, data->data );
		que -> rear -> head = que -> rear -> head -> next;
	}
}


// remove the front element from the queue
Node* dequeue(queue* que)
{
	if(queue_is_empty(que))
		return NULL; 
	
	Node* val = que -> front -> head ;
	que -> front -> head = que -> front -> head -> next;
	if(que -> front -> head == NULL)
		que -> rear -> head = NULL;

	return val;
}

// Check if queue is empty
bool queue_is_empty(queue* que)
{
	if(que -> front -> head == NULL)      
		return true;
	else
		return false;
}

// find the size of the queue
int queue_size(queue* que)
{
	int size = llist_size( que -> front );
	return size;
}

void queue_print(queue* que)
{
llist_print(que->front);

return;
}

