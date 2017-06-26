
 // Calculating the determinant of a Matrix using Minors... 

 #include<stdio.h>
 #include<stdlib.h>
 #include<math.h>
 
 long long int Determinant( long long int *A , int N );      /* As the order of the Matrix is not known previously , Matrix is sent as a pointer to an integer( long long int *A ) */
 
 int main( void )
{
  int N , i , j;
  long long int Det;
  scanf( "%d" , &N );
  
  long long int A[N][N];
  
     for( i = 0 ; i < N ; i++ )
         for( j = 0 ; j < N ; j++ )
          scanf( "%lld" , *( A + i ) + j );
 
  Det = Determinant( A , N );
  printf( "%lld\n" , Det );      
          
  return 0;
}

 // Recursive Function for finding the Determinant of a Matrix

 long long int Determinant( long long int *A , int N )
{
  long long int Det = 0;
  int i , j , k , l;
  
     if( N == 1 )               /* Base-Case : If N == 1 => It is a '1 by 1' matrix and the determinant is matrix itself */          
      Det = *A;
     else
    {                           /* Base-Case : As order of the Matrix reduces to '2' , another call to the function "Determinant" is no longer needed and can be calulated in this way */
         if( N == 2 )            
          Det = ( *A * *( A + 3 ) ) - ( *( A + 1 ) * *( A + 2 ) );
         else                      
        {                                             /* If 'N > 2' , Determinant function is called recursively to compute the value of determinant */
          long long int B[N - 1][N - 1] , *p;
          Det = 0;
          p = B;
          
             for( i = 0 ; i < N ; i++ )       /* To find the determinant of the Matrix using Minors , here i am taking 1st row to calculate the determinant */
            {     
                 for( j = 0 ; j < N - 1 ; j++ )
                {
                  l = 0;
                  
                     for( k = 0 ; k < N - 1 ; )   /* Copying the remaining Matrix into an 'N - 1 by N - 1' matrix leaving the elements in 1st row and the corresponding column */ 
                    {
                          if( l != i )
                         { 
                           *( p + j * ( N - 1 ) + k ) = *( A + ( j + 1 ) * N + l );
                           k++;
                         } 
                         
                      l++;   
                    } 
                }
                
              Det += pow( -1 , i + 2 ) * ( *( A + i ) ) * Determinant( B , N - 1 );     
            }     
        } 
    }  
    
  return Det;       
} 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
