#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//Creat New stack and allocate memory 
stack *stack_new()
{
        stack *S;
        S = (stack*)malloc(sizeof(stack)) ;
        //top --> head of LL       
        S->top = llist_new() ;
        return S ;
}

//Push = Prepend
void stack_push(stack* S, int value)
{
        llist_prepend(S->top,value) ;
}

//check empty
bool stack_is_empty(stack *S)
{
        if(S->top->head == NULL)
                return true ;
        else
                return false ;
}

//Pop
int stack_pop(stack* S)
{
        int temp = INT_MIN ;
        //Check empty
        if(stack_is_empty(S) == false)
        {
                temp = S->top->head->data ;
                llist_remove_first(S->top) ;
        }
        return temp ;                
}
//Return stack size
int stack_size(stack *S)
{
        return llist_size(S->top) ;        
}

void stack_print(stack *S)
{
        if(S->top != NULL)
                llist_print(S->top) ;        
}
