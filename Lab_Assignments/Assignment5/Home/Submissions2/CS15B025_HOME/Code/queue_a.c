/*
  BASIC QUEUE OPERATIONS 
  USING AN ARRAY
*/
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 1000

queue* queue_new()                               //Create a new queue
{
    queue *new;
    new = (queue *)malloc(sizeof(queue));
    new->arr = (int *)malloc(size * sizeof(int));
    new->front = -1;
    new->rear = -1;
    return new;
}

void enqueue(queue* Q, int data)                 //Add an element in the queue
{
    if((Q->front) < 0)
    {
        (Q->front)++;
        (Q->rear)++;
        Q->arr[0] = data;
    }
    else if(Q->rear < (size-1))
    {
        if(Q->front == (Q->rear)+1)
            return;
        Q->arr[++(Q->rear)] = data;
    }
    else
    {
        if(Q->front != 0)
        {
            Q->rear = 0;
            Q->arr[Q->rear] = data;
        }
    }
}

int dequeue(queue* Q)                            //Remove the first element from the queue
{
    if((Q->front) < 0)
        return -1;
    (Q->front)++;
    return(Q->arr[(Q->front) - 1]);
}

bool queue_is_empty(queue* Q)                    //Check if queue is empty
{
    if(queue_size(Q) == 0)
        return true;
    return false;
}

bool queue_is_full(queue* Q)                     //Check if queue is full
{
    if(queue_size(Q) == size)
        return true;
    return false;
}

int queue_size(queue* Q)                         //Find the size of the queue
{
    return (((Q->rear)-(Q->front) + size +1) % size);
}

void queue_print(queue* Q)                       //Print queue elements
{
    for(int i = (Q->front);i <= (Q->rear);i++)
    {
        printf("%d ", *((Q->arr) + i));
    }
}
