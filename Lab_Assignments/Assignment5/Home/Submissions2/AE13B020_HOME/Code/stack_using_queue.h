//
// Created by phani on 18/9/16.
//

#ifndef HW5_STACK_USING_QUEUE_H
#define HW5_STACK_USING_QUEUE_H

#include "queue.h"
#include "List.h"

typedef struct Stack {
    queue* queue1;
    queue* queue2;
} stack;

// create a new stack
stack *stack_new();

// push an element on the stack
void stack_push(stack *, int);

// pop the top element from the stack
int stack_pop(stack *);

// Check if stack is empty
bool stack_is_empty(stack *);

// find the size of the stack
int stack_size(stack *);

// print stack element
void stack_print(stack *);

#endif //HW5_STACK_USING_QUEUE_H
