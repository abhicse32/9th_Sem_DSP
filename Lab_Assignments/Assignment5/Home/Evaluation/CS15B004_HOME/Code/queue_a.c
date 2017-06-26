#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define size 1000


// create a new queue
queue* queue_new()
{
	queue* que = (queue*) malloc (sizeof(queue));
	que->arr = (int*) malloc (size * sizeof(int));
	que->front = -1;
	que->rear  = -1;

	return que;
}



// add an element in the queue
void enqueue(queue* que, int data)
{
	if(queue_is_empty(que))
	{
		que -> front = 0;
		que -> rear = 0;
		que -> arr[0] = data;
		return;
	}

	if( queue_is_full(que) )
		return;
	else
	{
		que -> rear = ( que -> rear + 1) % size;
		que -> arr[que->rear]= data;
	}
}


// remove the first element from the queue
int dequeue(queue* que)
{
	if(! queue_is_empty(que))
	{
		int val = que -> arr[que -> front];
		if(que -> front == que -> rear)
		{
			que -> front = que -> rear = -1;
			return val;
		}

		que -> front = ( que -> front + 1) % size;
		return val;
	}

	return -1;
}

// Check if queue is empty
bool queue_is_empty(queue* que)
{
	if(que -> front == -1)
		return true;
	else
		return false;
}

// bool check if queue is full
bool queue_is_full(queue* que)
{
	if( (que -> rear + 1)%size == que-> front )
		return true;
	else 
		return false;
}

// find the size of the queue
int queue_size(queue* que)
{
	if(queue_is_empty(que))
		return 0;

	int val = (que -> rear - que-> front) % size +1;
	return val;
}

// print queue element
void queue_print(queue* que)
{
	if(queue_is_empty(que))
		return;

	int cur = que -> front;
	int i = 1;
	int n = queue_size(que);

	while( i<= n)
	{
		printf("%d ", que -> arr[cur]);
		cur++;
		i++;
	}
}




