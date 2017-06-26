
 #include<stdio.h>
 
 int main( void )
{
  long int N , i;
  scanf( "%ld" , &N );
  long long int A[N] , Max = 0 , Second_Max = 0;
  
     for( i = 0 ; i < N  ; i++ ) 
      scanf( "%lld" , A + i );
      
     if( *A > *( A + 1 ) )
    {
      Max = *A;
      Second_Max = *( A + 1 );
    }
     else
    {
      Max = *( A + 1 );
      Second_Max = *A;
    }       
    
     for( i = 2 ; i < N ; i++ )
    {
         if( *( A + i ) > Max )
        { 
          Second_Max = Max;
          Max = *( A + i );
        }
         else
        {
             if( *( A + i ) > Second_Max )
              Second_Max = *( A + i );
        }   
    }  
    
  printf( "%lld %lld\n" , Max , Second_Max );   
      
  return 0;    
} 
