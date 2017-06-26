#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
queue* queue_new()
{
    queue *p = (queue*) malloc( sizeof(queue));
    p->front = -1;
    p->rear = 0;
    p->arr = (int*) malloc(1000 * sizeof(int));
    return p;
}
void enqueue(queue* q,int data)
{
    if((q->front) < 999)
    {
      (q->front)++;
      q->arr[(q->front)] = data;
    }
}
int dequeue(queue* q)
{
           int x = q->arr[q->rear];
            (q->rear)++;
           return x;
}
bool queue_is_empty(queue* q)
{
     if (q->front == -1)
        return 1;
    return 0;
}
bool queue_is_full(queue* q)
{
    if((q->front) >= 1000)
    return 1;
    return 0;
}
int queue_size(queue* q)
{
   return (1+(q->front)-(q->rear));
}
void queue_print(queue* q)
{
  if(queue_is_empty(q) == 0)
  {
    int i;
    for(i=q->rear;i<=q->front;i++)
    {
        printf("%d ",q->arr[i]);
    }
  }
}
