#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new()
{
     queue* A;
     A = malloc(sizeof(queue));
     A->arr = malloc(sizeof(int)*1000);
     
     A->front = -1;
     A->rear = -1;
     
     return A;      
}

void enqueue(queue* A, int a)
{
     A->rear = 0;
     A->front = A->front + 1;
     
     for(int i=A->front; i >0; i--)
     {
          A->arr[i] = A->arr[i-1];
     }
     
     A->arr[0] = a;
}

int dequeue(queue* A)
{
     if(A->front == 0)
     {
          int x = A->arr[0]; 
          A->rear = -1;
          A->front = -1;  
          return x;
     }

     int x = A->arr[A->front];

     A->front = A->front - 1;
     
     return x;
}

bool queue_is_empty(queue* A)
{
     if(A->front == -1 && A->rear == -1) return true;
     else return false;
}

bool queue_is_full(queue* A)
{
     if(A->front == 999) return true;
     else return false;
}

int queue_size(queue* A)
{
     return A->front + 1;
}

void queue_print(queue* A)
{
     for(int i=A->front; i >= 0; i--)
     {
          printf("%d ",A->arr[i]);
     }
}
