/*Implements all funtions listed in queue.h
Y BHARGAVA SAI CS15B042 18-Sep-2016*/
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue* queue_new(){
	queue* q = (queue*)malloc(sizeof(queue));
	q -> front = llist_new();
	q -> rear = llist_new();
	//q -> rear = q -> front;
}

// add an element to the queue
void enqueue(queue* q, int x){
	llist_append(q -> rear,x);
	if(q -> front -> head == NULL){
		q -> front -> head = q -> rear -> head;
	}
	else{
		q -> front -> head = q -> front -> head -> next;
	}
}

// remove the front element from the queue
int dequeue(queue* q){
	if(queue_is_empty(q)) return -2147483648;
	int x = q -> rear -> head -> data;
	q -> rear -> head = q -> rear -> head -> next;
	if(q -> rear -> head == NULL){
		q -> front -> head = q -> rear -> head;
	}
	return x;
}

// Check if queue is empty
bool queue_is_empty(queue* q){
	if(q -> rear -> head == NULL) return 1;
	return 0;	
}

// find the size of the queue
int queue_size(queue* q){
	return llist_size(q -> rear);
}

// print queue element
void queue_print(queue* q){
	llist_print(q -> rear);
	fflush(stdout);
}