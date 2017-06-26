#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 1000

// create a new queue
queue* queue_new()
{
	queue* q=(queue*) malloc(sizeof(queue));
	q->front=0;
	q->rear=size-1;
	int* A=calloc(size,sizeof(int));
	q->arr=A;
	return q;
}

// add an element in the queue
void enqueue(queue* q, int n)
{
	if(!queue_is_full(q))
	{
		q->rear=(q->rear+1)%size;
		q->arr[q->rear]=n;
		
	}
//else printf("98");
}

// remove the first element from the queue
int dequeue(queue* q)
{

	if(!queue_is_empty(q))
	{
	q->front=(q->front+1)%size;
	return q->arr[(q->front-1+size)%size];
	}
else return INT_MIN;
}

// Check if queue is empty
bool queue_is_empty(queue* q)
{
if((q->rear-q->front+1+size)%size==0)
return 1;
else
return 0;
}

// bool check if queue is full
bool queue_is_full(queue* q)
{
if((q->rear-q->front+1+size)%size==size-1)
return 1;
else
return 0;
}

// find the size of the queue
int queue_size(queue* q)
{
return (q->rear-q->front+1+size)%size;
}

// print queue element
void queue_print(queue* q)
{
int s=queue_size(q);
int i;
for(i=q->front;i-q->front<s;i++)
printf("%d ",q->arr[(i)%size]);

}

