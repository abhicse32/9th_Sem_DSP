#ifndef STACK_H
#define STACK_H
#include "List.h"
#include "stack.h"
#include "queue.h"
#include <stdbool.h>

queue* stack_new()                               //Create a new stack


void stack_push(queue*, int )              //Push an element on the stack


int stack_pop(queue* )                          //Pop the top element from the stack


bool stack_is_empty(queue* )                    //Check if stack is empty


int stack_size(queue* )                         //Find the size of the stack


void stack_print(queue* )                       //Print stack elements



#endif