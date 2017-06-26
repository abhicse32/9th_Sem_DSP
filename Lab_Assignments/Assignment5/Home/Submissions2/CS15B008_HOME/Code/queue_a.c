/* Program that implements basic queue functions using an array
	G.Pranav	CS15B015	18-9-2016	*/
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 1000

// create a new queue
queue* queue_new(){
	queue *queueptr=malloc(sizeof(queue));
	int *array=malloc(size*sizeof(int));
	queueptr->arr=array;
	queueptr->front=-1;
	queueptr->rear=-1;
	return queueptr;
}

// add an element in the queue
void enqueue(queue* queueptr, int x){
	if(!queue_is_full(queueptr)){
		if(queue_is_empty(queueptr)){
			queueptr->rear=0;
			queueptr->front=0;
		}
		else{
			queueptr->rear=((queueptr->rear)+1%size);
		}
		int *array=queueptr->arr;
		array[queueptr->rear]=x;
	}
}

// remove the first element from the queue
int dequeue(queue* queueptr){
	int ans;
	if(!queue_is_empty(queueptr)){
		int *array=queueptr->arr;
		if((queueptr->rear)==(queueptr->front)){
			ans=array[queueptr->rear];
			queueptr->rear=-1;
			queueptr->front=-1;
		}
		else{
			ans=array[queueptr->front];
			queueptr->front=((queueptr->front)+1)%size;
		}
		return ans;
	}
	else return INT_MIN;
}

// Check if queue is empty
bool queue_is_empty(queue* queueptr){
	if(queue_size(queueptr)==0) return 1;
	else return 0;
}

// bool check if queue is full
bool queue_is_full(queue* queueptr){
	if(queue_size(queueptr)==size) return 1;
	else return 0;
}

// find the size of the queue
int queue_size(queue* queueptr){
	if((queueptr->rear==-1)&&(queueptr->front==-1)) return 0;
	else if((queueptr->rear)<(queueptr->front)) return ((queueptr->rear)-(queueptr->front)+1+size);
	else return ((queueptr->rear)-(queueptr->front)+1);
}

// print queue element
void queue_print(queue* queueptr){
	int *array=queueptr->arr;
	int front=queueptr->front;
	int rear=queueptr->rear;
	int i;
	if(front<=rear){
		for(i=front;i<=rear;i++){
			printf("%d ",array[i]);
		}
	}
	else{
		for(i=front;i<=rear+size;i++){
			printf("%d ",array[i%size]);
		}
	}
}