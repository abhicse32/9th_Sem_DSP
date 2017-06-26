
 #include "stack_a.h"
 #include <stdio.h>
 #include <stdlib.h>
 #define size 1000

 /* Array implementation of Stack */

 typedef stack *Stack;
 
 // create a new stack
 
 stack *stack_new()
{
  Stack NewStack = ( Stack )malloc( sizeof( stack ) );
  
  NewStack->top = -1;
  NewStack->arr = ( int* )malloc( size * sizeof( int ) );
  
  return NewStack;
} 

 // push an element on the stack
 
 void stack_push( stack *S , int data )
{ 
     if( !stack_is_full( S ) )         /* S->top points to the element to top most element in the stack */
      S->arr[++S->top] = data;         /* Hence, to insert an element we increment and top and insert in it position */   
} 

 // pop the top element from the stack
 
 int stack_pop( stack *S )
{
     if( !stack_is_empty( S ) )
      return S->arr[S->top--];       /* To delete an element , we just decrement the top */
    
  return -1;   
} 

 // Check if stack is empty
 
 bool stack_is_empty( stack *S )
{
  return( S->top == -1 );        /* Returns '1' if the stack is empty else it returns '0' */
} 

 // bool check if stack is full
 
 bool stack_is_full( stack *S )
{
  return( S->top + 1 == size );     /* Returns '1' if the stack is full , else it returns '0' */
} 

 // find the size of the stack
 
 int stack_size( stack *S )
{
  return( S->top + 1 );  
}

 // print stack element
 
 void stack_print( stack *S )
{
  int i;
  
     for( i = S->top ; i >= 0 ; i-- )
      printf( "%d " , *( S->arr + i ) );    
} 



























