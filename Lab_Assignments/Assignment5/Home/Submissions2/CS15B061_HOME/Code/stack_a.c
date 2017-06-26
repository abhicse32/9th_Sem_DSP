/*-----------------------------------------------------------------------------
 *  Program to implement stack ADT using arrays
 *  Name: Harshavardhan.P.K.
 *  RollNo: CS15B061
 *  Date: 17 Sept,2016
 *-----------------------------------------------------------------------------*/
#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

#include <stdbool.h>
#include <limits.h>


/*-----------------------------------------------------------------------------
 *  Function: stack_new() - to create a new stack
 *-----------------------------------------------------------------------------*/
stack* stack_new(){
	stack* newS = (stack*)malloc(sizeof(stack));
	//allocate memory for stack array
	newS->arr=(int*)malloc(sizeof(size));
	//top = -1 as no elements are present
	newS->top = -1;
	return newS;
}

/*-----------------------------------------------------------------------------
 *  Function: stack_push() - push an element stack
 *  Input: stack* s - input stack pointer
 *  	   int n - the number to input
 *-----------------------------------------------------------------------------*/
 void stack_push(stack* s, int n){
 	//if stack is full
	if(s->top >= size-1) return;
	//else increment top and place in arr[top]
	s->arr[++(s->top)]=n;
}

/*-----------------------------------------------------------------------------
 *  Function: stack_pop() - pop top element of stack
 *  Input: stack* s - input pointer to stack
 *  Returns the popped element
 *-----------------------------------------------------------------------------*/
int stack_pop(stack* s){
	//if stack is empty
	if(s->top == -1) return INT_MIN;
	//else decrement top and return the topmost element
	(s->top)--;
	return s->arr[s->top+1];
}

// Check if stack is empty
bool stack_is_empty(stack* s){
	return(s->top == -1);
}

// bool check if stack is full
bool stack_is_full(stack* s){
	return(s->top == size-1);
}

// find the size of the stack
int stack_size(stack* s){
	return(s->top+1);
}

// print stack element
void stack_print(stack* s){
	int i;
	//print it from arr[top] to arr[0]
	for(i=s->top;i>=0;i--)
		printf("%d ",s->arr[i]);
}

