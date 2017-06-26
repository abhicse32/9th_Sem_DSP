
 #include<stdio.h>
 #include<stdlib.h>
 
 struct stack
{
  int top;                   // A[][0] - To store the elements of array in the stack
  int Arr[10000][2];         // A[][1] - To store the Positions of elements of array in the stack
};
  
 typedef struct stack *Stack;

 _Bool IsEmpty( Stack S );
 _Bool IsFull( Stack S );
 int Pop( Stack S );
 int Top( Stack s );
 void Push( Stack S , int Element , int Position );
 void Maintain_Order( Stack S , int Element , int Position , int *G );

 int main( void )
{
  struct stack S1;
  Stack S = &S1;
  int T , N , i , Element , Pos;
  scanf( "%d" , &T );

     while( T-- )
    {
      S->top = -1;
      scanf( "%d" , &N );
      int G[N];                       // 'G' Array is to store the Next greater element of every element in the array
    
         for( i = 0 ; i < N ; i++ )
        {
          scanf( "%d" , &Element );
          Maintain_Order( S , Element , i , G );   
        } 

         while( !IsEmpty( S ) )
        {
          Pos = Pop( S );
          G[Pos] = -1;
        } 

         for( i = 0 ; i < N ; i++ )
          printf( "%d " , *( G + i ) );

      puts( "" );
    }
   
  return 0;
}

 /* Function to check if the stack is empty */
 
 _Bool IsEmpty( Stack S )
{ 
  return( S->top == -1 );
}

 /* Function to check if the Stack is full */

 _Bool IsFull( Stack S )
{
  return( S->top == 9999 ); 
}

 /* Pops out the top element's position in the array and return it */

 int Pop( Stack S )
{
  int Temp = -1;

     if( !IsEmpty( S ) )
    {
      Temp =  S->Arr[S->top][1];
      S->top--;
    }

  return Temp;
}
 
 /* Function to Push an element and its position in the array on to the stack */

 void Push( Stack S , int Element , int Position  )
{
     if( !IsFull( S ) )
    {
      S->top++; 
      S->Arr[S->top][0] = Element;
      S->Arr[S->top][1] = Position;
    }
}

 /* Function that returns the top element from the Stack */

 int Top( Stack S )
{
     if( !IsEmpty( S ) )
      return( S->Arr[S->top][0] );

  return -1; 
}

 /* Function to maintain stack and the Greater than array after each element in the array is being added */

 void Maintain_Order( Stack S , int Element , int Position , int *G )
{
  int Temp , Pos;

     while( !IsEmpty( S ) )
    {
      Temp = Top( S );

         if( Element > Temp )
        {
           Pos = Pop( S );
           G[Pos] = Element;
        }
         else
          break;
    } 

  Push( S , Element , Position );
}

