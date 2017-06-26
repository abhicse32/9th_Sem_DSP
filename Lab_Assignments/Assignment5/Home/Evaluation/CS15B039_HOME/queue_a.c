#include "queue_a.h"
#include "List.c"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define size 1000

// create a new queue
queue* queue_new(){
	//One node is a dummy
	queue * newQ = (queue *) malloc (sizeof(queue));
	newQ->arr = (int *) malloc ((size) * sizeof(int));
	newQ->front = 0;
	newQ->rear = size-1;
	return newQ;
}

// find the size of the queue
int queue_size(queue* Q){
	//One element remains empty
	return ((Q->rear - Q->front + 1 +size) % size);
}

// Check if queue is empty
bool queue_is_empty(queue* Q){

	return (queue_size(Q) == 0);
}

// bool check if queue is full
bool queue_is_full(queue* Q){

	return (queue_size(Q) == size-1);
}

// add an element in the queue
void enqueue(queue* Q, int n){

	if(!queue_is_full(Q)){
		Q->rear = (Q->rear + 1) % size;
		(Q->arr)[Q->rear] = n;
	}
}

// remove the first element from the queue
int dequeue(queue* Q){
	int x = INT_MAX;
	if(!queue_is_empty(Q)){
		x = (Q->arr)[Q->front];
		Q->front = (Q->front + 1) % size;
		}
	return x;
}

// print queue element
void queue_print(queue* Q){
	int x;
	int i = Q->front;
	int len = queue_size(Q);
	while(len!=0){
		x = (Q->arr)[i];
		printf("%d ", x);
		i = (i+1) % size;
		len--;
	}
	//printf("\n");	
}
