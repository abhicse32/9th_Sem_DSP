
 #include "queue_a.h"
 #include <stdio.h>
 #include <stdlib.h>
 #define size 1000
 
 typedef queue *Queue;
 
 // create a new queue 
 
 queue* queue_new()
{
  Queue Q = ( Queue )malloc( sizeof( queue ) );
  
  Q->arr = ( int* )malloc( ( size + 1 ) * sizeof( int ) );
  Q->front = Q->rear = 0;
  
  return Q;
} 

 // bool check if queue is full
 
 bool queue_is_full( queue *Q )
{
     if( Q->rear == size )
      return( Q->front == 0 );
     else
      return( Q->rear + 1 == Q->front ); 
} 

 // Check if queue is empty
 
 bool queue_is_empty( queue *Q )
{
  return( Q->front == Q->rear );
} 

 // add an element in the queue
 
 void enqueue( queue *Q , int data )
{
     if( !queue_is_full( Q ) )
    {
      *( Q->arr + Q->rear ) = data;
      
         if( Q->rear == size )
          Q->rear = 0;
         else
          Q->rear = Q->rear + 1;  
    } 
}

 // remove the first element from the queue
 
 int dequeue( queue *Q )
{
  int value = -1;
  
     if( !queue_is_empty( Q ) )
    {
      value = *( Q->arr + Q->front );
      
         if( Q->front == size )
          Q->front = 0;
         else
          Q->front = Q->front + 1; 
    } 
    
  return value;  
} 

 // find the size of the queue
 
 int queue_size( queue *Q )
{
     if( Q->rear >= Q->front )
      return( Q->rear - Q->front );
     else
      return( size + 1 - Q->front + Q->rear );  
} 

 // print queue element
 
 void queue_print( queue *Q )
{
  int i;
  
     if( Q->rear > Q->front )
    {
         for( i = Q->front ; i < Q->rear ; i++ )
          printf( "%d " , *( Q->arr + i ) );
    } 
     else
    {
         if( Q->front > Q->rear )
        { 
             for( i = Q->front ; i < size + 1 ; i++ )
              printf( "%d " , *( Q->arr + i ) );
          
             for( i = 0 ; i < Q->rear ; i++ )
              printf( "%d " , *( Q->arr + i ) );
        }
         else
          printf( "0 " );        
    } 
}
 

/* 

  Here , I am storing only 'n - 1' elements in an 'n' numbered array. It is Circular Array Implementation.
  
  The queue is empty if both 'front' and 'rear' point to the same element.
  
  The queue is full if the front is pointing to the next element to which the rear is pointing.
  
  Whenever an element is to be inserted , it is inserted in the position to which the rear is pointing and incremented.
  
  The bount conditions are checked with an if-else statement.
  
*/    
