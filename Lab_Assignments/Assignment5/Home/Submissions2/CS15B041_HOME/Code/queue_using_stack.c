#include<stdio.h>
#include"ORIList.c"
#include<stdlib>


queue* stack_new()
{
	queue* q;
	q=queue_new();
	return q;
}


void stack_push(queue* q, int d)
{
	
	enqueue(q,d);
	
	
}

int stack_pop(queue* q)

	if(queue_size==0)
	return -1;
	else
	{
	int temp;
	int i=0;
	queue* q1;
	q1=queue_new();
	
	while(i < queue_size(q)-1)
	{
		temp=dequeue(q);
		enqueue(q,temp);	
		i++;
	}
	temp=dequeue(q);
	return temp;
	}
}

bool stack_is_empty(queue* q)
{
	if(queue_is_empty(q))
	return 1;
	else
	return 0;
	
	
}

int stack_size(queue* q)
{
	
	return queue_size(q);
}



void stack_print(queue *q)
{
	queue_print(q);

	
	int a[queue_size(q);];
	int i=0;
	while(!queue_is_empty)
	{
		a[i]=dequeue(q);
		i++;
	}
	i=0;
	while(i<queue_size(q);)
	{
		enqueue(q,a[i]);
		i++;
	}
	i=n-1;
	while(i>=0)
	{
		printf("%d",a[i]);
		i--;
	}
}
	
































