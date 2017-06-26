#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()
{  stack* st = (stack*)malloc(sizeof(stack));
   st->top=-1;
   int* arr= (int*)malloc(size*sizeof(int));
   if(arr==NULL)
   return NULL;
   st->arr=arr;
   return st;
}

void stack_push(stack* st,int num)
{  if(st->top==size-1)
    return;
    
   st->top=st->top+1;
   st->arr[st->top]=num;
}

int stack_pop(stack* st)
{  st->top=st->top-1;
    return st->arr[st->top+1];
}

bool stack_is_empty(stack* st)
{ if(st->top==-1)
   return true;
  return false;
}

bool stack_is_full(stack* st)
{ if(st->top==size-1)
   return true;
  return false;
}

int stack_size(stack* st)
{ return st->top+1;
}

void stack_print(stack* st)
{ int i;
  for(i=st->top; i>=0;i--)
  { printf("%d ",st->arr[i]);
  }
 // printf("\n");
}
   
   
