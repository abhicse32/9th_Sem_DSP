#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define size 1000

// create a new queue
queue* queue_new(){
	queue* Q=(queue*)malloc(sizeof(queue));
	Q->arr=(int*)malloc(size * sizeof(int));
	Q->front=-1;
	Q->rear=-1;
	return Q;
}

// Check if queue is empty
bool queue_is_empty(queue* Q){
	if(Q->rear==-1 ){
		return true;
	}
	else{
		return false;
	}
}

// bool check if queue is full
bool queue_is_full(queue* Q){

	if(Q->rear>=size){
		return true;
	}
	else{
		return false;
	}
}


// add an element in the queue
void enqueue(queue* Q, int data){
	if(queue_is_full(Q)){
		return;
	}
	else if(queue_is_empty(Q)){
		Q->front=0;
		Q->rear=0;
	}
	else{
		Q->rear++;
	}
	Q->arr[Q->rear]=data;
}

// remove the first element from the queue
int dequeue(queue* Q){
	if(queue_is_empty(Q)){
		return INT_MIN;
	}
	else if(Q->front==Q->rear){
		int y=Q->arr[Q->front];
		Q->front=-1;
		Q->rear=-1;
		return y;
	}
	else{
		int x;
		x=Q->arr[Q->front];
		Q->front++;
		return x;
	}
}

// find the size of the queue
int queue_size(queue* Q){
	int x;
	x=(Q->rear)-(Q->front)+1;
	return x;
}

// print queue element
void queue_print(queue* Q){
	if(queue_is_empty(Q)){
		return;
	}
	else{
		int i;
		for(i=(Q->front);(i<=Q->rear);i++){
			printf("%d ",Q->arr[i]);
		}
	}
}

