#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new(){
	queue* q = malloc(sizeof(queue));
	q->front = llist_new();																	// Allocating space for strings
	q->rear = llist_new();
	return q;
}

void enqueue(queue* q, int i){																
	if(!queue_is_empty(q)){
		q->rear->head->next = node_new(i);												// In other cases appending it at rear position	
		q->rear->head = q->rear->head->next;
		return;
	}
	llist_prepend(q->front, i);														// WHen it is empty	
	q->rear->head = q->front->head;	
	return;

}

int dequeue( queue* q ){
	if(queue_is_empty(q)) return ;													// Returning nothing when it is empty														
	int t = q->front->head->data;
	llist_remove_first(q->front);
	return t;
}

bool queue_is_empty(queue *q){
	if( q->front->head == NULL)														// If front head is pointing to null it is empty
		return true;
	return false;
}

int queue_size(queue* q){
	int size = llist_size(q->front);												// Size of list
	return size;	
}

void queue_print(queue* q){
	llist_print(q->front);															// Printing the list
	fflush(stdout);
	return;
}
