#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// create a new queue
queue* queue_new(){
	queue* Q=(queue*)malloc(sizeof(queue));
	Q->front=llist_new();
	Q->rear=llist_new();
	return Q;
}

// add an element to the queue
void enqueue(queue* Q, int data){
	Node* new=(Node*)malloc(sizeof(Node));
	new=node_new(data);
	if((Q->rear)->head==NULL && (Q->front)->head==NULL){
		(Q->rear)->head=(Q->front)->head=new;
		return;
	}
	else{
		((Q->rear)->head)->next=new;
		(Q->rear)->head=new;
	}
}

// remove the front element from the queue
int dequeue(queue* Q){
	Node* temp=(Q->front)->head;
	if((Q->front)->head==NULL && (Q->rear)->head==NULL){
		return INT_MIN;
	}
	if((Q->front)->head==(Q->rear)->head){
		(Q->front)->head=(Q->rear)->head=NULL;
		return temp->data;
	}
	else{
		(Q->front)->head=((Q->front)->head)->next;
		return temp->data;
	}
	free(temp);	
		
}

// Check if queue is empty
bool queue_is_empty(queue* Q){
	if((Q->front)->head==NULL && (Q->rear)->head==NULL){
		return true;
	}
	else{
		return false;
	}
}

// find the size of the queue
int queue_size(queue* Q){
	if(queue_is_empty(Q)){
		return 0;
	}
	else{
		return llist_size(Q->front);
	}
}
	

// print queue element
void queue_print(queue* Q){
	if(queue_is_empty(Q)){
		return;
	}
	else{
		llist_print(Q->front);
	}
}
