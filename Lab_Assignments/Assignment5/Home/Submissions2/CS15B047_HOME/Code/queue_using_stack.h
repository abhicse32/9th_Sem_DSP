#ifndef QUS_H
#define QUS_H
#include"stack.h"

stack *queue_new();

bool queue_is_empty(stack *S);

int queue_size(stack *S);

void queue_print(stack *S);

void enqueue(stack *S,int element);

int dequeue(stack *S);

#endif
