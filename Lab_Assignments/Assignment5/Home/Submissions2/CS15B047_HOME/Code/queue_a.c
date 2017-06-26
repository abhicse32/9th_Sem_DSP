#include "queue_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

//Create new Q 
queue* queue_new()
{
        queue *Q ;
        Q = (queue*)malloc(sizeof(queue)) ;
        Q->arr = (int*)malloc(sizeof(int)*size) ;
        Q->front = 0 ;
        Q->rear = - 1 ;
        return Q ;          
}

//Check empty Q
bool queue_is_empty(queue *Q)
{
        if(Q->front == 0 && Q->rear == -1)
                return true;
        else
                return false;
}

//Check full Q
bool queue_is_full(queue *Q)
{
        if(queue_size(Q) == size)
                return true ;
        else
                return false ;        
}

//Gives Q size
int queue_size(queue *Q)
{
        if(Q->front == 0 && Q->rear == -1)
                return  0;
        else
        {
                if(Q->rear >= Q->front)                 
                        return (Q->rear - Q->front + 1) ;
                else
                        return (size + Q->rear - Q->front + 1) ;
        }
}

//Enqueue
void enqueue(queue *Q, int value)
{
        if(queue_is_full(Q) == false)
        {
                //Update rear and add element
                Q->rear = Q->rear + 1 ;
                if(Q->rear == size)
                        Q->rear = 0;
                Q->arr[Q->rear] = value ;
        }        
}

//Dequeue
int dequeue(queue *Q)
{
        if(queue_is_empty(Q) == false)
        {
                //If only 1 ele present set front and rear to 0 & -1 -->Identification for empty Q 
                if(queue_size(Q) == 1)
                {
                        int temp = Q->arr[Q->front] ;
                        Q->front = 0;
                        Q->rear = -1 ;        
                        return temp;
                }        
                else
                {
                        int temp = Q->arr[Q->front] ;
                        Q->front++;
                        return temp;                        
                }
        }
        return -1 ;
}

///Print Q
void queue_print(queue *Q)
{
        if(Q->rear != -1)
        {        
                int count = 0;
                for(count=0;count<queue_size(Q);count++)
                {
                        printf("%d ",Q->arr[Q->front + count]);        
                }
        }
}
