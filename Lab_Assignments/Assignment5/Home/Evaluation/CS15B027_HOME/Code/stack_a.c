#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define size 1000
stack* stack_new()
{
    stack *p = (stack*) malloc( sizeof(stack));
    p->top = -1;
    p->arr = (int*) malloc(1000 * sizeof(int));
    return p;
}
void stack_push(stack* stk, int data)
{
    if((stk->top) < 999)
    {
      (stk->top)++;
      stk->arr[(stk->top)] = data;
    }
}
int stack_pop(stack* stk)
{
       if(stk->top >= 0){
        int x = stk->arr[(stk->top)];
       (stk->top)--;
        return x;
    }
}
bool stack_is_empty(stack* stk)
{
     if (stk->top == -1)
        return 1;
    return 0;
}
bool stack_is_full(stack* stk)
{
    if((stk->top) >= 1000)
    return 1;
    return 0;
}
int stack_size(stack* stk)
{
   if(stk->top >=0)
   return (stk->top)+1;
}
void stack_print(stack* stk)
{
  if(stack_is_empty(stk) == 0)
  {
    int i;
    for(i=stk->top;i>=0;i--)
    {
        printf("%d ",stk->arr[i]);
    }
  }
}
