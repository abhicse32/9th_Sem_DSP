#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()								// create a new queue
{
	queue* q;
	q=(queue*)malloc(sizeof(q));
	q->front=llist_new();
	return q;
}

void enqueue(queue* q, int data)				// add an element to the queue
{
	llist_append(q->front,data);				//enqueue is equivalent to append
}

int dequeue(queue* q)							// remove the front element from the queue
{
	int element=q->front->head->data;
	llist_remove_first(q->front);				//dequeue is equivalent to remove first
	return element;
}

bool queue_is_empty(queue* q)					// Check if queue is empty
{
	if(q->front->head==NULL) return 1;			//returns 1 if queue is empty
	return 0;									//else return 0
}

int queue_size(queue* q)						// find the size of the queue
{
	return llist_size(q->front);				//queue's size is just list size 
}

void queue_print(queue* q)						// print queue elements
{
    LList* lst=q->front;
    Node* cur;
    cur= lst->head;
    while(cur!=NULL)                             //Loops till last element               
    {
        printf("%d ",cur->data);
        cur=cur->next;
    }
}
