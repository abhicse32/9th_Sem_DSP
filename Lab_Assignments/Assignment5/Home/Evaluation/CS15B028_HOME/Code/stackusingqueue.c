#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
queue* stack_new()
{
   queue*pq=(queue*)malloc(sizeof(queue));
   pq->front=llist_new();
   pq->rear=llist_new();
   return pq;
}
void stack_push(queue*p, int x)
{
   llist_prepend(p->front);
}
int stack_pop(queue*p)
{
   int x=((p->front)->head)->data;
   llist_remove_first(p->front);
   return x;
}
bool stack_is_empty(queue*p)
{
   return queue_is_empty(p);
}
int stack_size(queue*p)
{
   return queue_size(p);
}
void stack_print(queue*p)
{
   queue_print(p);
}
