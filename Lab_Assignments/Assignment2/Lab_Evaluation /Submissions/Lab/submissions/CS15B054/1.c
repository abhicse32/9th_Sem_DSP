
 #include<stdio.h>
 #include<time.h>
 #include <sys/time.h>

 long long int Iterative_Fibanocci( int n );
 long long int Recursive_Fibanocci( int n );

 int main( void )
{
  int n , i;
  long long int F;
  FILE *f;
  struct timeval t1 , r1 , t2 , r2;           /* Varibles to calculate time required for the calculation of Fibanocci numbers */ 
  scanf( "%d" , &n );

     for( i = 1 ; i <= n ; i++ )
    {
      F = Iterative_Fibanocci( i );       
      printf( "%lld " , F );  
    }  

  puts( "" );
  
     for( i = 1 ; i <= n ; i++ )
    {
      F = Iterative_Fibanocci( i );
      printf( "%lld " , F );  
    }
 
  puts( "" );
  f = fopen( "output.csv" , "w" );       /* Opening the Output file in 'write' mode */

     for( i = 1 ; i <= 20 ; i++ )
    {
      gettimeofday( &t1 , NULL );       /* Calculating the time taken by Iterative Function */
      Iterative_Fibanocci( i ); 
      gettimeofday( &r1 , NULL );

      gettimeofday( &t2 , NULL );       /* Calculating the time taken by Recursive FUnction */ 
      Recursive_Fibanocci( i );
      gettimeofday( &r2 , NULL );

      fprintf( f , "%.10lf,%.10lf\n" , ( double )( ( r1.tv_sec - t1.tv_sec )*1000000 + ( r1.tv_usec - t1.tv_usec ) ) , ( double )( ( r2.tv_sec - t2.tv_sec )*1000000 + ( r2.tv_usec - t2.tv_usec ) ) );  
    }

  fclose( f );        /* CLosing the file */  

  return 0;
}

 long long int Iterative_Fibanocci( int n )
{
  long long int F = 1 , Temp1 = 0 , Temp2 , i;

     for( i = 1 ; i < n ; i++ )
    {
      Temp2 = F + Temp1;
      Temp1 = F;
      F = Temp2;  
    } 

  return F;
} 

 long long int Recursive_Fibanocci( int n )       
{
     if( n == 1 || !n )       /* Base Case - Return '1' if  n == 0 or n == 1 since F(0) = F(1) = 1 */
      return 1;
     else
      return Recursive_Fibanocci( n - 1 ) + Recursive_Fibanocci( n - 2 ); 
}














 
