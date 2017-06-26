#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

//Create new queue
queue* queue_new()
{
        queue *Q ;
        //Allocate memory
        Q = (queue*)malloc(sizeof(queue)) ;
        Q->front = llist_new() ;
        Q->rear =llist_new() ;
        
        return Q ;
}

//Enqueue element
void enqueue(queue *Q, int value)
{
        //If Q empty --> assign front and rear LL to new created node
        if(Q->rear->head == NULL && Q->front->head == NULL)
        {
                Q->rear->head = node_new(value) ;
                Q->front->head = Q->rear->head ;  
        }
        //Add element next to rear and update rear
        else
        {
                Q->rear->head->next = node_new(value) ;
                Q->rear->head = Q->rear->head->next ;  
        }
}

//Dequeue
int dequeue(queue *Q)
{
        int temp = -1 ;
        if(queue_is_empty(Q) == false)
        {                
                temp = Q->front->head->data ;
                //If only 1 ele then point both front andd rear to NULL
                if(queue_size(Q) == 1)
                {
                        Q->rear->head = NULL ;
                } 
                llist_remove_first(Q->front) ;
        }
        return temp ; 
}

//Check empty queue
bool queue_is_empty(queue *Q)
{
        //If front -> NULL then empty else not
        if(Q->front->head == NULL)
                return true ;
        else        
                return false ;
}

//Gives queue size 
int queue_size(queue *Q)
{
        return llist_size(Q->front) ;
}

//Print queue
void queue_print(queue *Q)
{
        llist_print(Q->front) ;        
}
