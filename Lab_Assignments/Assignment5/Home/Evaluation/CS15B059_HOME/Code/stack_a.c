/* KOMMURU ALEKHYA REDDY 
        CS15B059
        30AUG2016
        PERFORMING OPERATIONS ON STACK AS IF IT WERE AN ARRAY 
*/ 
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

//to create a new stack
stack* stack_new()
{
        stack * newstack=(stack *)malloc(sizeof(stack));//malloc for stack
        newstack->arr=(int *)malloc(sizeof(int)*size);
        newstack->top=-1;//initially since no element is present top has the value -1
}

//to add an element to the stack
void stack_push(stack* stk, int elm)
{
        if(stk->top>= -1 || stk->top <=(size-1))//checking the range of the top pointer
        {
                stk->arr[++(stk->top)]=elm;//incrementing top and adding the element    
        }
        else
                printf("stack overload");//if top not in range
}

//to decrement the pointer and return the popped value
int stack_pop(stack* stk)
{
        int elm;
        elm=stk->arr[stk->top];
        stk->top--;//decrement the top pointer
         return elm;
}

//tp check if the stack is empty or not
bool stack_is_empty(stack* stk)
{
        bool b;
        if(stk->top ==-1)
                b=true;//if top is -1 then stack is empty
        else
                b=false;   
        return b;             
}

//to check if the stack if full
bool stack_is_full(stack *stk)
{
        if(stk->top ==(size-1))
                return true;
        else
                return false;      
}

//to get the size of the stack
int stack_size(stack* stk)
{
        int s;
        s = stk->top +1;//size is the topindex +1
        return s;
}

//to print all the elements of the stack
void stack_print(stack* stk)
{
        int store =stk->top;
        int x;
        while(stk->top!= -1)
        {
                x=stack_pop(stk);            
                printf("%d ",x);//printing the elements
        }
        stk->top=store;
}






















