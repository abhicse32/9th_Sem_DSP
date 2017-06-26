
 #include<stdio.h>

 int main( void )
{
  int n , Max , Min , Temp_Max , Temp_Min , i;
  scanf( "%d" , &n );
 
  int A[n];
  
     for( i = 0 ; i < n ; i++ )
      scanf( "%d" , A + i );
 
     if( n == 1 )
      Max = Min = *A;
     else
    { 
         if( *A > *( A + 1 ) )
        { 
          Max = *A;
          Min = *( A + 1 );
        }
         else
        {
          Max = *( A + 1 );
          Min = *A;
        }

         for( i = 2 ; i < n ; i++ )
        {
             if( i + 1 < n )
            { 
                 if( *( A + i ) > *( A + i + 1 ) )
                {
                  Temp_Max = *( A + i );
                  Temp_Min = *( A + i + 1 );
                }
                 else
                {
                  Temp_Max = *( A + i + 1 );
                  Temp_Min = *( A + i );  
                }
               
                 if( Temp_Max > Max )
                  Max = Temp_Max;
                 if( Temp_Min < Min )
                  Min = Temp_Min;
            } 
             else
            {
                 if( *( A + i ) > Max )
                  Max = *( A + i );
                 if( *( A + i ) < Min )
                  Min = *( A + i );
            }  
          
          i++;
        } 
    }
     
  printf( "%d %d\n" , Min , Max );

  return 0;   
}















