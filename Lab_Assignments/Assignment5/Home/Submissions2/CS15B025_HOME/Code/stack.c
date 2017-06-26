/*
  BASIC STACK OPERATIONS 
  USING LINKED LISTS
*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

stack* stack_new()                               //Create a new stack
{
    stack *new;
    new = (stack *)malloc(sizeof(stack));
    new->top = llist_new();
    return new;
}

void stack_push(stack* S, int data)              //Push an element on the stack
{
    Node *t;
    t = ((S->top)->head);
    Node *new = node_new(data);
    ((S->top)->head) = new;
    new->next = t;
}

int stack_pop(stack* S)                          //Pop the top element from the stack
{
    stack *temp;
    temp = (stack *)malloc(sizeof(stack));
    temp = S;
    int top_element = 0;
    if(((temp->top)->head) == NULL)
        return -1;
    top_element = (((temp->top)->head)->data);
    ((temp->top)->head) = (((temp->top)->head)->next);
    return (top_element);
}

bool stack_is_empty(stack* S)                    //Check if stack is empty
{
    if(((S->top)->head) == NULL)
        return true;
    return false;
}

int stack_size(stack* S)                         //Find the size of the stack
{
    int len = 0;
    len = llist_size(S->top);
    return len;
}

void stack_print(stack* S)                       //Print stack elementS
{
    llist_print(S->top);
}
