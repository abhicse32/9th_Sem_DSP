#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include<limits.h>

queue* queue_new()
{
 queue* new = (queue *)malloc(sizeof(queue));
 new->front = llist_new();
 new->rear  = llist_new();
 return new;
}

void enqueue(queue* line, int n)
{
 if(queue_is_empty(line) == 1)
  {
   Node* new = (Node *)malloc(sizeof(Node));
   new->data = n;
   line->front->head = new;
   line->rear->head  = new;
   }
  else
  {
   Node *new = (Node *)malloc(sizeof(Node));
   new->data = n;
   line->rear->head->next = new;
   line->rear->head = line->rear->head->next;
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
   Node* new = line->front->head;
   line->front->head = line->front->head->next;
   return new->data;
  }
}

bool queue_is_empty(queue* line)
{
 if(line->front->head == NULL && line->rear->head == NULL)
  {
   return 1;
  }
 return 0;
}

int queue_size(queue* line)
{
 if(queue_is_empty(line) == 1)
 {
  return 0;
 }
 Node* new = line->front->head;
 int count = 0;
 while(new != line->rear->head)
 {
  new = new->next; 
  count++;
 }
 return (count+1);
}

void queue_print(queue* line)
{
 if(queue_is_empty(line) == 1)
  {
   return;
  }
 Node* new = line->front->head;
 printf("%d ",new->data);
 while(new != line->rear->head)
 {
    new = new->next;
    printf("%d ",new->data);
 }   
}
 
 





















 

