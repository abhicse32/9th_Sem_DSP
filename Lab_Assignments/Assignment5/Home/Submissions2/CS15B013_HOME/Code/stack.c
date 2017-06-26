#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>


stack* stack_new()
{
 stack * new=(stack *)malloc(sizeof(stack));
 new->top=llist_new();
 return new;
}

void stack_push(stack* argstak, int data)
{
 llist_prepend(argstak->top,data);
}

int stack_pop(stack* argstk)
{
 int popped=llist_get(argstk->top,0);
 llist_remove_first( argstk->top);
 return popped;
}

bool stack_is_empty(stack* argstk)
{
 if(argstk->top->head==NULL)
   return true;
 else
   return false;  
}


int stack_size(stack* argstk)
{
 int size=llist_size(argstk->top);
 return size;
}

void stack_print(stack* argstk)
{int a;
 stack * new=stack_new();
 while(!stack_is_empty(argstk))
 {
  a=stack_pop(argstk);
  stack_push(new,a);
  printf("%d ",a);
 }
 while(!stack_is_empty(new))
  stack_push(argstk,stack_pop(new));
}


















