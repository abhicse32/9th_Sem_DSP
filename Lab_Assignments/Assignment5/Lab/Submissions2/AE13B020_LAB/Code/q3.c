#include<stdio.h>
#include "stack.h"

void nextlargest();

void create_stack(stack *st, int *array, int start, int end) {
    int i;
    for (i = end - 1; i > start; i--)
        stack_push(st, array[i]);
}

void main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        nextlargest();
    }

}

void nextlargest() {
    int i, N;
    scanf("%d", &N);
    int array[N];
    for (i = 0; i < N; i++)
        scanf("%d", &array[i]);
    stack *st = stack_new();
    for (i = 0; i < N; i++) {
        create_stack(st, array, i, N);
        int poped = stack_pop(st);
        while (poped <= array[i]) {
            if (stack_is_empty(st)) {
                poped = -1;
                break;
            }
            poped = stack_pop(st);
        }
        printf("%d ", poped == array[i] ? -1 : poped);
    }
    printf("\n");
}
