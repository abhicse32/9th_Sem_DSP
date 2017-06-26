//stack.c by Raghavan S CS15B034 Home Assignment 5
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
stack* stack_new()
{
  stack *q = (stack*)malloc(sizeof(stack));
  q->top=llist_new();
  return q;
}

// push an element on the stack
void stack_push(stack *q, int data)
{
  llist_prepend(q->top,data);
}

// pop the top element from the stack
int stack_pop(stack *q)
{
  int n=llist_size(q->top);
  if(n==0)
  return INT_MIN;
  else
  {
    Node *p=q->top->head;
    n=p->data;
    llist_remove_first(q->top);
    return n;
  }
}

// Check if stack is empty
bool stack_is_empty(stack *q)
{
  return (q->top->head==NULL);
}

// find the size of the stack
int stack_size(stack *q)
{
  return (llist_size(q->top));
}

// print stack element
void stack_print(stack *q)
{
  llist_print(q->top);
}
