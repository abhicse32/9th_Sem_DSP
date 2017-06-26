#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

// create a new queue
queue* queue_new()
{
	queue* q = (queue*) malloc(sizeof(queue));
	q -> arr = (int *) malloc(size * sizeof(int));
	q -> front = -1;
	q -> rear  = -1;
	return q;
}

// Check if queue is empty
bool queue_is_empty(queue* q)
{
	if(q -> rear == -1)	return 1;
	else			return 0;

}

// bool check if queue is full
bool queue_is_full(queue* q)
{
	if(q -> rear == size - 1) return 1;
	else			 return 0;
}

// add an element in the queue
void enqueue(queue* q, int num)
{
	if (queue_is_empty(q))
    	{
		q -> front = q -> front + 1;
		q -> arr[q -> front] = num;
		q -> rear = q -> rear + 1;
		q -> arr[q -> rear] = num;
		
	}

    	else
    	{
    		if(!queue_is_full(q))
		q -> rear = q -> rear + 1;
		q -> arr[q -> rear] = num;
	}  
}

// remove the first element from the queue
int dequeue(queue* q)
{
	if(queue_is_empty(q));
	else
	{
		int pop = q -> arr[q -> front];
		q -> front = q -> front + 1;
		return pop;
	}
}

// find the size of the queue
int queue_size(queue* q)
{
	int l1 = q -> rear;
	int l2 = q -> front;
	int l = l1 - l2 + 1;
}

// print queue element
void queue_print(queue* q)
{
	int i;
	for(i = q -> front; i <= q -> rear; i++)	printf("%d ", q -> arr[i]);
}
