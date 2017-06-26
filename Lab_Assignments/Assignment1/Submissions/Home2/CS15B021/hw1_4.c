
 #include<stdio.h>

 int main( void )
{
  int i = 0 , C1[26] = { 0 } , C2[26] = { 0 };
  char S1[101] , S2[101];

  scanf( "%s%s" , S1 , S2 );

     while( S1[i] != '\0' )
    {
      C1[ S1[i] - 97 ]++;
      i += 1; 
    }

  i = 0;
 
     while( S2[i] != '\0' )
    {
      C2[ S2[i] - 97 ]++;
      i += 1; 
    }

     for( i = 0 ; i < 26 ; i++ )
    {
       if( C1[i] != C2[i] )
        break;        
    } 

     if( i == 26 )
      printf( "1\n" );
     else
      printf( "0\n" );

  return 0;  
}
