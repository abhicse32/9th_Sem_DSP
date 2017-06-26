#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>

#define size 1000

// create a new stack
stack *stack_new() {
    stack *stack1 = (stack *) malloc(sizeof(stack));
    stack1->arr = (int *) malloc(sizeof(int) * size);
    stack1->top = -1;
    return stack1;
}

// push an element on the stack
void stack_push(stack *stack1, int data) {
    int *array = stack1->arr;
    *(array + stack1->top + 1) = data;
    stack1->top++;
    return;
}

// pop the top element from the stack
int stack_pop(stack *stack1) {
    int *array = stack1->arr;
    int element = *(array + stack1->top);
    stack1->top--;
    return element;
}
// Check if stack is empty
bool stack_is_empty(stack *stack1) {
    if (stack1->top == -1)
        return 1;
    else
        return 0;
}

// bool check if stack is full
bool stack_is_full(stack *stack1) {
    if (stack1->top == size)
        return 1;
    else
        return 0;
}

// find the size of the stack
int stack_size(stack *stack1) {
    return stack1->top + 1;
}

// print stack element
void stack_print(stack *stack1) {
    int i, *array;
    array = stack1->arr;
    for (i = stack1->top; i >= 0; i--) {
        printf("%d ", *(array + i));
    }
//    printf("\n");
    return;
}
