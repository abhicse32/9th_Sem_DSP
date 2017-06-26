//QUEUE USING ARRAY(CIRCULAR)
//AUTHOR -SARTHAK PANDEY

#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new()
{
	queue *new;
	new=(queue *)malloc(sizeof(queue));
	new->arr=(int *)malloc(sizeof(int)*size);                                                     //MAKES AN ARRAY OF SIZE 'size'
	new->front=-1;
	new->rear=-1;
	return new;
}

void enqueue(queue* q, int data)                                                                      //TO ENQUEUE , ADDS ELEMENT TO LAST
{
	if (q->front==-1&&q->rear==-1)                                                                //IF ARRAY WAS INITIALLY EMPTY
	{
		q->arr[0]=data;
		q->front=0;
		q->rear=0;
	}
	else if((q->rear-q->front+1+size)%(size+1)+1<size)                                            //IF ARRAY WAS NONEMPTY
	{
		int i;
		q->rear++;
		i=q->rear;
		q->arr[i]=data;
	}
}

int dequeue(queue* q)                                                                                 //DEQUEUES FROM FRONT
{
	if (q->front!=-1)
	{
	if (q->front<size-1)
	{
		int i=q->front;
		q->front++;
		if (q->front-1==q->rear)
		{
		q->front=-1;
		q->rear=-1;
		}
		return q->arr[i];
	}
	else if (q->front==size-1)
	{
		q->front=0;
		if(q->rear==size-1)
		{
			q->front=-1;
			q->rear=-1;
		}
		return q->arr[size-1];
	}
	}
	
}

bool queue_is_empty(queue* q)
{
	if (q->front==-1)                                                                             //IF FRONT ==-1 , THEN QUEUE IS EMPTY
		return true;
	else
		return false;
}

bool queue_is_full(queue* q)
{
	if((q->rear-q->front+1+size)%(size+1)+1==size)                                                //SIZE OF QUEUE='q->rear-q->front+1+size)%(size+1)+1'
		return true;
	else
		return false;
}

int queue_size(queue* q)
{
	return (q->rear-q->front+1+size)%(size+1)+1;
}

void queue_print(queue* q)                                                                            //PRINTS QUEUE
{
	if (q->front!=-1)
	{
	int i,p;
	p=q->front;
	for (i=0;i< (q->rear-q->front+1+size)%(size+1)+1;i++)
		printf ("%d ",q->arr[(p+i)%size]);
	}
}




	



	
		
		
	
	
