//stack_a.c by Raghavan S CS15B034 Home Assignment 5
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
// create a new stack
stack* stack_new()
{
  stack *q = (stack*)malloc(sizeof(stack));
  q->top=-1;
  q->arr=(int *)malloc(sizeof(int)*size);
  return q;
}

// push an element on the stack
void stack_push(stack *q, int data)
{
  if(q->top==size-1)
  {
    printf("Overflow!!");
    return;
  }
  q->top++;
  q->arr[q->top]=data;
}

// pop the top element from the stack
int stack_pop(stack *q)
{
  if(q->top==-1)
  {
    printf("Underflow!!");
    return INT_MIN;
  }
  int n;
  n=q->arr[q->top];
  q->top--;
  return n;
}

// Check if stack is empty
bool stack_is_empty(stack *q)
{
  return (q->top==-1);
}

// bool check if stack is full
bool stack_is_full(stack *q)
{
  return (q->top==size-1);
}

// find the size of the stack
int stack_size(stack *q)
{
  return (q->top+1);
}

// print stack element
void stack_print(stack *q)
{
  int i=q->top;
  while(i>=0)
    {
      printf("%d ",q->arr[i]);
      i--;
    }
}
