
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include "List.h"
 #include "stack.h"
 
 typedef stack *Stack;
 
 long long int PostEvaluate( Stack S , char *Str );
 long long int StringToNum( char *Str , int *j );
 long long int Evaluate_Value( Stack S , char operation );
 
 int main( void )
{
  Stack S = stack_new();
  char Str[1001];
  long long int value;
  fgets( Str , 1000 , stdin );            // As the String contains spaces , we read it using 'fgets' function */
  
  value = PostEvaluate( S , Str );
  printf( "%lld\n" , value ); 
  
  free( S->top );
  free( S );
  
  return 0;
} 

 /* Function calculates the value of Post Fix Expression and returns its value */

 long long int PostEvaluate( Stack S , char *Str )
{
  long long int value; 
  int i = 0 , length = strlen( Str );
  char ch = *Str;
  
     while( i < length )
    { 
         if( ch >= 48 && ch <= 57 )                      
        {                                            /* If the character in the string being read is integer , we find its value by converting it into integer and push it onto the stack */ 
          value = StringToNum( Str , &i );
          stack_push( S , value );
          i += 1;
        }    
         else
        { 
             if( ch == 45 )                         /* If the character being read is '-' */
            { 
                 if( i < length - 2 )               /* And if the '-' read is not at the last position in the string */
                {
                     if( *( Str + i + 1 ) >= 48 && *( Str + i + 1 ) <= 57 )    /* If the character next to '-' is an integer , then that means we are reading a negative number and not '-' operator */
                    { 
                      i += 1;
                      value = -1 * StringToNum( Str , &i );        /* Multiplied with '-1' to get the negative value of that number */  
                      stack_push( S , value );
                      i += 1;                      
                    }
                     else
                    { 
                      stack_push( S , Evaluate_Value( S , ch ) );  /* If not , we are reading a '-' operator and so we calculate its value w.r.t top two operators and push it onto the stack */ 
                      i += 2;
                    }  
                } 
                 else
                { 
                  stack_push( S , Evaluate_Value( S , ch ) );     /* Same as above. That is if '-' is at last position of string , that means it is definitely an operator and not a negative integer */
                  i += 2;
                }  
            } 
             else
            { 
              stack_push( S , Evaluate_Value( S , ch ) );     /* If it is any other operator , we just calculate the value w.r.t top 2 operators and returnn it onto the stack */
              i += 2;
            }  
                  
        }
        
      ch = *( Str + i );  
    }    
        
  return stack_pop( S );  
} 

 /* Function to convert the characters into numbers */

 long long int StringToNum( char *Str , int *x )
{
  long long int value = 0;
  int i = *x;
  
     while( *( Str + i ) != 32 )                  // If the next characater being read is space that means , we terminate reading 
    {
      value = value * 10 + *( Str + i ) - 48;     // Cacluating its decimal equivalent - 48( ASCII value of zero( 0 ) )*/ 
      i++;
    } 
    
  *x = i;  
      
  return value;     
} 

 /* Function to evaluate the value of top two elements in the stack with respective to the operation */
 
 long long int Evaluate_Value( Stack S , char ch )
{
  long long int op1 , op2;
  op1 = stack_pop( S );
  op2 = stack_pop( S );
  
     if( ch == 43 )
      return( op2 + op1 );         /* Evaluating according to the nature of the operator */   
     else if( ch == 45 )
      return( op2 - op1 );
     else if( ch == 42 )
      return( op2 * op1 );
     else if( ch == 47 )
      return( op2 / op1 );
     else if( ch == 37 )
      return( op2 % op1 );
     else if( ch == 38 )
      return( op2 & op1 );
     else if( ch == 94 )
      return( op2 ^ op1 );
     else
      return( op2 | op1 );      
      
  return 0;    
} 











