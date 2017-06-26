/*
 * On 18th September 2016
 * Written by Teratipally Srikar, CS15B037
 * This program manipulates stack
 * data struncture using queue
 */

#include <stdio.h>  /*Including required header files*/
#include <stdlib.h>
#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"

void stack_reverse(queue*); /*This function reverses the given queue*/

queue* stack_new()  // create a new stack
{
    queue* new = queue_new();
    return new;
}

void stack_push(queue* que,int data)    // push an element on the stack
{
    int length = stack_size(que);
    enqueue(que,data);
    
    int i;  /*Counter*/
    for(i=0;i<length;i++)
    {
        int temp = dequeue(que);
        enqueue(que,temp);
    }
}

int stack_pop(queue* que)   // pop the top element from the stack
{
    return dequeue(que);
}

bool stack_is_empty(queue* que) // Check if stack is empty
{
    return queue_is_empty(que);
}

int stack_size(queue* que)  // find the size of the stack
{
    return queue_size(que);
}

void stack_print(queue* que)    // print stack element
{
    queue_print(que);
}

void stack_reverse(queue* que)  /*Including required header files*/
{
    if(queue_is_empty) return;
    
    int data = dequeue(que);
    stack_reverse(que);
    enqueue(que,data);
}