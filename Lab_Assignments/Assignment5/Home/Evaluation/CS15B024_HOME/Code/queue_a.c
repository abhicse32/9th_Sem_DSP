#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
queue* queue_new()
{
	queue* q=(queue*)malloc(sizeof(queue));
	q->arr=(int *)malloc(size*sizeof(int));
	q->front=0;
	q->rear=size-1;
	q->count=0;
}
// add an element in the queue
void enqueue(queue* q, int n)
{
	if(queue_is_full(q)!=1)
	{
		q->rear=(q->rear+1)%size;
		q->arr[q->rear]=n;
		q->count++;
	}		
	
}
// remove the first element from the queue
int dequeue(queue* q)
{
	int x;
	if(queue_is_empty(q)!=1)
	{
		x=q->arr[q->front];
		q->front=(q->front+1)%size;
		q->count--;
	}
	return x;

}
// Check if queue is empty
bool queue_is_empty(queue* q)
{
	return(q->count==0);
}
// bool check if queue is full
bool queue_is_full(queue* q)
{
	return(q->count==size);
}
// find the size of the queue
int queue_size(queue* q)
{
	return(q->count);
}
// print queue element
void queue_print(queue* q)
{
	int i=0;
	int j;
	j=q->front;
	while(i<q->count)	
	{
		printf("%d ",q->arr[j]);
		j=(j+1)%size;
		i++;
	}
		
}

