#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
{
 queue * new=(queue *)malloc(sizeof(queue));
 new->front=llist_new();
 new->rear=llist_new();
 return new;
}

void enqueue(queue * que, int data)
{
 llist_prepend(que->front,data);
 llist_append(que->rear,data);
}

int dequeue(queue * que)
{
 int popped=llist_get(que->rear,0);
 llist_remove_first(que->rear);
 llist_remove_last(que->front);
 return popped;
}

bool queue_is_empty(queue * que)
{
 if(que->front->head==NULL)
   return true;
 else
   return false;  
}

int queue_size(queue * que)
{
 int size=llist_size(que->front);
 return size;
}

void queue_print(queue * que)
{queue * new=queue_new();
 int a;
 llist_print(que->rear);
}









