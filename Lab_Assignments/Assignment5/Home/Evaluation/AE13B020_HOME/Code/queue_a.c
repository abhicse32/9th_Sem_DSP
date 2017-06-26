#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>

#define size 1000

// create a new queue
queue *queue_new() {
    queue *queue1 = (queue *) malloc(sizeof(queue));
    queue1->arr = (int *) malloc(sizeof(int) * size);
    queue1->front = 0;
    queue1->rear = -1;
    return queue1;
}

// add an element in the queue
void enqueue(queue *queue1, int data) {
    int *array = queue1->arr;
    *(array + queue1->rear + 1) = data;
    queue1->rear++;
    return;
}

// remove the first element from the queue
int dequeue(queue *queue1) {
    int *array = queue1->arr;
    int element = *(array + queue1->front);
    queue1->front++;
    return element;
}
// Check if queue is empty
bool queue_is_empty(queue *queue1) {
    if (queue1->front <= queue1->rear)
        return 0;
    else
        return 1;
}

// bool check if queue is full
bool queue_is_full(queue *queue1) {
    if (queue1->rear >= size)
        return 1;
    else
        return 0;
}

// find the size of the queue
int queue_size(queue *queue1) {
    if (queue1->front <= queue1->rear)
        return queue1->rear - queue1->front + 1;
    return 0;
}

// print queue element
void queue_print(queue *queue1) {
    int i, *array;
    array = queue1->arr;
    for (i = queue1->front; i <= queue1->rear; i++) {
        printf("%d ", *(array + i));
    }
//    printf("\n");
    return;
}