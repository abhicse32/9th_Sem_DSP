/* Program that implements basic queue functions using a linked list
	G.Pranav	CS15B015	18-9-2016	*/
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue* queue_new(){
	queue *queueptr=malloc(sizeof(queue));
	LList *listptr1=llist_new();
	LList *listptr2=llist_new();
	queueptr->front=listptr1;
	queueptr->rear=listptr2;
	return queueptr;
}

// add an element to the queue
void enqueue(queue* queueptr, int num){
	LList *listptr1=queueptr->front;
	LList *listptr2=queueptr->rear;
	if(queue_is_empty(queueptr)){
		Node *newnodeptr=node_new(num);
		listptr1->head=newnodeptr;
		listptr2->head=newnodeptr;
	}
	else{
		llist_append(listptr2,num);
		Node *nodeptr=listptr2->head;
		listptr2->head=nodeptr->next;
	}
}

// remove the front element from the queue
int dequeue(queue* queueptr){
	if(!queue_is_empty(queueptr)){
		LList *listptr=queueptr->front;
		int ans=llist_get(listptr,0);
		llist_remove_first(listptr);
		return ans;
	}
}

// Check if queue is empty
bool queue_is_empty(queue* queueptr){
	LList *listptr=queueptr->front;
	Node *startptr=listptr->head;
	if(startptr==NULL) return 1;
	else return 0;
}

// find the size of the queue
int queue_size(queue* queueptr){
	LList *listptr=queueptr->front;
	return llist_size(listptr);
}

// print queue element
void queue_print(queue* queueptr){
	LList *listptr=queueptr->front;
	llist_print(listptr);
}