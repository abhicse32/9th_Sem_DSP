/*
  BASIC QUEUE OPERATIONS 
  USING LINKED LISTS
*/
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

queue* queue_new()                               //Create a new queue
{
    queue *new;
    new = (queue *)malloc(sizeof(queue));
    new->front = llist_new();
    new->rear = llist_new();
    (new->front)->head = NULL;
    (new->rear)->head = NULL;
    return new;
}

void enqueue(queue* Q, int data)                 //Add an element to the queue
{
    Node *new = node_new(data);
    if((Q->front)->head == NULL)
    {
        (Q->front)->head = new;
        (Q->rear)->head = new;
    }
    else
    {
        ((Q->rear)->head)->next = new;
        (Q->rear)->head = new;
    }
}

int dequeue(queue* Q)                            //Remove the front element from the queue
{
    if((Q->front)->head == NULL)
        return INT_MIN;
    int first = ((Q->front)->head)->data;
    (Q->front)->head = ((Q->front)->head)->next;
    return first;
}

bool queue_is_empty(queue* Q)                    //Check if queue is empty
{
    if((Q->front)->head == NULL)
        return true;
    return false;
}

int queue_size(queue* Q)                         //Find the size of the queue
{
    return llist_size(Q->front);
}

void queue_print(queue* Q)                       //Print queue elements
{
    llist_print(Q->front);
}
