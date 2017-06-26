#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// create a new queue
stack* queue_new()
{
  stack *q = (stack*)malloc(sizeof(stack));
  q->top=llist_new();
  return q;
}

// add an element to the queue
void enqueue(stack *q, int data)
{
  stack *r=stack_new();
  while(q->top->head!=NULL)
  {
    stack_push(r,stack_pop(q));
  }
  stack_push(r,data);
  while(r->top->head!=NULL)
  {
    stack_push(q,stack_pop(r));
  }
}

// remove the front element from the queue
int dequeue(stack *q)
{
  return stack_pop(q);
}

// Check if queue is empty
bool queue_is_empty(stack *q)
{
  return (q->top->head==NULL);
}

// find the size of the queue
int queue_size(stack* q)
{
  return (llist_size(q->top));
}

// print queue element
void queue_print(stack *q)
{
  llist_print(q->top);
}
