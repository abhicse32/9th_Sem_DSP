#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// create a new queue
queue* queue_new(){
	queue* que= (queue*)malloc(sizeof(queue));
	que->front= llist_new();
	que->rear = llist_new();
	return que;
}

// push an element in the queue
void enqueue(queue* que, int data){
	if(!que->front->head){
		llist_append(que->front,data);
		que->rear->head= que->front->head;

	}else{ 
		llist_append(que->rear,data);
		que->rear->head= que->rear->head->next;
	}
}

// pop the top element from the queue
int dequeue(queue*que){
	int retVal= llist_get(que->front,0);
	llist_remove_first(que->front);
	if(!que->front->head)
		que->rear->head=NULL;
	return retVal;
}

// Check if queue is empty
bool queue_is_empty(queue*que){
	return que->front->head? false:true;
}

// find the size of the queue
int queue_size(queue* que){
	return llist_size(que->front);
}

// print queue element
void queue_print(queue* que){
	llist_print(que->front);
}