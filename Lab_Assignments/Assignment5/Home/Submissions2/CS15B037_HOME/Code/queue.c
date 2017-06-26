/*
 * On 18th september 2016
 * Written by Teratipally Srikar,CS15B037
 * This program manipulates queue
 * data structure using
 * linked lists
 */

#include "queue.h"      /*Including the required header files*/
#include <stdio.h>
#include <stdlib.h>

queue* queue_new()  // creates a new queue
{
    queue* new = (queue*) malloc(sizeof(queue));
    new->front = llist_new();
    new->rear = llist_new();
    return new;
}

void enqueue(queue* que, int data)  // adds an element to the queue
{
    llist_append(que->front,data);
    
    if((que->rear->head) == NULL) que->rear->head = que->front->head;
    else que->rear->head = (que->rear->head)->next;
}

int dequeue(queue* que) // removes the front element from the queue
{
    if(!queue_is_empty(que)){
    int data = que->front->head->data;
    llist_remove_first(que->front);
    if(que->front->head == NULL) que->rear->head = NULL;
    return data;}
}

bool queue_is_empty(queue* que) // Checks if queue is empty
{
    if(que->front->head == NULL) return true;
    else return false;
}

int queue_size(queue* que)  // finds the size of the queue
{
    return llist_size(que->front);
}

void queue_print(queue* que)    // prints queue element
{
    llist_print(que->front);
}
