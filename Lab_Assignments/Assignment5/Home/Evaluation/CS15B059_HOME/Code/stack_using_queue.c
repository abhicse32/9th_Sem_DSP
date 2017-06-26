/* KOMMURU ALEKHYA REDDY 
        CS15B059
        30AUG2016
        PERFORMING OPERATIONS ON QUEUE AS IF IT WERE A STACK 
*/ 
#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

//to create a new stack which is actually a queue
queue* stack_new()
{
        return queue_new();
}

//to add an element at the front of stack
void stack_push(queue* que, int elm)
{
        int x;
        queue * temp = queue_new();   //make a temporary queue     
        while(!queue_is_empty(que))
        {
                x=dequeue(que);    
                enqueue(temp,x); 
        }//shift all the elements to the temporary queue
        enqueue(que,elm);//add one element
        while(!queue_is_empty(temp))
        {
                x=dequeue(temp);    
                enqueue(que,x); 
        }//shift all the elements back to the main queue from the temporary queue
}

//to remove the first element of a stack
int stack_pop(queue * que)
{
        int elm;
        elm=dequeue(que);
        return elm;
}


//to check if a stack is empty
bool stack_is_empty(queue* que)
{
        return queue_is_empty(que);
}


// find the size of the stack
int stack_size(queue* que)
{
        return queue_size(que);
}

// print stack element
void stack_print(queue * que)
{
        queue_print(que);
}

