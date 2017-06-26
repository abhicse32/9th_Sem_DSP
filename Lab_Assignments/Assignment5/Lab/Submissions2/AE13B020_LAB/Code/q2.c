#include<stdio.h>
#include<string.h>
#include "stack.h"

int reversals(char *string);

void main() {
    int T;
    scanf("%d", &T);
    char string[1000];
    while (T--) {
        scanf("%s", string);
        printf("%d\n", reversals(string));
    }
}

int reversals(char *string) {
    int i, size = (int) strlen(string);
    if (size % 2)
        return -1;
    stack *st = stack_new();
    for (i = 0; i < size; i++) {
        if (string[i] == '}' && !stack_is_empty(st)) {
            if (llist_get(st->top, 0) == '{')
                stack_pop(st);
            else
                stack_push(st, string[i]);
        }
        else
            stack_push(st, string[i]);
    }
    int m = stack_size(st);
    int n = 0;
    while (!stack_is_empty(st) && llist_get(st->top, 0) == '{') {
        stack_pop(st);
        n++;
    }
    return (m / 2 + n % 2);
}
