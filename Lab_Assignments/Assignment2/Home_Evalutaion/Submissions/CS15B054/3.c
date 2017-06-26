
 #include<stdio.h>
 
 void TOH( int D , char Source , char Destaination , char Auxilary );               /* At the Start  =>  Source - A     Destination - C     AUxilary - B  */
 void Move( char Source , char Destination );
 
 int c1 , c2 = 0  , c3 = 0;       /* c1 , c2 , c3 - Keeps count of number of disks in each of the three pegs A , B and C respectively */ 
 
 int main( void )
{
  int N;
  scanf( "%d" , &N );
  
  c1 = N;
  TOH( N , 'A' , 'C' , 'B' );
    
  return 0;  
}  

 /* Recursive function to solve TOH */

 void TOH( int D , char Source , char Destination , char Auxilary )
{
     if( D == 1 )                               
    {                                         /* Base-Case -  If the no. of disks in a peg is one , we move that directly from Source peg to Destination peg */ 
      Move( Source , Destination );     
      return;
    } 
     else                                                    
    {                                                      //  Recursively calling the movement of top 'n - 1' disks from source peg to Auxilary peg so that the bottom most peg can be placed in  
      TOH( D - 1 , Source , Auxilary , Destination );      //  desitination peg...
      Move( Source , Destination );
      TOH( D - 1 , Auxilary , Destination , Source );      /*  Now moving those 'n - 1' pegs from Auxilary peg to the Destination peg */ 
    } 
} 
 
 /* Function that changes the count of disks in pegs when a disk is moved from one peg to another */
 /* Also prints the movements of disks */
  
 void Move( char Source , char Destination )
{
     if( Source == 'A' )                      // Code to find which the Source and Destination pegs are and modify the counts as the disks are moved */
    { 
      c1--;
      
         if( Destination == 'B' )
          c2++;
         else
          c3++;    
    }     
     else
    { 
         if( Source == 'B' )
        {
          c2--;
          
             if( Destination == 'A' )
              c1++;
             else
              c3++; 
        }
         else
        {
          c3--;
          
             if( Destination == 'A' )
              c1++;
             else
              c2++; 
        }    
    } 
    
  printf( "%c -> %c %d %d %d\n" , Source , Destination , c1 , c2 , c3 );      /* Printing the movement of disk from one peg to another */
} 





















  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
