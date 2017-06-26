#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 1000

queue* queue_new()
{
  queue*pq=(queue*)malloc(sizeof(queue));
  pq->arr=(int*)malloc(1000*sizeof(int));
  pq->rear=-1;
  pq->front=0;
  return pq;
}
void enqueue(queue*pq, int x)
{
  pq->rear++;
  if(pq->rear==1000)
  pq->rear=0;
  pq->arr[pq->rear]=x;
}
int dequeue(queue*pq)
{
  int x=pq->arr[pq->front];
  
  pq->front++;
  return x;
}
bool queue_is_empty(queue*pq)
{
  if((pq->rear)==(pq->front)-1)
  return 1;
  else return 0;
}
bool queue_is_full(queue*pq)
{
  if(pq->front==(pq->rear)-1)
  return true;
  else return false;
}
int queue_size(queue*pq)
{
  if(pq->rear>=pq->front)
  return (pq->rear-pq->front+1);
}
void queue_print(queue*pq)
{
  int i;
  /*if(pq->front>pq->rear)
  {
    for(i=pq->front;i<1000;i++)
    {
      printf("%d ",pq->arr[i]);
    }
    for(i=0;i<=pq->rear;i++)
    {
      printf("%d ",pq->arr[i]);
    }
  }
  else*/     
  for(i=pq->front;i<=pq->rear;i++)
  {
     printf("%d ",pq->arr[i]);
  }
}       
  
  
