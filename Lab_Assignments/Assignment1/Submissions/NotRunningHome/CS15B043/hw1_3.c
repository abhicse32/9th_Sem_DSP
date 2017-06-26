
 #include<stdio.h>
 
 long long int Euclid_Gcd( long long int a , long long int b );
 long long int Max( long long int a , long long int b );
 void Prime_Factors( long long int a , long long int b , long long int gcd );
 _Bool IsPrime( long long int a );
 
 int main( void )
{
  long long int a , b , gcd , Max_Var;
  scanf( "%lld%lld" , &a , &b );
  
  Max_Var = Max( a , b ); 
  
     if( Max_Var == b )
    {
      b = a;
      a = Max_Var;    
    }  
 
  gcd = Euclid_Gcd( a , b );
  Prime_Factors( a , b , gcd );
   
  return 0;
} 

 // Euclid's gcd algorithm to find out the gcd of two numbers...

 long long int Euclid_Gcd( long long int a , long long int b )
{
  long long int r = a % b; 
    
     while( r )
    {
      a = b;
      b = r;
      r = a % b;
    }      
    
  return b;  
} 

 // Function to find out the maximum of two given numbers...

 long long int Max( long long int a , long long int b )
{
     if( a > b )
      return a;
     else
      return b; 
} 

 // Function to find out all the Prime Factors of two given numbers... 

 void Prime_Factors( long long int a , long long int b , long long int gcd )
{
  long long int i;
  _Bool result;
  
     if( !( a % 2 ) && !( b % 2 ) )
      printf( "%d " , 2 );

     for( i = 3 ; i <= gcd ;  )
    {
      result = IsPrime( i );
      
         if( result )
        {
             if( !( a % i ) && !( b % i ) )
              printf( "%lld " , i );
        }
        
      i += 2;     
    }   
    
  puts( "" );  
} 

 // Function to find out if a number is prime or not...

 _Bool IsPrime( long long int a )
{
  long long int i , r;
  
     for( i = 2 ; i <= a / 2 ; i++ )
    {
      r = a % i;
      
         if( !r ) 
          return 0;
    } 
    
  return 1;  
}








































