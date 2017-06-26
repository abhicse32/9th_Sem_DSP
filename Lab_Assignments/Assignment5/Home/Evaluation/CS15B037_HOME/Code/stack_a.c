/*
 * On 18th september 2016
 * Written by Teratipally Srikar,CS15B037
 * This program manipulates stack
 * data structure using
 * linked lists
 */

#include "stack_a.h"    /*Including the required header files*/
#include <stdio.h>
#include <stdlib.h>
#define size 4


stack* stack_new()  // create a new stack
{
    stack* new = (stack*) malloc(sizeof(stack));
    (new->top) = -1;
    new->arr = malloc(sizeof(int)*size);
    return new;
}

void stack_push(stack* stk, int data)   // push an element on the stack
{
    (stk->top)++;
    stk->arr[(stk->top)] = data;
}

int stack_pop(stack* stk)   // pop the top element from the stack
{
    int data = stk->arr[(stk->top)];
    (stk->top)--;
    return data;
}

bool stack_is_empty(stack* stk) // Check if stack is empty
{
    if((stk->top)==-1) return true;
    else return false;
}

bool stack_is_full(stack* stk)  // bool check if stack is full
{
    if((stk->top)==(size-1)) return true;
    else return false;
}

int stack_size(stack* stk)  // find the size of the stack
{
    return ((stk->top)+1);
}

void stack_print(stack* stk)    // print stack element
{
    int i;  /*Counter*/
    for(i=(stk->top);i>=0;i--)
    {
        printf("%d ",stk->arr[i]);
    }
   // printf("\n");
}
