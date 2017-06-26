#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

//Create stack
stack* stack_new()
{
        stack *S ;
        //Allocate memory to stack and array
        S = (stack *)malloc(sizeof(stack)) ;
        S->arr = (int*)malloc(sizeof(int)*size) ;
        S->top = -1 ;

        return S ;
}
//Check full stack
bool stack_is_full(stack *S)
{
        if(S->top == size -1)
                return true ;
        else
                return false ;
}

//Check empty stack
bool stack_is_empty(stack *S)
{
        if(S->top == -1)
                return true ;
        else
                return false ;
}

//If stack not full push ele on stack
void stack_push(stack *S, int value)
{
        if(stack_is_full(S) == false)
        {
                (S->top)++ ;
                S->arr[S->top] = value ;                       
        }               
}

//If stack not empty pop ele from stack
int stack_pop(stack *S)
{
        if(stack_is_empty(S) == false)
        {
                int temp = S->arr[S->top] ;
                (S->top)-- ;
                return temp ;
        }
        else
                return -1 ;                
}

//Return size (+1 due to 0 based indexing) 
int stack_size(stack *S)
{
        return (S->top) + 1 ;
}

//print stack
void stack_print(stack *S)
{
        int count;
        
        for(count=S->top;count>=0;count--)
        {
                printf("%d ",S->arr[count]);        
        }
//        printf("\n");                        
}
