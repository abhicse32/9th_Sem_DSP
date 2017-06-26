#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
queue* queue_new()										// create a new queue
{
	queue* q;
	q=(queue*)malloc(sizeof(queue));
	int q->arr[size];									//Declaration of array
	q->rear=-1;											//q->rear is index of last added element 
	q->front=0;											//q->front is the index of the element to be popped
	return q;
}

void enqueue(queue* q, int data)						//Adds an element to the queue
{
	if(queue_is_full(q)) return;
	q->rear=q->rear + 1;
	if(q->rear==size) q->rear=0;						//if queue is not full and q->rear ==size then set q->rear=0
	q->arr[q->rear]=data;								//Store the value in arr
}

int dequeue(queue* q)									//Removes the element added first
{
	if(queue_is_empty(q)) return;
	int element=q->arr[(q->front)];
	q->front=q->front + 1;								
	if(q->front==size) q->front=0;						//if queue is not empty and q->front ==size then set q->front=0
	return element;
}

bool queue_is_empty(queue* q)										// Check if queue is empty
{
	if((q->rear + 1 - q->front)==0) return 1;						//queue_size= q->rear + 1 - q->front
	return 0;
}

bool queue_is_full(queue* q)
{
	if((q->rear + 1 - q->front)==size) return 1;					//queue_size=q->rear + 1 - q->front
	return 0;
}

int queue_size(queue* q)											//Returns the size of the queue
{
	return ((q->rear + 1 - q->front));
}

void queue_print(queue* q)											//Prints the queue
{
	int i;
	for(i=q->front;i<=q->rear;i++) printf("%d ",q->arr[i]);
}
