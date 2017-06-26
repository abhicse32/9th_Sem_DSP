#ifndef STACK_USING_QUEUE
#define STACK_USING_QUEUE
#include <stdbool.h>

typedef struct Queue_a{
	int *arr;
	int front;
	int rear;
}queue;

// create a new stack
queue* stack_new();

// push an element on the stack
void stack_push(queue*, int);

// pop the top element from the stack
int stack_pop(queue*);

// Check if stack is empty
bool stack_is_empty(queue*);

// bool check if stack is full
bool stack_is_full(queue*);

// find the size of the stack
int stack_size(queue*);

// print stack element
void stack_print(queue*);

#endif
