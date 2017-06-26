#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define size 1000


// create a new queue
queue* queue_new()
{
	queue *Q=(queue*)malloc(sizeof(queue));
	Q->arr=(int*)malloc(100*sizeof(int));
	Q->front=-1;
	Q->rear=-1;
}

// add an element in the queue
void enqueue(queue *Q, int x)
{
	
	if(Q->front<0&&Q->rear<0)
	{
	Q->arr[0]=x;
	Q->front=Q->rear=0;
	return ;
	}
	if(queue_is_full(Q)==true)
	return ;
	
	
	int index= ((Q->rear+1)%size);
	Q->arr[index]=x;
	Q->rear=index;
	
}
// remove the first element from the queue
int dequeue(queue *Q)
{
	if(Q->front<0 && Q->rear<0)
	return (-1);
	int x=Q->arr[Q->front];
	if(Q->front==Q->rear)
	{
		Q->front=-1;
		Q->rear=-1;
		return x;
	}
	Q->front=(Q->front+1)%size;
	return x;
}
	

// Check if queue is empty
bool queue_is_empty(queue* Q)
{
	if(Q->front==Q->rear==-1)
	return true;
	else
	return false;
}

// bool check if queue is full
bool queue_is_full(queue* Q)
{
	if((Q->rear-Q->front+1)==size)
	return true;
	else
	return false;
}

// find the size of the queue
int queue_size(queue* Q) 
{
	if(Q->front<0&&Q->rear<0)
	return (0);
	if(queue_is_full(Q)==true)
	return size;
	else
	return (abs(Q->rear-Q->front)+1);
}

// print queue element
void queue_print(queue *Q)
{
	if(queue_is_empty(Q)==true)
	return;
	int i=0;
	int index;
	int count= abs(Q->rear-Q->front)+1;
	while(i<count)
	{
	index=(Q->front+i)%size;
	printf("%d ",Q->arr[index]);
	i++;
	}
}

