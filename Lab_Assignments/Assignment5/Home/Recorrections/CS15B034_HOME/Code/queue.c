//queue.c by Raghavan S CS15B034 Home Assignment 5
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
// create a new queue
queue* queue_new()
{
  queue *q = (queue*)malloc(sizeof(queue));
  q->front=llist_new();
  q->rear=llist_new();
  return q;
}

// add an element to the queue
void enqueue(queue *q, int data)
{
   llist_append(q->front,data);
   if(llist_size(q->front)==1)
   q->rear->head=q->front->head;
   else
   q->rear->head=q->rear->head->next;
}

// remove the front element from the queue
int dequeue(queue *q)
{
  int n=llist_size(q->front);
  if(n==0)
  return INT_MIN;
  else if(n==1)
  {
    q->rear->head=NULL;
    n=q->front->head->data;
    llist_remove_first(q->front);
    return n;
  }
  else
  {
    Node *p=q->front->head;
    n=p->data;
    llist_remove_first(q->front);
    return n;
  }
}

// Check if queue is empty
bool queue_is_empty(queue *q)
{
  return (q->front->head==NULL);
}

// find the size of the queue
int queue_size(queue* q)
{
  return (llist_size(q->front));
}

// print queue element
void queue_print(queue *q)
{
  llist_print(q->front);
}
