/*Implements all funtions listed in queue_a.h
Y BHARGAVA SAI CS15B042 18-Sep-2016*/
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new queue
queue* queue_new(){
	queue* q = (queue*)malloc(sizeof(queue));
	q -> arr = (int*)malloc(sizeof(int)*size);
	q -> front = 0;
	q -> rear = size - 1;
	return q;
}

// add an element in the queue
void enqueue(queue* q, int x){
	if(!queue_is_full(q)){
		q -> rear++;
		q -> rear = q -> rear % size;
		q -> arr[q -> rear] = x;
	}	
}

// remove the first element from the queue
int dequeue(queue* q){
	if(!queue_is_empty(q)){
		int x = q -> arr[q -> front];
		q -> front++;
		q -> front = q -> front % size;
		return x;
	}
}

// Check if queue is empty
bool queue_is_empty(queue* q){
	int x = q -> rear + 1;
	x = x % size;
	if(x == q -> front) return 1;
	else return 0;
}

// bool check if queue is full
bool queue_is_full(queue* q){
	int x = q -> rear + 2;
	x = x % size;
	if(x == q -> front) return 1;
	else return 0;
}

// find the size of the queue
int queue_size(queue* q){
	return (q->rear - q->front + 1 + size)%size;
}

// print queue element
void queue_print(queue* q){
	int i = 0;
	while(i < queue_size(q)){
		printf("%d ",q -> arr[(i + q -> front)%size]);
		i++;
	}
}

