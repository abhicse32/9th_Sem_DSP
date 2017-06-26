/*D TEJA VARDHAN REDDY CS15B014  18/9/16*/
/* QUEUE LINKED LIST FUNCTIONS*/

#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue* queue_new(){
	queue*a=(queue*)malloc(sizeof(queue));
	a->front=llist_new();
	a->rear=llist_new();
		
}

// add an element to the queue
void enqueue(queue*a, int data){
	if(llist_size(a->front)){

		llist_append( a->rear, data );
		(a->rear)->head=((a->rear)->head)->next;
	}
	else
	{
		llist_append( a->front, data);
		(a->rear)->head=(a->front)->head;
	}

}
// remove the front element from the queue
int dequeue(queue*a){
	if(llist_size(a->front)){
		int data=llist_get(a->front,0 );
		llist_remove_first(a->front);
		return data;
	}
}

// Check if queue is empty
bool queue_is_empty(queue*a){
	if(llist_size(a->front))
		return 0;
	else 
		return 1;

}
// find the size of the queue
int queue_size(queue*a){
	return llist_size(a->front);
}
// print queue element
void queue_print(queue*a){
	llist_print(a->front);
}