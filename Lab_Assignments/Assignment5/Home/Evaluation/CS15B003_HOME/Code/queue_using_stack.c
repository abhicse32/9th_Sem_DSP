#include <stdio.h>  
#include <stdlib.h>
#include "List.h"
#include "stack.h"

void queue_reverse(stack* stk); 

stack* queue_new()  
{
    stack* new = stack_new();
    return new;
}

void enqueue(stack *stk,int data)
{
    queue_reverse(stk);
    stack_push(stk,data);
    queue_reverse(stk);
}

int dequeue(stack *stk)     
{
    return stack_pop(stk);
}

bool queue_is_empty(stack *stk)
{
    return stack_is_empty(stk);
}

int queue_size(stack *stk)  
{
    return stack_size(stk);
}

void queue_print(stack *stk)
{
    stack_print(stk);
}

void queue_reverse(stack* stk)
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



