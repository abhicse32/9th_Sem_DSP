
 #include<stdio.h>
 
 int main( void )
{
  long long int N , i = 0;
  int A[10] = { 0 };
  scanf( "%lld" , &N );
  
     while( N )
    { 
      *( A + i ) = N % 16;           // 16( x1 + 16( x2 + 16( x3 + ....) ) ) + xn  => xn is remainder and remaining thing quotient...
      N = N / 16;                    // Repeating this process again gives x(n -1) , x(n - 2) , ... x1...  
      i++;                           // This is repeated until 'N' goes to zero... 
    } 
    
  printf( "0x" );
  
     for( i = 7 ; i >= 0 ; i-- )
    {
         switch( *( A + i ) )
        {
             case 10:
              printf( "a" );
              break;
              
             case 11:
              printf( "b" );
              break;
              
             case 12:
              printf( "c" );
              break;
              
             case 13:
              printf( "d" );
              break;
              
             case 14:
              printf( "e" );
              break;
              
             case 15:
              printf( "f" );
              break;
              
             default:
              printf( "%d" , *( A + i ) );      
        }  
    }  
    
  puts( "" );
  
  return 0;  
} 
