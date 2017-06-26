/*
 * On 18th september 2016
 * Written by Teratipally Srikar,CS15B037
 * This program manipulates stack
 * data structure using
 * linked lists
 */

#include "stack.h"  /*Including the required header files*/
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()      // creates a new stack
{
    stack* new = (stack*) malloc(sizeof(stack));
    new->top = llist_new();
    return new;
}

void stack_push(stack* stk, int data)   // pushes an element on the stack
{
    llist_prepend(stk->top,data);
}

int stack_pop(stack* stk)   // pops the top element from the stack
{
    
    if(!stack_is_empty(stk)){
    int data = llist_get(stk->top,0);
    llist_remove_first(stk->top);
    return data;}
}

bool stack_is_empty(stack* stk) // Checks if stack is empty
{
    if((stk->top)->head == NULL) return true;
    else return false;
}

int stack_size(stack* stk)  // finds the size of the stack
{
    return llist_size(stk->top);
}

void stack_print(stack* stk)    // prints the stack elements
{
    llist_print(stk->top);
}
