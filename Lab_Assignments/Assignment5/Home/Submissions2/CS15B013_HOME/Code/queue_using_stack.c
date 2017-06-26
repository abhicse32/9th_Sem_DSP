#include<stdio.h>
#include"stack.h"
#include"queue_using_stack.h"
#include<stdlib.h>

queue* queue_new()
{
 stack * new=stack_new();
 queue * newq=(queue *)malloc(sizeof(queue));
 newq->front=new->top;
 newq->rear=new->top;
 return newq;
}

void enqueue(queue* que, int data)
{stack * sf=stack_new();
 stack * sr=stack_new();
 stack * temp=stack_new();
 
 if(queue_is_empty(que)) 
  {
   stack_push(sf,data);
   stack_push(sr,data);
   que->front=sf->top;
   que->rear=sr->top;
  }
 else
 {
  sf->top=que->front;
  stack_push(sf,data);
  que->front=sf->top;
 
  sr->top=que->rear;
  
  while(!stack_is_empty(sr))
       stack_push(temp,stack_pop(sr));
       
       stack_push(temp,data);
       
   while(!stack_is_empty(temp))
       stack_push(sr,stack_pop(temp));
        
  que->rear=sr->top;   
 } 

}

int dequeue(queue* que)
{
 stack * sf=stack_new();
 stack * sr=stack_new();
 stack * temp=stack_new();
 sr->top=que->rear;
 stack_pop(sr);
 que->rear=sr->top;

 sf->top=que->front;
 
  while(!stack_is_empty(sf))
       stack_push(temp,stack_pop(sf));
       
       int a=stack_pop(temp);
       
   while(!stack_is_empty(temp))
       stack_push(sf,stack_pop(temp));
   
 que->front=sf->top;  
 
 return a;
}

bool queue_is_empty(queue* que)
{
 stack * new=stack_new();
 new->top=que->front;
 return stack_is_empty(new);
}

int queue_size(queue* que)
{
 stack * new=stack_new();
 new->top=que->front;
 return stack_size(new);
}

void queue_print(queue* que)
{
 stack * sf=stack_new();
 stack * sr=stack_new(); 
 
 sr->top=que->rear;
 
 stack_print(sr);
}






