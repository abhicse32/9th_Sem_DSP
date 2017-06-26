 #include<stdio.h>
 
 int main( void )
{
  int i , N;
  float x = 1;
  scanf( "%d" , &N );

  for( i = 1 ; i * i < N ; i++ )
   x = i;

  for( i = 0 ; i < 15 ; i++ )
   x = ( x + ( N / x ) ) / 2;

  printf( "%0.15f\n" , x );

  return 0; 
}
