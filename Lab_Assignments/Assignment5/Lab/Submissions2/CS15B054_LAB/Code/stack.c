#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack* stack_new()  // creating new stack
{
    stack* st=(stack*) malloc(sizeof(stack));
    st->top= llist_new();
    return st;
}

void stack_push(stack* st, int data)  // pushing data into stack
{
    llist_prepend(st->top,data);
}

int stack_pop(stack* st)    // getting st->top->head->data
{
    int top_val= llist_get(st->top,0);
    llist_remove_first(st->top);
    return top_val;
}

bool stack_is_empty(stack* st)  // checking weather stack is empty or not
{
    if(st->top->head == NULL) return 1;
    else return 0;
}

int stack_size(stack* st)    // to find size of stack
{
    return llist_size(st->top);
}

void stack_print(stack* st)   // printing stack
{
    llist_print(st->top);
}
