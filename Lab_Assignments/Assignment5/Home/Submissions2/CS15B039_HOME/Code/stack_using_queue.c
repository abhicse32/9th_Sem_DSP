#include<stdio.h>
#include "stack_using_queue.h"
#include <stdlib.h>
#include"queue_a.c"
#include <limits.h>
#define size 1000

// create a new stack
queue* stack_new(){
	
	queue* new_stack = (queue*) malloc(sizeof(stack));
	new_stack->arr = (int *) malloc(sizeof(int)*size);
	new_stack->front = size-1;
	new_stack->rear = 0;
	return new_stack;
}

// Check if stack is empty
bool stack_is_empty(queue* q){
    return(queue_is_empty(q));
}

// bool check if stack is full
bool stack_is_full(queue* q){
    return(queue_is_full(q));
}

// find the size of the stack
int stack_size(queue* q){
    return ((q->front - q->rear + 1 +size) % size);
}

// push an element on the stack
void stack_push(queue* q, int n){
    if(!queue_is_full(q)){
        q->front = (q->front + 1) % size;
        (q->arr)[q->front] = n;
        }
}

// pop the top element from the stack
int stack_pop(queue* q){
    int x = INT_MAX;
    if(!queue_is_empty(q)){
        x = (q->arr)[q->front];
        q->front = ((q->front - 1 + size) % size);
       }
    return x;
}

// print stack element
void stack_print(queue* q){

	queue_print(q);
}
