s
 // Newton's Method of finding Square Root...
 
 #include<stdio.h>

 double Guess_Number( long int N );
 double Newtons_Method( double x , long int N );
  
 int main( void )
{
  long int N;
  double Sq_Root , Guess;
  scanf( "%ld" , &N );
  
  Guess = Guess_Number( N );
  Sq_Root = Newtons_Method( Guess , N );
  
  printf( "%0.15f\n" , Sq_Root );
  
  return 0;
} 

 // Function to guess an approximate value of Square root of 'N'...
 
 double Guess_Number( long int N )
{
  long int i = 2 , Temp = 1;
  
     while( Temp < N )
    { 
      Temp = i * i;
      i++;
    }  
       
  return i;     
} 

 // Function for finding a better approximation of the Square root of 'N' using 'Guess'...
 
 double Newtons_Method( double x , long int N )
{
  double Sq_Root;
  int i;
  
     for( i = 1 ; i <= 15 ; i++ )
    {
      Sq_Root = ( x + ( N / x ) ) / 2;
      x = Sq_Root;
    } 
    
  return Sq_Root;  
} 
