
 #include "stack.h"
 #include "List.h"
 #include <stdio.h>
 #include <stdlib.h>
 
 typedef stack *Stack;
 typedef Node *PtrToNode;
 
 // create a new stack
 
 stack *stack_new()
{
  Stack NewStack = ( Stack )malloc( sizeof( stack ) );  
  NewStack->top = llist_new(); 
  
  return NewStack;
} 

 // push an element on the stack
 
 void stack_push( stack *S , int data )
{
  llist_prepend( S->top , data );
} 

 // pop the top element from the stack
 
 int stack_pop( stack *S )
{
  PtrToNode Temp = S->top->head;
  int value = -1;
  
     if( Temp )
      value = Temp->data;
    
  llist_remove_first( S->top );
  
  return value;    
}

 // Check if stack is empty
 
 bool stack_is_empty( stack *S )
{
  return( S->top->head == NULL );
} 

 // find the size of the stack
 
 int stack_size( stack *S )
{
  Stack S1 = stack_new();
  int size = 0;
 
     while( !stack_is_empty( S ) )
    {
      size++;
      stack_push( S1 , stack_pop( S ) );
    }
    
     while( !stack_is_empty( S1 ) ) 
      stack_push( S , stack_pop( S1 ) );
      
  free( S1->top );
  free( S1 );    
      
  return size;    
} 

 // print stack element
 
 void stack_print( stack *S )
{
  Stack S1 = stack_new();
  int value;
  
     while( !stack_is_empty( S ) )
    {
      value = stack_pop( S );
      stack_push( S1 , value );
      printf( "%d " , value );
    }  
  
     while( !stack_is_empty( S1 ) )
      stack_push( S , stack_pop( S1 ) );
    
  free( S1->top );
  free( S1 );  
} 




















