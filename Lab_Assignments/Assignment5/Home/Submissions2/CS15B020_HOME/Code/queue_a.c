#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 1000


queue* queue_new()
	{
		queue* que;
		que=(queue*)malloc(1*sizeof(queue));
		int* a;
		a=(int*)malloc(SIZE*sizeof(int));
		que->arr=a;
		que->front=0;
		que->rear=-1;
		return que;
	}

void enqueue(queue* que, int m)
	{
		if(queue_is_full(que))
		{
			return;
		}
		else
		{
			que->rear=que->rear+1;
			(que->arr)[que->rear]=m;
		}
	}

int dequeue(queue* que)
	{
	
		if(queue_is_empty(que))
		{
			return -1;
		}
		else
		{
			int x;
			x=(que->arr)[que->front];
			que->front=que->front+1;
			return x;
		}
	}
		

int queue_size(queue* que)
	{
		int sz;
		sz=((que->rear)-(que->front)+1+SIZE)%(SIZE);
		return sz;
	}

bool queue_is_full(queue* que)
	{
		if(queue_size(que)==SIZE-1) return 1;
		else return 0;
	}

bool queue_is_empty(queue* que)
	{
		if(queue_size(que)==0) return 1;
		else return 0;
	}

void queue_print(queue* que)
	{
		int i;
		i=que->front;
		if(queue_is_empty(que)!=1)
		{
		  while(i!=(que->rear+1+SIZE)%SIZE)
			{
				printf("%d ",(que->arr)[i]);
				i=(i+1)%SIZE;
			}
			//printf("\n");
		}
	}
			
