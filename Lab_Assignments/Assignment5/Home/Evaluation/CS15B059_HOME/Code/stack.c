/* KOMMURU ALEKHYA REDDY 
        CS15B059
        30AUG2016
        PERFORMING OPERATIONS ON A STACK 
*/ 
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

//create a new tack by allotting space for it 
stack* stack_new()
{
        stack * newstack=(stack *)malloc(sizeof(stack));
        newstack->top=llist_new();//creating a new list
        return newstack;
}

//to add an element at the beginning of a list
void stack_push(stack* stk, int elm)
{
        Node * first=(Node *)malloc(sizeof(Node));
	first->data=elm;
	first->next=stk->top->head;//need to use the head element directly, cant use a temporary variable
	stk->top->head=first;   
}

//pop function removes an element from the top of the stack and prints it
int stack_pop(stack* stk)
{
        int elm;
        if(stk->top->head!=NULL)//if it contains atleast one element
        {
                elm=stk->top->head->data;
                stk->top->head=stk->top->head->next;//get the element and remove the node
                 return elm;
        } 
        return INT_MIN;      
}

//to return true if stack is empty and false if it is not
bool stack_is_empty(stack* stk)
{
        if(stk->top->head== NULL)
                return true;//if the list pointer of stack points to NULL
        else 
                return false;        
}

//to find the size of the stack
int stack_size(stack* stk)
{
         int count=0,x;
        stack * tempstack=stack_new();//creating a temporary stack
        while(stk->top->head!=NULL)
        {
                x=stack_pop(stk);
                count ++;//pop the element and increment count
                stack_push(tempstack,x);//push it into a temporary stack
        }
        
        while(tempstack->top->head!=NULL)
        {
                x=stack_pop(tempstack);//push all the elements back into the previous stack
                stack_push(stk,x);
        }
        return count;
}

//to print all the elements of a stack,can access only the topmost element
void stack_print(stack* stk)
{
        int x;
        stack * tempstack=stack_new();//creating a temporary stack
        while(stk->top->head!=NULL)
        {
                x=stack_pop(stk);
                printf("%d ",x);//pop the element and print it
                stack_push(tempstack,x);//push it into a temporary stack
        }
        while(tempstack->top->head!=NULL)
        {
                x=stack_pop(tempstack);//push all the elements back into the previous stack
                stack_push(stk,x);
        }
}























