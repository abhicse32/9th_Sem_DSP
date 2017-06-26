#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_using_queue.h"

// create a new stack
queue* stack_new()
{
  queue *q = (queue*)malloc(sizeof(queue));
  q->front=llist_new();
  q->rear=llist_new();
  return q;
}

// push an element on the stack
void stack_push(queue *q, int data)
{
  int i=0,s=queue_size(q);
  enqueue(q,data);
  while(i<s)
  {
    enqueue(q,dequeue(q));
    i++;
  }
}

// pop the top element from the stack
int stack_pop(queue *q)
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

// Check if stack is empty
bool stack_is_empty(queue *q)
{
  return (q->front->head==NULL);
}

// find the size of the stack
int stack_size(queue *q)
{
  return (llist_size(q->front));
}

// print stack element
void stack_print(queue *q)
{
  llist_print(q->front);
}
