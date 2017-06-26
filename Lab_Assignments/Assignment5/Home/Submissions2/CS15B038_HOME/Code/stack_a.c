#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new()
{
     stack* A;
     A = malloc(sizeof(stack));
     A->arr = malloc(sizeof(int)*1000);
     A->top = -1;
     return A;
}

int stack_size(stack* A)
{
     return A->top + 1;
}

void stack_push(stack* A, int a)
{
     A->top = A->top + 1;
     A->arr[A->top] = a;
}

int stack_pop(stack* A)
{
     int x = A->arr[A->top];
     A->top = A->top - 1;
     return x;
}

bool stack_is_empty(stack* A)
{
     if(A->top == -1) return true;
     else return false;
}

bool stack_is_full(stack* A)
{
     if(A->top == 999) return true;
     else return false;
}

void stack_print(stack* A)
{
     for(int i = 0; i <= A->top; i++)
     {
          printf("%d ", A->arr[A->top-i]);
     }
}
