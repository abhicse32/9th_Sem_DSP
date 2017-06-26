#ifndef STACK_H
#define STACK_H
#include "List.h"
#include <stdbool.h>
#include <stdlib.h>
#include "queue.h"

typedef struct Stack{
	LList* top;
}stack;

void reverse(queue* q1, queue* q2);

// create a new stack
queue* stack_new();

// push an element on the stack
void stack_push(queue*, int);

// pop the top element from the stack
int stack_pop(queue*);

// Check if stack is empty
bool stack_is_empty(queue*);

// find the size of the stack
int stack_size(queue*);

// print stack element
void stack_print(queue*);

#endif
