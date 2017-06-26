#include<stdio.h>
#include<string.h>
#include "stack.h"

int check();

void main() {
    int T;
    scanf("%d", &T);
    while (T--)
        printf("%d\n", check());
}

int check() {
    char string[1000];
    scanf("%s", string);
    int i;
    int size = strlen(string);
    stack *st = stack_new();
    for (i = 0; i < size; i++) {
        switch (string[i]) {
            case '{': {
                stack_push(st, string[i]);
                break;
            }
            case '(': {
                stack_push(st, string[i]);
                break;
            }
            case '[': {
                stack_push(st, string[i]);
                break;
            }
            case '}': {
                if (stack_size(st) == 0)
                    return 0;
                int poped_element = stack_pop(st);
                if (poped_element != 123)
                    return 0;
                break;
            }
            case ')': {
                if (stack_size(st) == 0)
                    return 0;
                int poped_element = stack_pop(st);
                if (poped_element != 40)
                    return 0;
                break;
            }
            case ']': {
                if (stack_size(st) == 0)
                    return 0;
                int poped_element = stack_pop(st);
                if (poped_element != 91)
                    return 0;
                break;
            }
        }
    }
    return 1;
}
