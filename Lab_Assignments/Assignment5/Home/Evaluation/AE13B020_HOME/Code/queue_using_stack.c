#include "queue_using_stack.h"
#include <stdio.h>
#include <stdlib.h>
// create a new queue
queue *queue_new(){
    queue* queue1=(queue *) malloc(sizeof(queue));
    queue1->stack1=stack_new();
    queue1->stack2=stack_new();
    return queue1;
}

// add an element to the queue
void enqueue(queue *queue1, int data){
    while(!stack_is_empty(queue1->stack1))
        stack_push(queue1->stack2,stack_pop(queue1->stack1));
    stack_push(queue1->stack1,data);
    while (!stack_is_empty(queue1->stack2))
        stack_push(queue1->stack1,stack_pop(queue1->stack2));
    return;
}

// remove the front element from the queue
int dequeue(queue *queue1){
    return stack_pop(queue1->stack1);
}

// Check if queue is empty
bool queue_is_empty(queue *queue1){
    if(stack_size(queue1->stack1)+stack_size(queue1->stack2))
        return false;
    else
        return true;
}

// find the size of the queue
int queue_size(queue *queue1){
    return stack_size(queue1->stack1)+stack_size(queue1->stack2);
}

// print queue element
void queue_print(queue *queue1){
    while(!stack_is_empty(queue1->stack1)){
        int data=stack_pop(queue1->stack1);
        printf("%d ",data);
        stack_push(queue1->stack2,data);
    }
    while (!stack_is_empty(queue1->stack2))
        stack_push(queue1->stack1,stack_pop(queue1->stack2));
    return;
}
