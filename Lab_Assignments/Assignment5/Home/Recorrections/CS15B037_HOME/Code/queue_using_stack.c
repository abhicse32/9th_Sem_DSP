/*
 * On 18th September 2016
 * Written by Teratipally Srikar, CS15B037
 * This program manipulates queue
 * by using stack structure
 */

#include <stdio.h>  /*Including the required header files*/
#include <stdlib.h>
#include "List.h"
#include "stack.h"

void queue_reverse(stack* stk); /*This function reverses a given stack*/

stack* queue_new()  // creates a new queue
{
    stack* new = stack_new();
    return new;
}

void enqueue(stack *stk,int data)   // adds an element in the queue
{
    queue_reverse(stk);
    stack_push(stk,data);
    queue_reverse(stk);
}

int dequeue(stack *stk)     // removes the first element from the queue
{
    return stack_pop(stk);
}

bool queue_is_empty(stack *stk) // Checks if queue is empty
{
    return stack_is_empty(stk);
}

int queue_size(stack *stk)  // finds the size of the queue
{
    return stack_size(stk);
}

void queue_print(stack *stk)    // prints queue element
{
    stack_print(stk);
}

void queue_reverse(stack* stk)  /*This function reverses a given stack*/
{
    stack* reversed = stack_new();
    int n = stack_size(stk);
    int i;
    
    for(i=0;i<n;i++)
    {
        int data = stack_pop(stk);
        stack_push(reversed,data);
    }
    
    stk->top = reversed->top;
}



