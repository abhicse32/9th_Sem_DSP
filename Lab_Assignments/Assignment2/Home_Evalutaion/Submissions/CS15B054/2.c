
 /* Solving N-Queens Problem by Back-Tracking Method - Using Recursion */

 #include<stdio.h>
 
 void N_Queens1( int *A , int N );
 void N_Queens2( int *B , int N ); 
 _Bool Possible_Position( int *A , int N , int Position , int column );
 void Print_Positions( int *A , int N );
 
 int count = 0 , check = 0;       /* count - Variable to keep count of no. of possible configurations */
                                  /* check - Variable to check if we checked all possible configurations possible and there no longer exist any to check and so we stop when it becomes '1' */
 int main( void )
{
  int N , i;
  scanf( "%d" , &N );
  
     if( N == 1 )                /* If 'N == 1' , there is '1' possibility and so we return */
    {
      printf( "1\n1\n" );
      return 0;
    }
  
  int A[N];                     /* Array to keep track of possible configurations for the N-Queen system */
  
     for( i = 0 ; i < N ; i++ )
      *( A + i ) = -1;
      
  N_Queens1( A , N );   
    
  printf( "%d\n" , count );   
  
  return 0;
} 

 /* Function to find the first possible configuration for the placement of N-Queens */

 void N_Queens1( int *A , int N  )
{
  int i , j = 0;
  _Bool result; 
  
     for( i = 0 ; i < N ; i++ )                            /* Starts from first row and column by using Back-Tracking Method to find the first possibke configuration */
    {     
         for( ; j < N ; j++ )
        {
          result = Possible_Position( A , N , j , i );
          
             if( result )
              break;
        }
        
         if( j == N )
        {
             if( i )
            { 
              i -= 2;
              j = *( A + i + 1 ) + 1;
            }
             else
            {  
              result = 0;
              break;
            }   
        } 
         else
          j = 0;             
    }   
    
     if( i == N )
    {
      count++;
      result = 1;
    }   
    
     if( result )                  /* If there exits such confuguration , now we check from the last column if there exists any other configuration and so on recursively */
    {   
      Print_Positions( A , N );    /* Else , there doesn't exist one such configuration and so we return */ 
      N_Queens2( A , N );
    }  
} 

 /* Function that checks whether a particular 'row' in particular 'column' is suitable for the QUEEN to be placed in that cell */ 

 _Bool Possible_Position( int *A , int N , int Position , int column )
{
  int i , Temp1 , Temp2 , x;
  
     for( i = 0 ; i < column ; i++ )
    {
      x = *( A + i );
      Temp1 = Position - x;     /* Temp1 - Variable that checks if there already exists a QUEEN in the row of the cell being checked for the placcement of QUEEN */  
      
         if( !Temp1 )
          break;
         else
        {
          Temp2 = column - i;                                  
          
             if( Temp1 == Temp2 || Temp1 * -1 == Temp2 )   /* Checks if the current Position being checked for the placement of queen is in diagonal to any other already placed QUEENS */
              break;
        }   
    } 
    
     if( i == column )
    { 
      *( A + column ) = Position;
      return 1;
    }  
     else
    {
         if( !column && Position == N )
          check = 1;
           
      return 0;
    }  
} 

 /* Function that prints the positions of N-Queens structure */
 
 void Print_Positions( int *A , int N )
{
  int i;
  
     for( i = 0 ; i < N ; i++ )
      printf( "%d " , *( A + i ) );
      
  puts( "" );      
} 

 /* After finding the first configuration , we check from back if there are more configurations possible */ 

 void N_Queens2( int *B , int N )
{
   int i , j = *( B + N - 2 ) + 1; 
   _Bool result;
   
      for( i = N - 2 ; i >= 0 ; i-- )
     {
          for( ; j < N ; j++ )
         {
           result = Possible_Position( B , N , j , i );
           
              if( result ) 
               break;
         } 
         
          if( j != N )
         { 
              if( i + 1 == N )
             {
               count++;
               result = 1;
               break;
             }
              else
               i += 2;
                 
           j = 0;    
         }
          else
         {
              if( i >= 1 )
               j = *( B + i - 1 ) + 1;
              else
             {
               check = 1;
               result = 0;
               break; 
             }     
         }   
     }  
     
      if( result )
     {
       Print_Positions( B , N );
       
          if( check )                
           return; 
          else                          /* If we find one more such configuration , we again analyse it from backward increasing the row number of already placed QUEEN */
           N_Queens2( B , N );          /* Calling the function Recursively until all the possibilities are checked */
     }  
}

 /* Explanation :
 
  =>  We start from the '0'th column...
  =>  We try all the rows in the current column. If queen can be placed in some row , we store 
      that row in array 'A' and check if placing the queen here gives a configuration...   
  =>  If placing the queen there doesn't give a connfiguration , we again come backward and
      try other rows in that column...
 */    
     


































 
