
 #include<stdio.h>
 #include<stdlib.h>
 #include "List.h"
 #include "stack.h"
 
 typedef stack *Stack;
 typedef LList *List;
 typedef Node *PtrToNode;
 
 void enqueue( stack *S , int data );
 int dequeue( stack *S );
 bool queue_is_empty( stack *S );
 int queue_size( stack *S );
 void queue_print( stack *S );
 
 int main( void )
{
  Stack S = stack_new();
  int i;
  
     for( i = 1 ; i <= 15 ; i++ )
    {
      enqueue( S , i );
      
         if( !( i % 3 ) )
          dequeue( S );
          
      queue_print( S );
      puts( "" );
    }
  
  free( S->top );
  free( S );
  
  return 0;
} 

 // add an element to the 'Queue implementation of Stack'
 
 void enqueue( stack *S , int data )
{
  Stack S1 = stack_new();
  
     while( !stack_is_empty( S ) )
      stack_push( S1 , stack_pop( S ) );
      
  stack_push( S , data );
  
     while( !stack_is_empty( S1 ) )
      stack_push( S , stack_pop( S1 ) );
      
  free( S1->top );
  free( S1 );    
} 

 // remove the front element from the 'Queue Implementation of Stack'
 
 int dequeue( stack *S )
{
  return stack_pop( S );
} 

 // Check if 'Queue implementation of Stack' is empty
 
 bool queue_is_empty( stack *S )
{
  return stack_is_empty( S );
} 

 // find the size of the 'Queue implementatio of Stack'
 
 int queue_size( stack *S )
{
  return stack_size( S );
}

 // print 'Queue implementation of Stack' element
 
 void queue_print( stack *S )
{
  stack_print( S );
}  
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
