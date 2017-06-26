
 #include<stdio.h>
 
 void Permutations( int *A , int n , int start );
 void Swap( int *a , int *b );
 
 int main( void )
{
  int n , i;
  scanf( "%d" , &n );
  int A[n];
  
     for( i = 0 ; i < n ; i++ )
      scanf( "%d" , A + i );
      
  Permutations( A , n , 0 );
  puts( "" );
      
  return 0;    
} 

 void Swap( int *a , int *b )             // The swapping of two elements must reflect in the function , Hence thery are passed as pointers
{
  int Temp = *a;
  *a = *b;
  *b = Temp;
} 

 /* Function to print all the permutations of the array */ 

 void Permutations( int *A , int n , int start )
{
  int j;

     if( start == n )                       /* If start == n => the array is full with new permutation and so it is printed */
    {
         for( j = 0 ; j < n ; j++ )
          printf( "%d" , *( A + j ) );
          
      printf( " " );    
      return;
    }  
     else
    {
         for( j = start ; j < n ; j++ )       
        {
          Swap( A + start , A + j );            /* Here there are 2 swap functions so that net effect is nullified and we could keep track of array without any repetitions */
          Permutations( A , n , start + 1 );    /* Recursively calling the function to find the permutations in the array with one element less than the original array */
          Swap( A + j , A + start );
        }  
    }  
} 
