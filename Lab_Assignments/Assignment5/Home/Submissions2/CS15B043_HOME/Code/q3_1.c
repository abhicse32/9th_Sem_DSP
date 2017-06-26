
 #include<stdio.h>
 #include<stdlib.h>
 #include<string.h>
 #include "List.h"
 #include "stack.h" 
 
 typedef stack *Stack;
 
 void PostInFix( Stack S , char *Str );
 char Char_Equivalent( int value );
 int Num_Equivalent( char ch );
 
 int main( void )
{
  Stack S = stack_new();
  char Str[1001];
  
  fgets( Str , 1000 , stdin );       /* We read the string using 'fgets' function since it contains spaces */
  PostInFix( S , Str );
  
  free( S->top );
  free( S );
  
  return 0; 
} 

 /* Function to convert the given Infix form into PostFix Form */

 void PostInFix( Stack S , char *Str )
{
  char ch , Temp;
  int i = 0 , l = strlen( Str );     /* Length of the string using taken through 'fgets' function is 1 more than its length - Hence the condition 'l - 1' */
  
     while( i < l - 1 )
    {
      ch = *( Str + i );
      
         if( ( ch >= 65 && ch <= 90 ) || ( ch >= 97 && ch <= 122 ) || ( ch >= 48 && ch <= 57 ) )
        { 
          Temp = ch;                                 // If the character read is not an operator but some variable , the we print it until a space is found or until it exceeds length of string */
           
             while( Temp != 32 && i < l - 1 )
            {     
              printf( "%c" , Temp );
              i++;
              Temp = *( Str + i );
            }  
          
          printf( " " );
          i++;  
        }  
         else
        {
             if( ch == 40 )                 // 40 - ASCII Value of '('... If it is read , it is just pushed onto the stack */
              stack_push( S , Num_Equivalent( ch ) );
             else
            {
                 if( ch == 41 )            // 41 - ASCII value of ')' 
                {
                  Temp = Char_Equivalent( stack_pop( S ) );
                  
                     while( Temp != 40 )
                    {
                      printf( "%c " , Temp );
                      Temp = Char_Equivalent( stack_pop( S ) );
                    }  
                }
                 else
                {
                     if( ch == 43 || ch == 45 )           /* 43 , 45 - ACSII value of '+' , '-' respectively */
                    {            
                         while( 1 )
                        { 
                             if( !stack_is_empty( S ) )
                            { 
                              Temp = Char_Equivalent( stack_pop( S ) );
                          
                                 if( Temp == 38 || Temp == 40 || Temp == 94 || Temp == 124 )
                                { 
                                  stack_push( S , Num_Equivalent( Temp ) );
                                  break;
                                }
                                 else
                                  printf( "%c " , Temp );       
                            }            
                             else
                              break;                      
                        }    
                        
                      stack_push( S , Num_Equivalent( ch ) );  
                    } 
                     else
                    {
                         if( ch == 37 || ch == 42 || ch == 47 )              /* 37 , 42 , 47 - ASCII values of '%' , '*' and '/' respectively.  */
                        {
                             while( 1 )
                            { 
                                 if( !stack_is_empty( S ) )
                                { 
                                  Temp = Char_Equivalent( stack_pop( S ) );
                                  
                                     if( Temp == 37 || Temp == 42 || Temp == 47 )
                                      printf( "%c " , Temp );
                                     else
                                    {
                                      stack_push( S , Num_Equivalent( Temp ) );
                                      break;  
                                    }     
                                }
                                 else
                                  break;
                            } 
                            
                          stack_push( S , Num_Equivalent( ch ) );      
                        }
                         else
                        {
                             if( ch == 38 )                   /* 38 - ACSII value of '&' - BITWISE And */
                            {
                                 while( 1 )
                                {
                                     if( !stack_is_empty( S ) )
                                    {
                                      Temp = Char_Equivalent( stack_pop( S ) );
                                      
                                         if( Temp == 40 || Temp == 94 || Temp == 124 )
                                        {
                                          stack_push( S , Num_Equivalent( Temp ) );
                                          break;
                                        } 
                                        else
                                         printf( "%c " , Temp );
                                    } 
                                     else
                                      break;
                                } 
                                
                              stack_push( S , Num_Equivalent( ch ) );  
                            }  
                             else
                            {
                                 if( ch == 94 )                /* 94 - ASCII value of '^' - BITWISE Xor */
                                {
                                     while( 1 )
                                    {
                                         if( !stack_is_empty( S ) )
                                        {
                                          Temp = Char_Equivalent( stack_pop( S ) );
                                          
                                             if( Temp == 40 || Temp == 124 )
                                            {
                                              stack_push( S , Num_Equivalent( Temp ) );
                                              break;
                                            } 
                                             else
                                              printf( "%c " , Temp ); 
                                        } 
                                         else
                                          break;
                                    } 
                                    
                                  stack_push( S , Num_Equivalent( ch ) );  
                                } 
                                 else
                                {
                                     while( 1 )
                                    {                                       /* If all the above statements are false , then the operator is '|' - Opeartow with least precedence */ 
                                         if( !stack_is_empty( S ) )
                                        { 
                                          Temp = Char_Equivalent( stack_pop( S ) );
                                      
                                             if( Temp == 40 )
                                            { 
                                              stack_push( S , Num_Equivalent( Temp ) );
                                              break;
                                            }  
                                             else
                                              printf( "%c " , Temp ); 
                                        }      
                                         else
                                          break;
                                    }   
                                    
                                  stack_push( S , Num_Equivalent( ch ) );  
                                }
                            } 
                        }       
                    } 
                }  
            } 
            
          i += 2;  
        }    
    }   
    
     while( !stack_is_empty( S ) )                      /* After all the characters in the string are processed , we print the values in the stack until it becomes empty */
    {
      Temp = Char_Equivalent( stack_pop( S ) );
      printf( "%c " , Temp );
    } 
      
  puts( "" );    
} 
 
 /* Function to find the ASCII value of an operator */

 int Num_Equivalent( char ch )
{
  int Temp = ch;
  
  return Temp;
} 

 /* Function to find the operator with respective to its ASCII value */

 char Char_Equivalent( int value )
{
  char ch = value;
  
  return ch;  
} 






































