#include "queue.h"
#include<limits.h>
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue* queue_new(){

	queue * newQ = (queue *) malloc (sizeof(queue));
	newQ->front = llist_new();
	newQ->rear = llist_new();
	return newQ;
}

// Check if queue is empty
bool queue_is_empty(queue* Q){
	
	return (queue_size(Q) == 0);
}

// add an element to the queue
void enqueue(queue* Q, int n){
	
	llist_append( Q->front, n);
	if(queue_size(Q)==1)
		Q->rear->head = Q->front->head;
	else
		Q->rear->head = (Q->rear->head)->next;
}

// find the size of the queue
int queue_size(queue* Q){
	
	return (llist_size(Q->front));
}

// remove the front element from the queue
int dequeue(queue* Q){

	int x = INT_MAX;
	if(!queue_is_empty(Q)){
		x = llist_get(Q->front, 0);
		llist_remove_first(Q->front);
	}
	return x;
}

// print queue element
void queue_print(queue* Q){

	llist_print(Q->front);
}
