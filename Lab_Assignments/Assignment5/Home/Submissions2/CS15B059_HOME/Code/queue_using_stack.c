/* KOMMURU ALEKHYA REDDY 
        CS15B059
        30AUG2016
        PERFORMING OPERATIONS ON STACK AS IF IT WERE A QUEUE 
*/ 
#include<stdio.h>
#include"stack.h"
#include <stdlib.h>
#include<limits.h>

/*keeping the function names the same but performing the operation using a stack*/
//creating a new stack which appears like a queue to the outside world
stack* queue_new()
{
        stack * newstack=(stack *)malloc(sizeof(stack));
        newstack->top=llist_new();//creating a new list
        return newstack;
}

//to add an element at the back
void enqueue(stack* stk, int elm)
{
        int x;
        stack * temp=stack_new();//creats a temporary stack
        while(!stack_is_empty(stk))
        {
              x=stack_pop(stk);
              stack_push(temp,x);  //pop all the elements of the main stack
        }
        stack_push(stk,elm);//push the new element
        while(!stack_is_empty(temp))
        {
              x=stack_pop(temp);
              stack_push(stk,x); //pop all the elements and push them back into the main stack
        }
}

//to remove the first element
int dequeue(stack * stk)
{
        int elm;
        elm=stack_pop(stk);
        return elm;
}

//to check if the stack is empty
bool queue_is_empty(stack * stk)
{
        return stack_is_empty(stk);
}

//to find the size of the queue which is also the size of the stack 
int queue_size(stack * stk)
{
        return stack_size(stk);
}


//to print all the elements of a stack
void queue_print(stack *stk)
{
        stack_print(stk);//prints it in the same order
}
