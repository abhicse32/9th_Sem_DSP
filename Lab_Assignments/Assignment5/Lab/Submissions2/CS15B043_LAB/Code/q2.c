
 #include<stdio.h>
 #include<stdlib.h>
 
 struct stack
{
  int top;
  char *Arr;
};
  
 typedef struct stack *Stack;

 Stack Initialize_Stack( void );
 _Bool IsEmpty( Stack S );
 _Bool IsFull( Stack S );
 char Pop( Stack S );
 void Push( Stack S , char ch );
 int Min_Reversals( Stack S , char *Str ); 

 int main( void )
{
  Stack S = Initialize_Stack();
  int T , Min;
  char Str[1001];
  scanf( "%d" , &T ); 

     while( T-- )
    {
      S->top = -1;
      scanf( "%s" , Str );
      Min = Min_Reversals( S , Str );

      printf( "%d\n" , Min ); 
    }
 
  free( S->Arr );
  free( S );

  return 0;
}
  
 /* Function to initialize Stack */
  
 Stack Initialize_Stack( void )
{
  Stack S = ( Stack )malloc( sizeof( struct stack ) );
  S->top = -1;
  S->Arr = ( char* )malloc( 1000 * sizeof( char ) );

  return S;   
}

 /* Function to check if the stack is empty */
 
 _Bool IsEmpty( Stack S )
{ 
  return( S->top == -1 );
}

 /* Function to check if the Stack is full */

 _Bool IsFull( Stack S )
{
  return( S->top == 999 ); 
}

 /* Pops out the top element and return it */

 char Pop( Stack S )
{
     if( !IsEmpty( S ) )
      return S->Arr[S->top--];

  return '\0';
}
 
 /* Function to Push an element on to the stack */

 void Push( Stack S , char ch )
{
     if( !IsFull( S ) )
       S->Arr[++S->top] = ch;
}

 /* Function to compute the minimum number of reversals required */

 int Min_Reversals( Stack S , char *Str )
{
  int Min = 0 , i = 0;
  char ch = *Str;
       
     while( ch )
    {
         if( ch == 123 )
          Push( S , '{' );
         else
        {
             if( IsEmpty( S ) )
            {
              Min += 1;
              Push( S , '{' );
            }   
             else
              Pop( S );
        }

      i += 1;
      ch = *( Str + i ); 
    }

     if( IsEmpty( S ) )
      return Min;
    
     if( !( ( S->top + 1 ) % 2 ) )
      return( Min + ( ( S->top + 1 ) / 2 ) );

  return -1;
}












