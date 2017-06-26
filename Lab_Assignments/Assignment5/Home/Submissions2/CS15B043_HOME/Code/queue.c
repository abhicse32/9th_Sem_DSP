
 #include "queue.h"
 #include <stdio.h>
 #include <stdlib.h>
 
 typedef queue *Queue;
 typedef Node *PtrToNode;
 typedef LList *List;
 
 // create a new queue
 
 queue *queue_new()
{
  Queue NewQueue = ( Queue )malloc( sizeof( queue ) );
  
  NewQueue->front = llist_new();
  NewQueue->rear = llist_new();
  
  return NewQueue;
} 

 // add an element to the queue
 
 void enqueue( queue *Q , int data )
{
  PtrToNode NewNode = node_new( data );
  
     if( !Q->front->head )
    {
      Q->front->head = Q->rear->head = NewNode;
      return; 
    }      
     
  Q->rear->head->next = NewNode; 
  Q->rear->head = NewNode;  
} 

 // remove the front element from the queue
 
 int dequeue( queue *Q )
{
  int value = -1;
  
     if( !queue_is_empty( Q ) )
    {
      value = Q->front->head->data;
       
         if( Q->front->head == Q->rear->head )
          Q->rear->head = NULL;
    
      llist_remove_first( Q->front );
    }  
    
  return value;  
} 

 // Check if queue is empty
 
 bool queue_is_empty( queue *Q )
{
  return( Q->front->head == NULL );
} 

 // find the size of the queue
 
 int queue_size( queue *Q )
{
  Queue Q1 = queue_new();
  int data , size = 0;
     
     while( !queue_is_empty( Q ) )
    {
      size++;
      data = dequeue( Q );
      enqueue( Q1 , data );
    }
    
     while( !queue_is_empty( Q1 ) )
    {
      data = dequeue( Q1 );
      enqueue( Q , data );
    }    
    
  free( Q1->front );
  free( Q1->rear );
  free( Q1 );  
    
  return size;  
}

 // print queue element
 
 void queue_print( queue *Q )
{
  Queue Q1 = queue_new();
  int data;
  
     while( !queue_is_empty( Q ) )
    {
      data = dequeue( Q );
      enqueue( Q1 , data );
      printf( "%d " , data );
    }
    
     while( !queue_is_empty( Q1 ) )
    {
      data = dequeue( Q1 );
      enqueue( Q , data );
    }    
    
  free( Q1->front );
  free( Q1->rear );
  free( Q1 );  
} 









































 


 
 

