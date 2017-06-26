#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

stack *stack_new() {
    stack *st = (stack *) malloc(sizeof(stack));
    st->top = llist_new();
    return st;
}

void stack_push(stack *st, int data) {
    llist_append(st->top, data);
    return;
}

int stack_pop(stack *st) {
    int size = llist_size(st->top);
    int pop_element = llist_get(st->top, size - 1);
    llist_remove_last(st->top);
    return pop_element;
}

bool stack_is_empty(stack *st) {
    int size = llist_size(st->top);
    if (size)
        return 0;
    else
        return 1;
}

int stack_size(stack *st) {
    return llist_size(st->top);
}

void stack_print(stack *st) {
    int i, size = llist_size(st->top);
    for (i = size - 1; i >= 0; i--) {
        printf("%d ", llist_get(st->top, i));
    }
//    printf("\n");
}
