#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
queue* queue_new()
{
    queue *st = (queue*) malloc( sizeof(queue));
    st->rear = -1;
    st->front = 0;
    st->arr = (int*) malloc(1000 * sizeof(int));
    return st;
}
void enqueue(queue* que,int data)
{
    if((que->rear) < 999)
    {
      (que->rear)++;
      que->arr[(que->rear)] = data;
    }
}
int dequeue(queue* que)
{
           int x = que->arr[que->front];
            (que->front)++;
           return x;
}
bool queue_is_empty(queue* que)
{
     if (que->rear == -1)
        return 1;
    return 0;
}
bool queue_is_full(queue* que)
{
    if((que->rear) >= 1000)
    return 1;
    return 0;
}
int queue_size(queue* que)
{
   return (1+(que->rear)-(que->front));
}
void queue_print(queue* que)
{
  if(queue_is_empty(que) == 0)
  {
    int i;
    for(i=que->front;i<=que->rear;i++)
    {
        printf("%d ",que->arr[i]);
    }
  }
}
