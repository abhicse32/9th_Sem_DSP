#ifndef STACK_USING_QUEUE
#define STACK_USING_QUEUE
#include <stdbool.h>
#include "queue.h"

// create a new stack
typedef struct Stack_using_queue{
	queue* que1;
	queue* que2;
}stack_q;

stack_q* stack_new();

// push an element on the stack
void stack_push(stack_q*, int);

// pop the top element from the stack
int stack_pop(stack_q*);

// Check if stack is empty
bool stack_is_empty(stack_q*);

// find the size of the stack
int stack_size(stack_q*);

// print stack element
void stack_print(stack_q*);

#endif

