#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new()
{
 queue * new=(queue *)malloc(sizeof(queue));
 new->arr=(int *)malloc(sizeof(int)*size);
 new->front=0;
 new->rear=0;
}

void enqueue(queue * que,int data)
{
 int end=que->rear;
 int * array=que->arr;
 array[end]=data;
 que->rear=que->rear+1;
}

int dequeue(queue * que)
{int * array=que->arr;
 int popped=array[que->front];
 que->front=que->front+1;
 return popped;
}

bool queue_is_empty(queue * que)
{
 if(que->front==que->rear-1)
   return true;
 else
   return false;
}

bool queue_is_full(queue * que)
{
 if(que->rear==1000)
   return true;
 else
   return false;  
}

int queue_size(queue * que)
{int a=que->rear;int b=que->front;
 
 return a-b;
}

void queue_print(queue * que)
{
 int a=que->front;
 int b=que->rear;
 int * array=que->arr;
 
 while((b-a)>=1)
 {
  printf("%d ",array[a]);
  a++;
 }
 
}













