/*-----------------------------------------------------------------------------
 *  Program to implement stack ADT using linked list
 *  Name: Harshavardhan.P.K.
 *  RollNo: CS15B061
 *  Date: 17 Sept,2016
 *-----------------------------------------------------------------------------*/
#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



/*-----------------------------------------------------------------------------
 *  Function: stack_new() - to create a new stack
 *-----------------------------------------------------------------------------*/
stack* stack_new(){
	//allocate memory for new stack
	stack* newS = (stack*)malloc(sizeof(stack));
	newS->top= llist_new();
	return newS;
}


/*-----------------------------------------------------------------------------
 *  Function: stack_push() - push an element stack
 *  Input: stack* s - input stack pointer
 *  	   int n - the number to input
 *-----------------------------------------------------------------------------*/
void stack_push(stack* s, int n){
	llist_prepend(s->top,n);
}


/*-----------------------------------------------------------------------------
 *  Function: stack_pop() - pop top element of stack
 *  Input: stack* s - input pointer to stack
 *  Returns the popped element
 *-----------------------------------------------------------------------------*/
int stack_pop(stack* s){
	//store top element in ans
	int ans = llist_get(s->top,0);
	llist_remove_first(s->top);
	return ans;
}

// Check if stack is empty
bool stack_is_empty(stack* s){
	return(!(s->top->head));
}


/*-----------------------------------------------------------------------------
 *  Function stack_size() - to find no. of elements in stack
 *  Input: stack* s - input stack pointer
 *  Returns the number of elements in stack
 *-----------------------------------------------------------------------------*/
int stack_size(stack* s){
	stack *t = stack_new();
	int sz=0;//store count of elements
	//pop elemnts from s to t and increment sz to get no. of elements
	while(!stack_is_empty(s)){
		int nu = stack_pop(s);
		stack_push(t,nu);
		sz++;
	}
	//push back the elements from t to s
	while(!stack_is_empty(t)){
		int nu = stack_pop(t);
		stack_push(s,nu);
	}
	return sz;
}


/*-----------------------------------------------------------------------------
 *  Function: stack_print() to print the elements of stack
 *  Input: stack *s: the input stack pointer
 *-----------------------------------------------------------------------------*/
void stack_print(stack* s){

	stack *t = stack_new();
	//pop elements from s to t and print them
	while(!stack_is_empty(s)){
		int nu = stack_pop(s);
		printf("%d ",nu);
		stack_push(t,nu);
	}
	//pop back the elements to s
	while(!stack_is_empty(t)){
		int nu = stack_pop(t);
		stack_push(s,nu);
	}
}
