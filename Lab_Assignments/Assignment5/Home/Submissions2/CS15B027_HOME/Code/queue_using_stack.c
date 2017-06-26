#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>
stack* queue_new()
{
  stack* out=(stack *)malloc(sizeof(stack));
  out = stack_new();
  return out;
}
void enqueue(stack* stk, int data)
{
  stack* p=(stack *)malloc(sizeof(stack));
  p = stack_new();
    while(stack_is_empty(stk) == 0)
    {
      int x = stack_pop(stk);
         stack_push(p,x);
    }
      stack_push(p,data);
    while(stack_is_empty(p) == 0)
    {
      int y = stack_pop(p);
         stack_push(stk,y);
    }
}
int dequeue(stack* stk)
{
  stack_pop(stk);
}
bool queue_is_empty(stack* stk)
{
  return stack_is_empty(stk);
}
int queue_size(stack* stk)
{
  return stack_size(stk);
}
void queue_print(stack* stk)
{
   stack_print(stk);
}
