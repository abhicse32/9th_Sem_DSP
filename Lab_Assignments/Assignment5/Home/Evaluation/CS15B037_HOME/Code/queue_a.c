/*
* 18th September 2016
* Written by Teratipally Srikar,CS15B037
* This program is used for
* manipulating queue data structure by 
* using array
*/

#include "queue_a.h"    /*Including the required header files*/
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new()  /*This function creates a new queue*/
{
    queue* new = (queue*) malloc(sizeof(queue));
    new->arr = (int*) malloc((sizeof(int))*(size+1));
    new->front = 0;
    new->rear = -1;
}

int queue_size(queue* que)  /*This function returns the size of the queue*/
{
	return (((que->rear)-(que->front)+size+1)%size);
}

bool queue_is_empty(queue* que) /*This function returns whether the queue is empty*/
{
    if(queue_size(que)==0) return true;
    else return false;
}

bool queue_is_full(queue* que)  /*This function returns if the array is full*/
{
    if(queue_size(que)==(size)) return true;    /*since if the top is pointed to last index it is full*/
    else return false;
}

void enqueue(queue* que, int data)  /*This function adds a data into the queue*/
{
    if(queue_is_full(que)) return;  /*If the function is full then nothing can be added*/
    que->rear = (que->rear+1)%size;
    que->arr[(que->rear)] = data;
}

int dequeue(queue* que) /*This function removes the first inserted element and returns its value*/
{
    if(queue_size(que)==0) return -1;   /*If there are no elements then, nothing to remove*/
    int data = que->arr[(que->front)];
	que->front = ((que->front)+1+size)%size;
	return data;
}

void queue_print(queue* que)    /*This function prints the elements in the array*/
{
	int i; /*Counter*/
	for(i=que->front;i!=que->rear;)
	{
		printf("%d ",que->arr[i]);
		i = (i+1)%size;
	}

    printf("%d ",que->arr[i]);  /*Printing the last element*/
}

