/*
  SIMULATING QUEUE USING STACK
*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

stack* queue_new()                               //Create a new queue
{
    return stack_new();
}

void enqueue(stack* S, int data)                 //Add an element to the queue
{
    if(stack_is_empty(S))
    {
        stack_push(S,data);
    }
    else
    {
        stack *T = stack_new();
        int i;
        int len = stack_size(S);
        for(i = 0;i < len;i++)                   //REVERSE, PUSH THEN REVERSE
        {
            stack_push(T,stack_pop(S));
        }
        stack_push(T,data);
        len = stack_size(T);
        for(i = 0;i < len;i++)
        {
            stack_push(S,stack_pop(T));
        }
    }
}

int dequeue(stack* S)                            //Remove the front element from the queue
{
    return stack_pop(S);
}

bool queue_is_empty(stack* S)                    //Check if queue is empty
{
    return stack_is_empty(S);
}

int queue_size(stack* S)                         //Find the size of the queue
{
    return stack_size(S);
}

void queue_print(stack* S)                       //Print queue element
{
    stack_print(S);
}
