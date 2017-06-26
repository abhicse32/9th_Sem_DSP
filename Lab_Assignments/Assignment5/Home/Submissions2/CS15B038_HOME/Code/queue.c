#include "List.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()
{
     queue* Q = (queue*) malloc(sizeof(queue));
     Q->front = llist_new();
     Q->rear = llist_new();
     return Q;
}

void enqueue(queue* Q, int a)
{
     llist_append(Q->front, a);
     
     if(Q->rear->head == NULL)
     {
          Q->rear->head = Q->front->head;
          return;
     }
     
     Q->rear->head = Q->rear->head->next;     
}

int dequeue(queue* Q)
{
     int a = Q->front->head->data;
     llist_remove_first(Q->front);
     if(Q->front->head == NULL) Q->rear->head == NULL;
     return a;
}

bool queue_is_empty(queue* Q)
{
     if(Q->rear->head == NULL && Q->front->head == NULL) return true;
     else return false;
}

int queue_size(queue* Q)
{
     return llist_size(Q->front);
}

void queue_print(queue* Q)
{
     llist_print(Q->front);
}
