#ifndef STACK_USING_QUEUE_H
#define STACK_USING_QUEUE_H
#include "List.h"
#include "queue.h"
#include <stdbool.h>


// add an element to the stack
void stack_push(queue*, int);

// remove the front element from the queue
int stack_pop(queue*);

// Check if queue is empty
bool stack_is_empty(queue*);

// find the size of the queue
int stack_size(queue*);

// print queue element
void stack_print(queue*);

#endif
