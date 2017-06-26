//queue_a.c by Raghavan S CS15B034 Home Assignment 5
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
// create a new queue
queue* queue_new()
{
  queue *q = (queue*)malloc(sizeof(queue));
  q->front=-1;
  q->rear=-1;
  q->arr=(int *)malloc(sizeof(int)*size);
  return q;
}

// add an element in the queue
void enqueue(queue *q, int data)
{
  if(q->front==q->rear+1||(q->rear==size-1&&q->front==0))
  {
    printf("Overflow!!");
    return;
  }
  if(q->front==-1)
  q->front=q->rear=0;
  else
  q->rear++;
  if(q->rear==size)
  q->rear=0;
  q->arr[q->rear]=data;
}

// remove the first element from the queue
int dequeue(queue *q)
{
  if(q->front==-1)
  {
    printf("Underflow!!");
    return INT_MIN;
  }
  int n;
  n=q->arr[q->front];
  if(q->front==q->rear)
  q->front=q->rear=-1;
  else
  q->front++;
  if(q->front==size)
  q->front=0;
  return n;
}

// Check if queue is empty
bool queue_is_empty(queue *q)
{
  return (q->front==-1);
}

// bool check if queue is full
bool queue_is_full(queue *q)
{
  return (q->front==q->rear+1||(q->rear==size-1&&q->front==0));
}

// find the size of the queue
int queue_size(queue *q)
{
  int count=0;
  if(q->front==-1)
  return 0;
  else
  {
    int i=q->front;
    if(q->front>q->rear)
    {
      while(i<size)
      {
        count++;
        i++;
      }
      i=0;
      while(i<=q->rear)
      {
        count++;
        i++;
      }
    }
    else
    {
      while(i<=q->rear)
      {
        count++;
        i++;
      }
    }
  }
  return count;
}

void queue_print(queue *q)
// print queue element
{
  if(q->front==-1)
  return;
  int i=q->front;
  if(q->front>q->rear)
  {
    while(i<size)
    {
      printf("%d ",q->arr[i]);
      i++;
    }
    i=0;
    while(i<=q->rear)
    {
      printf("%d ",q->arr[i]);
      i++;
    }
  }
  else
  {
    while(i<=q->rear)
    {
      printf("%d ",q->arr[i]);
      i++;
    }
  }
}
