#include <stdio.h> 
#include <stdlib.h>
#include "stack_using_queue.h"
#include "queue.h"
#include "List.h"

void stack_reverse(queue*);

queue* stack_new()  
{
    queue* new = queue_new();
    return new;
}

void stack_push(queue* que,int data)
{
    int length = stack_size(que);
    enqueue(que,data);
    
    int i;  
    for(i=0;i<length;i++)
    {
        int temp = dequeue(que);
        enqueue(que,temp);
    }
}

int stack_pop(queue* que)
{
    return dequeue(que);
}

bool stack_is_empty(queue* que)
{
    return queue_is_empty(que);
}

int stack_size(queue* que)  
{
    return queue_size(que);
}

void stack_print(queue* que)   
{
    queue_print(que);
}

void stack_reverse(queue* que)  
{
    if(queue_is_empty) return;
    
    int data = dequeue(que);
    stack_reverse(que);
    enqueue(que,data);
}
