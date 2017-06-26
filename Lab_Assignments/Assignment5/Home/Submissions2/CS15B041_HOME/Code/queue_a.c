#include "queue_a.h"
#include <stdio.h>
#include"List.h"
#include <stdlib.h>
#define size 1000


queue* queue_new()
{
	queue* q;
	q=(queue*)malloc(sizeof(queue));
	q->arr=(int*)malloc(100*sizeof(int));

	q.front=-1;
	q.rear=-1;
	

	return q;
}

void enqueue(queue* q, int n)
{
	if(q.front== -1 && q.rear==-1)
	{
		q.front=0;
		q.rear=0;
		q->arr[q.rear]=n;
	}
	
	else if(queue_is_full(Q)==true)
		return ;
	
	else if(q.front!=0 && q.rear==size-1)
	{
		q.rear=0;
		q->arr[q.rear]=n;
	}
	else
	{
		q->arr[q.rear+1]=n;
		q.rear++;
	}
		
}

int dequeue(queue* q)
{
	int x;
	if(front>=0)
	{
		x=q->arr[q.front];
		if(q.front == q.rear)
		{	q.front=-1;
			q.rear=-1;
			
			return x;
			
		}
		
		else if(q.front=size-1)
		{
			q.front=0;
			return x;
		}
		else
		{	
		q.front= (q.front+1)%size;
		return x;
		}
	if(q.front <0 && q.rear<0)
	return  -1;
		
}
	


bool queue_is_empty(queue* q)
{		
	if(queue_size(q)==0)
	return 1;
	else
	return 0;
}


bool queue_is_full(queue* q)
{
	if((q->rear-q->front+1)==size)
	return true;
	else
	return false;
}

int queue_size(queue*)
{
	int c;
	if(q.rear== -1 && q.front==-1)
	return 0;
	else if(q.front==0 && q.rear >0)
	{
		c=q.rear-q.front +1;
		return c;
	}
	else if(q.front!=0 && q.rear<q.front)
	{
		c=q.front-q.rear+1;
		return c;
	}
	
		
		
	
}
void queue_print(queue* q)
{
	if(queue_is_empty(Q))
	return;
	int i=0;
	int index;
	int count=queue_size(q) ;
	while(i<count)
	{
	index=(q->front+i)%size;
	printf("%d ",q->arr[index]);
	i++;
	}
}

}
	
int main()
{
	queue* q;	
	s=queue_new();
	queue_print(s);

	
}	
		


































	
	
