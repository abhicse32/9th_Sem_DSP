
 #include<stdio.h>
 #include<stdlib.h>
 #include "List.h"
 #include "queue.h"
 
 typedef queue *Queue;
 typedef LList *List;
 typedef Node *PtrToNode;
 
 void stack_push( queue *Q , int data );
 int stack_pop( queue *Q );
 bool stack_is_empty( queue *Q );
 int stack_size( queue *Q );
 void stack_print( queue *Q );
 
 int main( void )
{
  Queue Q = queue_new();
  int i;

  /*  
     for( i = 0 ; i <= 15 ; i++ )
    {
      stack_push( Q , i );
      
         if( !( i % 3 ) )
          stack_pop( Q );
          
      stack_print( Q );    
      puts( "" );   
    } 
  
 */
  
  free( Q->front );
  free( Q->rear );
  free( Q );    
  
  return 0;  
}

 // push an element on the stack
 
 void stack_push( queue *Q , int data )
{
  Queue Q1 = queue_new();
  enqueue( Q1 , data );                      /* Here we take two Queue's and simulate the behavious of stack. */
                                             
     while( !queue_is_empty( Q ) )          /* The push function is made costly so that the resulting queue looks like a stack */
      enqueue( Q1 , dequeue( Q ) );
                                            /* All other functions are normal - Only Push function is involving changes here */
     while( !queue_is_empty( Q1 ) )
      enqueue( Q , dequeue( Q1 ) );
      
  free( Q1->front );
  free( Q1->rear );
  free( Q1 );    
}

 // pop the top element from the stack
 
 int stack_pop( queue *Q )
{
  return dequeue( Q );
} 

 // Check if stack is empty
 
 bool stack_is_empty( queue *Q )
{
  return queue_is_empty( Q );
}

 // find the size of the stack
 
 int stack_size( queue *Q )
{
  return queue_size( Q );
} 

 // print stack element
 
 void stack_print( queue *Q )
{
  queue_print( Q );
}
















