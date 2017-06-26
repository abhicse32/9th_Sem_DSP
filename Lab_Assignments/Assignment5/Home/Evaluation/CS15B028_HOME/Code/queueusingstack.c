#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
stack* queue_new()
{
   stack *p=(stack*)malloc(sizeof(stack));
   p->top=llist_new();
   return p;
}
void enqueue(stack*p, int x)
{
   stack*t=stack_new();
   while(stack_is_empty(p)==0)
   {
      stack_push(t,stack_pop(p));
   }
   stack_push(p,x);
   while(stack_is_empty(t)==0)
   {
      stack_push(p,stack_pop(t));
   }   
}
int dequeue(stack*p)
{
   int x=((p->top)->head)->data;
   llist_remove_first(p->top);
   return x;
}     
bool queue_is_empty(stack*p)
{
   return stack_is_empty(p);
}
int queue_size(stack*p)
{
   return stack_size(p);
}
void queue_print(stack*p)
{
   stack_print(p);
}
