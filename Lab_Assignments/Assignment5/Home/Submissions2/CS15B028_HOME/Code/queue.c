#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
queue* queue_new()
{
   queue*pq=(queue*)malloc(sizeof(queue));
   pq->front=llist_new();
   pq->rear=llist_new();
   return pq;
}
void enqueue(queue*pq, int data)
{
   if((pq->front)->head==NULL&&(pq->rear)->head==NULL)
   {
      Node*t=node_new(data);
      t->next=NULL;
      (pq->front)->head=t;
      (pq->rear)->head=t;
      return;
   }    
   llist_append(pq->front,data);
   (pq->rear)->head=((pq->rear)->head)->next;  
}
int dequeue(queue*pq)
{
   int x=((pq->front)->head)->data;
   (pq->front)->head=((pq->front)->head)->next;
   return x;
}
bool queue_is_empty(queue*pq)
{
   if((pq->front)->head==NULL&&(pq->rear)->head==NULL)
   return 1;
   else return 0;
}
int queue_size(queue*pq)
{
   return llist_size(pq->front);
}
void queue_print(queue*pq)
{
   llist_print(pq->front);
}
/*int main()
{
   int n;
   scanf("%d",&n);
   queue*pq=queue_new();
   int i,x;
   for(i=0;i<n;i++)
   {
      scanf("%d",&x);
      enqueue(pq,x);
   }
   queue_print(pq);  
}*/
