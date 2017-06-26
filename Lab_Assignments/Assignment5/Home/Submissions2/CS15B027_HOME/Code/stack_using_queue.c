#include "stack_using_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
queue* stack_new()
{
  queue* out = queue_new();
  return out;
}
void stack_push(queue* q, int data)
{
  queue* out = queue_new();
if(queue_is_empty(q) == 1)
   enqueue(q,data);
 else
 {
  while(queue_is_empty(q) == 0)
  {
   int x = dequeue(q);
   enqueue(out,x);
  }   enqueue(q,data);
  while(queue_is_empty(out) == 0)
  {
   int y = dequeue(out);
   enqueue(q,y);
   } 
 }
}
int stack_pop(queue* q)
{if(queue_is_empty(q) == 0)
  return dequeue(q);   
}
bool stack_is_empty(queue* q)
{
   return queue_is_empty(q);
}
int stack_size(queue* q)
{
   return queue_size(q);
}
void stack_print(queue* q)
{
   queue_print(q);
}
