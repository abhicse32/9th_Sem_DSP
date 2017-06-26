
 #include<stdio.h>
 
 int main( void )
{
  char S1[101] , S2[101];
  int C1[26] = { 0 } , C2[26] = { 0 };      // Initializing a '26'[a...z] numbered array to find out the number of occurences of each letter in the string...
  int i = 0;
  scanf( "%s%s" , S1 , S2 );
  
     while( *( S1 + i ) )
    { 
      ( *( C1 + *( S1 + i ) - 97 ) )++;    // Finding out the number of occurences of each letter in string 1...
      i++;
    }
     
  i = 0;
      
     while( *( S2 + i ) )
    {   
      ( *( C2 + *( S2 + i ) - 97 ) )++;   // Finding out the number of occurences of each letter in string 2...
      i++;
    }  
    
     for( i = 0 ; i < 26 ; i++ )
    {
         if( *( C1 + i ) != *( C2 + i ) )  // If the number of occurences in both the strings are same , then the strings are anagrams...
          break;
    } 
    
     if( i == 26 )
      printf( "%d\n" , 1 );
     else
      printf( "%d\n" , 0 );
      
  return 0;       
} 
