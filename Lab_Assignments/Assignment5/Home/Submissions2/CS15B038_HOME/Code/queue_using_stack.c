#include "stack.h"
#include <stdbool.h>

stack* queue_new()
{
     return stack_new();
}

void enqueue(stack* A, int a)
{
     stack* B = queue_new();
     int z;
     
     while(!stack_is_empty(A))
     {
          z = stack_pop(A);
          stack_push(B, z);     
     }          
     
     stack_push(A, a);
     
     while(!stack_is_empty(B))
     {
          z = stack_pop(B);
          stack_push(A, z);
     }

}

int dequeue(stack* A)
{
     return stack_pop(A);
}

bool queue_is_empty(stack* A)
{
     return stack_is_empty(A);
}

int queue_size(stack* A)
{
     return stack_size(A);
}

void queue_print(stack* A)
{
     stack_print(A);
}
