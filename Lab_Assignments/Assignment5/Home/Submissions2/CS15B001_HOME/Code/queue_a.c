/*
Array based implementation of queue

Ameet S Deshpande
CS15B001
*/


//Take care of the new line printed after print function



#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define size 1000
//#define size 6



// create a new queue
queue* queue_new()
{
	queue *temp;
	temp = (queue*) malloc(sizeof(queue));

	temp->arr = (int*) malloc(sizeof(int)*size);
	temp->front = -1;
	temp->rear = 0;
	return temp;
}



// add an element in the queue
void enqueue(queue *a, int data)
{
	if(a->front == -1)
	{
		a->front = 0;
		a->rear = 0;
		(a->arr)[a->rear] = data;
	}
	else
	{
		int next;
		if(a->rear == size-1)
		{
			next = 0;
		}
		else
		{
			next = a->rear + 1;
		}

		if(next == a->front)
		{
			return;	//This means that the array/queue is full
		}

		else
		{
			a->rear = next;
			(a->arr)[a->rear] = data;
			return;	//Else increment the array rear pointer and add the element to the end
		}

	}
}




// remove the first element from the queue
int dequeue(queue *a)
{	
	int value;	//Stores the value of the deleted element

	if(a->front == -1)
	{
		return INT_MIN;
	}

	if(a->front == a->rear)
	{	
		value = (a->arr)[a->front];
		a->front = -1;
		a->rear = 0;
		return value;
	}

	else
	{
		int next;

		if(a->front == size-1)
		{
			next = 0;
		}
		else
		{
			next = a->front + 1;
		}

		value = (a->arr)[a->front];
		a->front = next;
		return value;

	}
}




// Check if queue is empty
bool queue_is_empty(queue *a)
{
	if(a->front == -1)
	{
		return 1;
	}

	return 0;
}



// bool check if queue is full
bool queue_is_full(queue *a)
{	int next;

	if(a->rear == size-1)
	{
		next = 0;
	}
	else
	{
		next = a->rear + 1;
	}

	if(next == a->front)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



// find the size of the queue
int queue_size(queue *a)
{
	if(a->rear >= a->front)
	{
		return (a->rear) - a->front+1;
	}
	else
	{
		return a->rear - a->front + size +1;
	}
}




// print queue element
void queue_print(queue *a)
{
	int i;
	if(a->front == -1)
	{
		return;
	}

	if(a->rear >= a->front)
	{
		for(i= a->front;i<=a->rear;++i)
		{
			printf("%d ",(a->arr)[i]);
		}
	}

	else
	{
		for(i=a->front; i < size; ++i)
		{
			printf("%d ",(a->arr)[i]);
		}

		for(i = 0; i <= a->rear; ++i)
		{
			printf("%d ",(a->arr)[i]);
		}
	}

}