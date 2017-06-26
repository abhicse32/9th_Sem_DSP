#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// Create a new stack
queue* stack_new()
{
 queue* queueptr=queue_new();
 return queueptr;
}

// Push an element on the stack
void stack_push(queue* queueptr,int x)
{
 int count=stack_size(queueptr);
 enqueue(queueptr,x);
 while(count>0)
 {
  count = count-1;
  int temp=dequeue(queueptr);
  enqueue(queueptr,temp);
 }

}

// Pop the top element from the stack
int stack_pop(queue* queueptr)
{
 int a=dequeue(queueptr);
 return a;
}

// Check if stack is empty
bool stack_is_empty(queue* queueptr)
{
 return queue_is_empty(queueptr);
}

// Size of the stack
int stack_size(queue* queueptr)
{
 return queue_size(queueptr);
}

//Print stack elements
void stack_print(queue* queueptr)
{
 queue_print(queueptr);
}
