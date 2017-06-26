/*D TEJA VARDHAN REDDY CS15B014  18/9/16*/
/* STACK ARRAY FUNCTIONS*/

#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000
// create a new stack
stack* stack_new(){
	stack*a=(stack*)malloc(sizeof(stack));
	a->arr=(int*)malloc(sizeof(int)*size);
	a->top=0;
}

// push an element on the stack
void stack_push(stack*a, int data){
	int top =a->top;
	if(a->top != size){
		
		(a->arr)[top]=data;
		a->top=a->top+1;
	}

}

// pop the top element from the stack
int stack_pop(stack*a){
	int top =a->top;
	if(!stack_is_empty(a))
	{
		top--;
		(a->top)--;
		return (a->arr)[top];
		
	}
}


// bool check if stack is full
bool stack_is_full(stack*a){
	if(a->top==size)
		return 1;
	else 
		return 0;
}
// Check if stack is empty
bool stack_is_empty(stack*a){
	if(a->top==0)
		return 1;
	else 
		return 0;
}
// find the size of the stack
int stack_size(stack*a){
	return a->top;
}
// print stack element
void stack_print(stack*a){
	int i;
	for ( i = a->top -1; i >= 0   ; --i)
	{
		printf("%d ",(a->arr)[i]);
	}

}