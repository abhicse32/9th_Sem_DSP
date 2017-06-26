/*
  BASIC STACK OPERATIONS 
  USING AN ARRAY
*/
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define size 1000

stack* stack_new()                               //Create a new stack
{
    stack *new;
    new = (stack *)malloc(sizeof(stack));
    new->arr = (int *)malloc(size * sizeof(int));
    new->top = -1;
    return new;
}

void stack_push(stack* S, int data)              //Push an element on the stack
{
    if((S->top) < (size-1))
        S->arr[++(S->top)] = data;
    return;
}

int stack_pop(stack* S)                          //Pop the top element from the stack
{  
    --(S->top);
    return (S->arr[(S->top) + 1]);
}

bool stack_is_empty(stack* S)                    //Check if stack is empty
{
    if((S->top) < 0)
        return true;
    return false;
}

bool stack_is_full(stack* S)                     //Check if stack is full
{
    if((S->top) == (size-1))
        return true;
    return false;
}

int stack_size(stack* S)                         //Find the size of the stack
{
    return ((S->top) + 1);
}

void stack_print(stack* S)                       //Print stack elements
{
    for(int i = (S->top);i >= 0;i--)
    {
        printf("%d ", *((S->arr) + i));
    }
}
