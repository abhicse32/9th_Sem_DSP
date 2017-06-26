#include<stdio.h>
#include"stack_using_queue.h"
#include"queue.h"
#include<stdlib.h>

stack* stack_new()
{
 queue * new=queue_new();
 stack * news=(stack *)malloc(sizeof(stack));
 news->top=new->front;
 return news;
}

void stack_push(stack* stk, int data)
{
 queue * new=queue_new();
 new->front=stk->top;
 enqueue(new,data);
 stk->top=new->front;
}

int stack_pop(stack* stk)
{
 queue * new1=queue_new(); 
 queue * new2=queue_new();
 
 new1->rear=stk->top;
 
/* int size=queue_size(new1);
 int i=1;
 for(;i<size;i++)
  enqueue(new2,dequeue(new1));
  
 stk->top=new2->front;*/
 return dequeue(new1);
}

bool stack_is_empty(stack* stk)
{
 queue * new=queue_new();
 new->front=stk->top;
 return queue_is_empty(new);
}

int stack_size(stack* stk)
{
 queue * new=queue_new();
 new->front=stk->top;
 return queue_size(new);
}

void stack_print(stack* stk)
{
 queue * new=queue_new();
 new->rear=stk->top;
 queue_print(new);
}












