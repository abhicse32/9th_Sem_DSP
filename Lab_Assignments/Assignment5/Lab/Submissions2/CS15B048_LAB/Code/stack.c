#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

// create a new stack
stack* stack_new(){
  stack* new = (stack*) malloc(sizeof(stack));
  new->top = llist_new();
  return new;
}

// push an element on the stack
void stack_push(stack* my_stack, int value){
  llist_prepend(my_stack->top, value);
}

// pop the top element from the stack
int stack_pop(stack* my_stack){
  return llist_remove_first(my_stack->top);
}

// find the size of the stack
int stack_size(stack* my_stack){
  return llist_size(my_stack->top);
}

// print stack element
void stack_print(stack* my_stack){
  llist_print(my_stack->top);
}
// Check if stack is empty
bool stack_is_empty(stack* my_stack){
  return (my_stack->top->head == NULL);
}
