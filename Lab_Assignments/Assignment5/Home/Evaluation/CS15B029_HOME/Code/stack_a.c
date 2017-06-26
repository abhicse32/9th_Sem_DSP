#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define size 1000
stack* stack_new()
{
    stack *st = (stack*) malloc( sizeof(stack));
    st->top = -1;
    st->arr = (int*) malloc(1000 * sizeof(int));
    return st;
}
void stack_push(stack* avi, int data)
{
    if((avi->top) <= 998)
    {
      (avi->top)++;
      avi->arr[(avi->top)] = data;
    }
}
int stack_pop(stack* avi)
{
       if(avi->top > -1){
        int x = avi->arr[(avi->top)];
       (avi->top)--;
        return x;
    }
}
bool stack_is_empty(stack* avi)
{
     if (avi->top == -1)
        return 1;
    return 0;
}
bool stack_is_full(stack* avi)
{
    if((avi->top) > 999)
    return 1;
    return 0;
}
int stack_size(stack* avi)
{
   if(avi->top > -1)
   return (avi->top)+1;
}
void stack_print(stack* avi)
{
  if(stack_is_empty(avi) == 0)
  {
    int i;
    for(i=avi->top;i>-1;i--)
    {
        printf("%d ",avi->arr[i]);
    }
  }
}
