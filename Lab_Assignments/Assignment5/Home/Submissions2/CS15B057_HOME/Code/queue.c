/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
*/
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
// create a new queue
queue* queue_new(){
	queue* temp=(queue*)malloc(sizeof(queue));
	temp->front=llist_new();
	temp->rear=temp->front;
	return temp;
}

// add an element to the queue
void enqueue(queue* q, int data){
	if(queue_size(q)==0){
		llist_append(q->rear,data);
		q->front=q->rear;
	}
	else{
		llist_append(q->rear,data);
	}
}

// remove the front element from the queue
int dequeue(queue* q){
	if(queue_is_empty(q)) return INT_MIN;
	int save=q->front->head->data;
	Node* temp=q->front->head;
	q->front->head=q->front->head->next;
	if(q->front->head==NULL) q->rear=q->front;
	free(temp);
	return save;
}

// Check if queue is empty
bool queue_is_empty(queue* q){
	if(q->front->head==NULL) return true;
	return false;
}

// find the size of the queue
int queue_size(queue* q){
	Node* temp=q->front->head;
	int ans=0;
	while(temp!=NULL){
		ans++;
		temp=temp->next;
	}
	return ans;
}

// print queue element
void queue_print(queue* q){
	llist_print(q->front);
}
