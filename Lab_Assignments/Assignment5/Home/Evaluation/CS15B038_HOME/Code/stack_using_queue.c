#include "queue.h"
#include <stdbool.h>

queue* stack_new()
{
     return queue_new();
}

void stack_push(queue* Q, int a)
{
     queue* P = queue_new();
     int z;
     
     while(!queue_is_empty(Q))
     {
          z = dequeue(Q);
          enqueue(P, z);     
     }          
     
    enqueue(Q, a);
     
     while(!queue_is_empty(P))
     {
          z = dequeue(P);
          enqueue(Q, z);
     }

  
}

int stack_pop(queue* Q)
{
     return dequeue(Q);
}

bool stack_is_empty(queue* Q)
{
     return queue_is_empty(Q);
}

int stack_size(queue* Q)
{
     return queue_size(Q);
}

void stack_print(queue* Q)
{
     queue_print(Q);
}
