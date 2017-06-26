/*
  SIMULATING STACK USING QUEUE
*/
#include "List.h"
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void reverse(queue *Q)                           //REVERSE THE QUEUE
{
    if(queue_size(Q) == 1);
    else if(queue_size(Q) == 2)
    {
        int b = dequeue(Q);
        enqueue(Q,b);
    }
    else
    {
        int a = dequeue(Q);
        reverse(Q);
        enqueue(Q,a);
    }
}

queue* stack_new()                               //Create a new stack
{
    return queue_new();
}

void stack_push(queue* Q, int data)              //Push an element on the stack
{
    if(queue_size(Q) == 0)
        enqueue(Q,data);
    else
    {
        reverse(Q);
        enqueue(Q,data);
        reverse(Q);
    }
}

int stack_pop(queue* Q)                          //Pop the top element from the stack
{
    return dequeue(Q);
}

bool stack_is_empty(queue* Q)                    //Check if stack is empty
{
    return queue_is_empty(Q);
}

int stack_size(queue* Q)                         //Find the size of the stack
{
    return queue_size(Q);
}

void stack_print(queue* Q)                       //Print stack elements
{
    queue_print(Q);
}
