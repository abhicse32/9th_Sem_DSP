#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new()
{
	queue* new;
	new=(queue*)malloc(sizeof(queue));
	// created space for new queue
	new->arr=(int*)malloc(sizeof(int)*1000);
	new->front=-1;
	new->rear=-1;
	return new;
}

void enqueue(queue* new, int data)
{
	if(!queue_is_full(new))
	{
		if(queue_is_empty(new))
		{
			new->arr[0]=data;
			new->front++;
			new->rear++;
		}
		else
		{
			if(new->rear!=999)
			{
				new->rear++;
				new->arr[new->rear]=data;
			}
			else
			{
				new->rear=0;
				new->arr[new->rear]=data;
			}
			
		}
	}
}

int dequeue(queue* new)
{
	if(!queue_is_empty(new))
	{
		int x;
		x=new->arr[new->front];
		new->arr[new->front]=0;
		if(new->front==new->rear)
		{
			new->front=-1;
			new->rear=-1;
		} 
		else if(new->front!=999)
		{
		new->front++;
		}
		else
		{
		new->front=0;
		}
		return x;	
	}
		
}

bool queue_is_empty(queue* que)
{
	if(queue_size(que)==0)
	return 1;
	else
	return 0;
}

bool queue_is_full(queue* que)
{
	if(queue_size(que)==1000)
	return 1;
	else
	return 0;	
}

int queue_size(queue* new)
{
	if(new->front==-1)
	return 0;
	else if(new->front>new->rear)
	{
		return 1000-(new->front-new->rear-1);	
	}
	else
	return(new->rear-new->front+1);

}

void queue_print(queue* new)
{
	
		int x;
		x=new->front;
		while(x!=new->rear+1)
		{	
			if(x==999)
			{printf("%d ",new->arr[x]);
			x=0;
			continue;
			}
			printf("%d ",new->arr[x]);
			x++;
			
		}
	
}

