#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include "List.h"
#define size 1000

queue* queue_new()
{
 queue* line = (queue *)malloc(sizeof(queue));
 line->arr = (int* )malloc(sizeof(int) * size);
 line->front = -1;
 line->rear  = -1;
}

void enqueue(queue* line, int n)
{
 if(queue_is_empty(line) == 1)
  {
   line->front = 0;
   line->rear  = 0;
   (line->arr)[0] = n;
  }
 else
  {
   (line->arr)[++(line->rear)] = n;
  }
}

int dequeue(queue* line)
 {
  if(queue_is_empty(line) == 1)
   {
    return INT_MIN;
   }
  else
   {
    int p;
    p = (line->arr)[line->front];
    line->front = line->front + 1;
    return p;
   }
   
 }

bool queue_is_full(queue* line)
{
  if((line->rear - line->front) >= 1000)
   {
    return 1;
   }
  else
   {
    return 0;
   }
}

bool queue_is_empty(queue* line)
{
 if(line->front == -1)
  {
   return 1;
  }
 else
  {
   return 0;
  }
}

int queue_size(queue* line)
{
 if(line->front == -1)
  {
   return 0;
  }
 else
  {
   return ((line->rear)-(line->front) +1)%size ;
  }
}

void queue_print(queue* line)
{
 if(line->front != -1)
  {
   int i;
   for(i = (line->front);i <= (line->rear);i++)
   {
    if(i == size)
    {
     i = 0;
    }
    printf("%d ",(line->arr)[i]);
   }
  }
  else
  {
   return;
  }
}
   	 



























