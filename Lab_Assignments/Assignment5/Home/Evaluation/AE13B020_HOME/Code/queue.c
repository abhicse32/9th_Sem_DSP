#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// create a new queue
queue *queue_new() {
    queue *queue1 = (queue *) malloc(sizeof(queue));
    queue1->front = llist_new();
    queue1->rear = llist_new();
    return queue1;
}

// add an element to the queue
void enqueue(queue *queue1, int data) {
    llist_prepend(queue1->rear, data);
    llist_append(queue1->front, data);
}

// remove the front element from the queue
int dequeue(queue *queue1) {
    int front_element = llist_get(queue1->front, 0);
    llist_remove_first(queue1->front);
    llist_remove_last(queue1->rear);
    return front_element;
}

// Check if queue is empty
bool queue_is_empty(queue *queue1) {
    int size = llist_size(queue1->front);
    if (size)
        return 0;
    else
        return 1;
}

// find the size of the queue
int queue_size(queue *queue1) {
    return llist_size(queue1->front);
}

// print queue element
void queue_print(queue *queue1) {
    int i, size = llist_size(queue1->front);
    for (i = 0; i < size; i++) {
        printf("%d ", llist_get(queue1->front, i));
    }
//    printf("\n");
}