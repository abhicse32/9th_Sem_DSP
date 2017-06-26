//
// Created by phani on 18/9/16.
//
// create a new stack
#include "stack_using_queue.h"
#include <stdio.h>
#include <stdlib.h>

stack *stack_new(){
    stack* stack1=(stack *)malloc(sizeof(stack));
    stack1->queue1=queue_new();
    stack1->queue2=queue_new();
    return stack1;
}

// push an element on the stack
void stack_push(stack *stack1, int data){
    enqueue(stack1->queue2,data);
    while(!queue_is_empty(stack1->queue1))
        enqueue(stack1->queue2,dequeue(stack1->queue1));
    while(!queue_is_empty(stack1->queue2))
        enqueue(stack1->queue1,dequeue(stack1->queue2));
    return;
}

// pop the top element from the stack
int stack_pop(stack *stack1){
    return dequeue(stack1->queue1);
}

// Check if stack is empty
bool stack_is_empty(stack *stack1){
    if(queue_size(stack1->queue1)+queue_size(stack1->queue1))
        return false;
    else
        return true;
}

// find the size of the stack
int stack_size(stack *stack1){
    return queue_size(stack1->queue1);
}

// print stack element
void stack_print(stack *stack1){
    while(!queue_is_empty(stack1->queue1)){
        int data=dequeue(stack1->queue1);
        printf("%d ",data);
        enqueue(stack1->queue2,data);
    }
    while(!queue_is_empty(stack1->queue2))
        enqueue(stack1->queue1,dequeue(stack1->queue2));
    return;
}

