#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
//#include "List.c"
#include <stdbool.h>
/*
typedef struct Queue{
	LList* front;
	LList* rear;
}queue;*/

// create a new queue
queue* queue_new(){
	queue* q;
	q=(queue*)malloc(sizeof(queue));
	q->front=llist_new();
	q->rear=llist_new();
	return q;

}
// add an element to the queue
void enqueue(queue* Q, int data){
	int flag=1;
	if(queue_is_empty(Q)){
		flag=1;
	}
	llist_append(Q->front, data);
	if(flag==1)
		Q->rear->head=Q->front->head;
	else
		Q->rear->head=Q->rear->head->next;
	
}

// remove the front element from the queue
int dequeue(queue* Q){
	if(llist_size(Q->front)){
		int val=Q->front->head->data;

		llist_remove_first(Q->front);
		if(Q->front->head==NULL)
			Q->rear->head=NULL;
		return val;
	}
	return ;
}


// Check if queue is empty
bool queue_is_empty(queue* Q){
	return(Q->front->head==NULL);
}

// find the size of the queue
int queue_size(queue* Q){
	return llist_size(Q->front);
}

// print queue element
void queue_print(queue* Q){
	llist_print(Q->front);
}






/*


// create a new queue
queue* queue_new(){
	queue* newQ = (queue*)malloc(sizeof(queue));
	newQ->front=llist_new();
	newQ->rear=llist_new();
	return newQ;
}

// add an element to the queue
void enqueue(queue* q, int n){
	llist_append(q->rear,n);
	if(q->rear->head->next)
	q->rear->head=q->rear->head->next;
	if(q->front->head == NULL)
		q->front->head=q->rear->head;
}

// remove the front element from the queue
int dequeue(queue* q){
	int ans = llist_get(q->front,0);
	llist_remove_first(q->front);
	if(q->front == NULL) q->rear=NULL;
	return ans;
}

// Check if queue is empty
bool queue_is_empty(queue* q){
	return (!(q->front->head));
}

// find the size of the queue
int queue_size(queue* q){
	return(llist_size(q->front));
}

// print queue element
void queue_print(queue* q){
	llist_print(q->front);
}*/
