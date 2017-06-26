#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()
{
 stack * newstack=(stack *)malloc(sizeof(stack));
 newstack->arr=(int *)malloc(sizeof(int)*size);
 newstack->top=0;
 return newstack;
}

void stack_push(stack* stk, int data)
{
 int * end=stk->arr;
 int i=stk->top;
 while(i>0)
  {i--;end++;}
 *end=data; 
 stk->top=stk->top+1; 
}

int stack_pop(stack* stk)
{int * end=stk->arr;
 int index=stk->top;
 while(index>1)
 {end++;index--;}
 stk->top=stk->top-1;
 return *end;
}

bool stack_is_empty(stack* stk)
{
 if(stk->top==0)
   return true;
 else
   return false;  
}

bool stack_is_full(stack* stk)
{
 if(stk->top==1000)
   return true;
 else
   return false;
}

int stack_size(stack* stk)
{
 return stk->top;
}

void stack_print(stack* stk)
{
 int * end=stk->arr;
 int index=stk->top-1;
 while(index>=0)
 {
  printf("%d ",end[index]);
  index--;
 }

}













