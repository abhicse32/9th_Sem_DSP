//
// Created by phani on 18/9/16.
//

#ifndef HW5_QUEUE_USING_STACK_H
#define HW5_QUEUE_USING_STACK_H

#include "stack.h"
#include "List.h"

typedef struct Queue {
    stack *stack1;
    stack *stack2;
} queue;

// create a new queue
queue *queue_new();

// add an element to the queue
void enqueue(queue *, int);

// remove the front element from the queue
int dequeue(queue *);

// Check if queue is empty
bool queue_is_empty(queue *);

// find the size of the queue
int queue_size(queue *);

// print queue element
void queue_print(queue *);

#endif //HW5_QUEUE_USING_STACK_H
