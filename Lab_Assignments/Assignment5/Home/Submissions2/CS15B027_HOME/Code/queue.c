#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "List.h"
queue* queue_new()
{
  queue* p=(queue *)malloc(sizeof(queue));
  p->front=llist_new();
  p->rear=llist_new();
  return p;
}
void enqueue(queue* lst, int data)
{
	llist_prepend(lst->front,data);
	llist_append(lst->rear,data);
}
int dequeue(queue* lst)
{
	int pop= llist_get(lst->rear,0);
	llist_remove_first(lst->rear);
	llist_remove_last(lst->front);
	return pop;
}
bool queue_is_empty(queue* q)
{
    if((q->front)->head == NULL)    
    return 1;
    return 0;
}
int queue_size(queue* q)
{
  llist_size(q->front);
}
void queue_print(queue* q)
{
  	llist_print(q->rear);
}
