#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

queue* queue_new()
{  queue* qu = (queue*)malloc(sizeof(queue));
    qu->front=0;
    qu->rear=-1;
    int* arr= (int*)malloc(size*sizeof(int));
    if(arr==NULL)
        return NULL;
    qu->arr=arr;
    return qu;
}

void enqueue(queue* qu,int num)
{  if(qu->front==(qu->rear+2)%size )
    return;
    
    qu->rear=(qu->rear+1)%size;
    qu->arr[qu->rear]=num;
}

int dequeue(queue* qu)
{ int x;

    x=qu->front;
   qu->front=(qu->front+1)%size;
    return qu->arr[x];
}

bool queue_is_empty(queue* qu)
{ if(qu->front==(qu->rear+1)%size)
    return true;
    return false;
}

bool queue_is_full(queue* qu)
{ if(qu->front==(qu->rear+2)%size )
    return true;
    return false;
}

int queue_size(queue* qu)
{ return ((qu->rear-qu->front)+1)%size;
}

void queue_print(queue* qu)
{ int i;
    for(i=0; i<queue_size(qu);i++)
    { printf("%d ",qu->arr[(i+qu->front)%size]);
    }
    //printf("\n");
}

