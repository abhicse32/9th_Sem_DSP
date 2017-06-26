
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
 int Check_Parenthesis( Stack S , char *Str );

 int main( void )
{
  Stack S = Initialize_Stack();
  int T;
  scanf( "%d" , &T );
  char Str[1001];

     while( T-- )
    { 
      S->top = -1;
      scanf( "%s" , Str );
      printf( "%d\n" , Check_Parenthesis( S , Str ) );  
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

 /* Function to check if the given Parenthesis sequence is a Valid sequence */

 int Check_Parenthesis( Stack S , char *Str )
{
  int i = 0 , j;
  char ch = *Str , Temp;

     while( ch != '\0' )
    {
         if( ch == 40 || ch == 91 || ch == 123 )
        {
          Push( S , ch );
        }
         else
        {
             if( !IsEmpty( S ) )
            {
              Temp = Pop( S );

                 if( ch == 41 )
                {
                     if( Temp != 40 )
                      return 0;
                }     
                 else 
                {
                     if( ch == 93 )
                    {
                         if( Temp != 91 )
                          return 0;
                    }
                     else 
                    { 
                         if( Temp != 123 )
                          return 0; 
                    } 
                }    
            }
        }

      i++;
      ch = *( Str + i );  
    }

     if( IsEmpty( S ) )
      return 1;
   
  return 0; 
}













