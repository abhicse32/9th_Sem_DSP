/*
*16th September 2016
*Written By Teratipally Srikar, CS15B037
*This Program has the functions required
*for manipulating the stack
*like create, insert, remove, size, print
*/

#include "stack.h"  /*Including the required header files*/
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()  /*This function returns a new stack*/
{
    stack* new = (stack*) malloc(sizeof(stack));
    new->top = llist_new();
    return new;
}

void stack_push(stack* stk, int data)   /*This function pushes an element in to a stack*/
{
    llist_prepend(stk->top,data);
}

int stack_pop(stack* stk)   /*This function removes an element from the stack and returns its value*/
{
    int data = llist_get(stk->top,0);
    llist_remove_first(stk->top);
    return data;
}

bool stack_is_empty(stack* stk) /*This function tells whether a stack is empty or not*/
{
    if((stk->top)->head == NULL) return true;
    else return false;
}

int stack_size(stack* stk)  /*This function returns the size of the stack*/
{
    return llist_size(stk->top);
}

void stack_print(stack* stk)    /*This function prints all the elements in the stack*/
{
    llist_print(stk->top);
}

int stack_peep(stack* stk)  /*This function returns the value of the top lement in the stack*/
{
    return stk->top->head->data;
}
