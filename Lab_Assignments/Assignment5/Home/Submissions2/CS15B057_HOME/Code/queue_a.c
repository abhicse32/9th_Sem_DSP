/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
*/
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 1000
// create a new queue
queue* queue_new(){
	queue* temp=(queue*)malloc(sizeof(queue));
	temp->arr=(int*)malloc(sizeof(int));
	temp->front=temp->rear=-1;
	return temp;
}

// add an element in the queue
void enqueue(queue* q, int data){
	if(queue_is_full(q)) return;
	if(q->front==-1) {
		q->front=0;
		(q->rear)=0;
	}
	else if(q->rear==size-1){
		q->rear=0;
	}
	else (q->rear)++;
	(q->arr)[(q->rear)]=data;
}

// remove the first element from the queue
int dequeue(queue* q){
	if(q->front==-1) return INT_MIN;
	int save=(q->arr)[q->front];
	if(q->front==q->rear) q->front=q->rear=-1;
	else if(q->front==size-1) q->front=0;
	else (q->front)++;
	return save;
}

// Check if queue is empty
bool queue_is_empty(queue* q){
	if(q->front==-1) return true;
	return false;
}

// bool check if queue is full
bool queue_is_full(queue* q){
	if(q->front==0&&q->rear==(size-1)) return true;
	if(q->front==(q->rear)+1) return true;	
	return false;
}

// find the size of the queue
int queue_size(queue* q){
	if(q->front==-1) return 0;
	if(q->rear>=q->front) return (q->rear-q->front+1);
	return(size-q->front+q->rear+1);
}

// print queue element
void queue_print(queue* q){
	if(q->front==-1) return;
	int i;	
	for(i=q->front;i<=q->rear;i++){
		printf("%d ",(q->arr)[i]);
	}
}
