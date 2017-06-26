#include "queue.h"
#include <stdio.h>
#include <stdlib.h>


queue* queue_new(){
    queue* qu=(queue*) malloc(sizeof(queue));
    qu->front= llist_new();
    qu->rear=llist_new();
    qu->rear->head=qu->front->head;
    return qu;
}

void enqueue(queue* qu, int num){
    if(qu->front->head==NULL)
    { llist_append(qu->front,num);
        qu->rear->head=qu->front->head;
        return;
    }
    llist_append(qu->front,num);
    qu->rear->head=qu->rear->head->next;
}


int dequeue(queue* qu){
    
    int ret_val= llist_get(qu->front,0);
    llist_remove_first(qu->front);
    return ret_val;
}

// Check if queue is empty
bool queue_is_empty(queue* qu){
    if(qu->front->head)
        return false;
    return true;
}

// find the size of the queue
int queue_size(queue* qu){
    return llist_size(qu->front);
}

// print queue element
void queue_print(queue* qu){
    llist_print(qu->front);
}