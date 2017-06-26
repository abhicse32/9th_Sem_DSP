
 #include<stdio.h>
 #include<math.h>

 struct Complex
{
  float real;
  float imaginary;
};
 
 void Addition( struct Complex a , struct Complex b );
 void Subtraction( struct Complex a , struct Complex b );
 void Multiplication( struct Complex a , struct Complex b );
 void Division( struct Complex a , struct Complex b );
 void Modulus( struct Complex a , struct Complex b ); 

 int main( void )
{
  struct Complex a , b;
  int operation;

  scanf( "%f%f" , &a.real , &a.imaginary ); 
  scanf( "%f%f" , &b.real , &b.imaginary );
  scanf( "%d" , &operation );

     while( operation != 0 && operation != -1 )
    { 
         switch( operation )
        {
             case 1:
              Addition( a , b );
              scanf( "%f%f" , &a.real , &a.imaginary ); 
              scanf( "%f%f" , &b.real , &b.imaginary );
              scanf( "%d" , &operation );
              break;
             case 2:
              Subtraction( a , b );
              scanf( "%f%f" , &a.real , &a.imaginary ); 
              scanf( "%f%f" , &b.real , &b.imaginary );  
              scanf( "%d" , &operation );
              break;
             case 3:
              Multiplication( a , b );
              scanf( "%f%f" , &a.real , &a.imaginary ); 
              scanf( "%f%f" , &b.real , &b.imaginary );
              scanf( "%d" , &operation );  
              break;       
             case 4:
              Division( a , b );
              scanf( "%f%f" , &a.real , &a.imaginary ); 
              scanf( "%f%f" , &b.real , &b.imaginary );
              scanf( "%d" , &operation );   
              break;
             case 5:
              Modulus( a , b );
              scanf( "%f%f" , &a.real , &a.imaginary ); 
              scanf( "%f%f" , &b.real , &b.imaginary );
              scanf( "%d" , &operation );  
             break;
            default:
             break;
       }
  }   
  
  return 0;
}

 void Addition( struct Complex a , struct Complex b )
{
  float r , i;
 
  r = a.real + b.real;
  i = a.imaginary + b.imaginary;

     if( i > 0 )
      printf( "%0.6f + %0.6fi\n" , r , i );
     else
    {
      i *= -1;
      printf( "%0.6f - %0.6fi\n" , r , i );
    }
}

  void Subtraction( struct Complex a , struct Complex b )
{
  float r , i;
 
  r = a.real - b.real;
  i = a.imaginary - b.imaginary;

     if( i > 0 )
      printf( "%0.6f + %0.6fi\n" , r , i );
     else
    { 
      i *= -1;
      printf( "%0.6f - %0.6fi\n" , r , i );
    }
}

 void Multiplication( struct Complex a , struct Complex b )
{
  float r , i;

  r = ( a.real * b.real ) - ( a.imaginary * b.imaginary );
  i = ( a.real * b.imaginary ) + ( a.imaginary * b.real );

     if( i > 0 )
      printf( "%0.6f + %0.6fi\n" , r , i );
     else
    {
      i *= -1;
      printf( "%0.6f - %0.6fi\n" , r , i );
    }
}

 void Division( struct Complex a , struct Complex b )
{
  float r , i;

  r = ( ( a.real * b.real ) + ( a.imaginary * b.imaginary ) ) / ( ( b.real * b.real ) + ( b.imaginary * b.imaginary ) );
  i = ( ( a.imaginary * b.real ) - ( a.real * b.imaginary ) ) / ( ( b.real * b.real ) + ( b.imaginary * b.imaginary ) );

     if( i > 0 )
      printf( "%0.6f + %0.6fi\n" , r , i );
     else
    {
      i *= -1; 
      printf( "%0.6f - %0.6fi\n" , r , i );
    } 
}
 
 void Modulus( struct Complex a , struct Complex b )
{
  float distance;
  distance = sqrt( ( ( a.real - b.real ) * ( a.real - b.real ) ) + ( ( a.imaginary - b.imaginary ) * ( a.imaginary - b.imaginary ) ) );

  printf( "%0.6f\n" , distance );
}












