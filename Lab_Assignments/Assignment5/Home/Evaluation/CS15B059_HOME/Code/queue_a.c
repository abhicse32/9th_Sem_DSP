/* KOMMURU ALEKHYA REDDY 
        CS15B059
        30AUG2016
        OPERATIONS ON QUEUE USING AN ARRAY 
*/ 
#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define size 1000

//to create a queue
queue* queue_new()
{
        queue * que=(queue *)malloc(sizeof(queue));//creating a queue using malloc
        que->arr=(int *)malloc(sizeof(int)* size);
        que->front=0;
        que->rear=size-1;//allotting indices for the pointers
        return que;
}

//increments the rear pointer and checks if rear is in the range
void enqueue(queue* que, int elm)
{
        que->rear++;
        if(que->rear>size-1)
        que->rear=0;//if rear is not in the range make it 0, initialise it again
        que->arr[que->rear]=elm;//append the element  
                   
}

//to remove the first element from the queue
int dequeue(queue* que)
{
        int x;
        x=que->arr[que->front];//gets the value at front
        que->front++;//increments the front pointer
        return x;//returns the value dequeued
}


//to check if a queue is empty
bool queue_is_empty(queue* que)
{
        int count;
        count=((que->rear) - (que->front) +1 + size) % size;    //calculates the size
        if(count==0)
                return true;//if the global variable count is zero then the queue is empty
        else
                return false;//else returns that it is not empty        
}


//checks if a queue is full
bool queue_is_full(queue* que)
{
        int count;
        count=((que->rear) - (que->front) +1 + size) % size;    //calculates the size
        if(count==size)
                return true;//if the count is equal to size then all elements have been inserted
        else
                return false;        
}

//returns the size of a queue
int queue_size(queue* que)
{
        int count;
        count=((que->rear) - (que->front) +1 + size) % size;    //calculates the size
        return count;//as we have already used a variable to keep a check on the numbers being inserted 

}

//to print all the elements of a queue by inserting a sentinal character, int min
void queue_print(queue* que)
{
        int count;
        count=((que->rear) - (que->front) +1 + size) % size;    //calculates the size
        int x;
        int s=0; 
        while(s<count)
        {
                x=dequeue(que);
                printf("%d ",x);
                enqueue(que,x);
                s++;
        }  
}











