#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define WRT_X 0
#define WRT_Y 1

typedef struct _node {
   int x;
   int y;
   struct _node *nextx;
   struct _node *nexty;
} node;

typedef node *list;

list genRandList ( int n )
{
   list L;
   node *p, *q;
   int i;

   /* Create dummy header */
   L = (list)malloc(sizeof(node));
   L -> x = L -> y = 0;
   L -> nextx = L -> nexty = NULL;

   /* Insert random elements at the end of the list */
   srand((unsigned int)time(NULL));
   p = L;
   for (i=0; i<n; ++i) {
      q = (node *)malloc(sizeof(node));
      q -> x = 1000 + rand() % 9000;
      q -> y = 1000 + rand() % 9000;
      q -> nextx = q -> nexty = NULL;
      p -> nextx = p -> nexty = q;
      p = q;
   }

   return L;
}

// COMPLETE THE FOLLOWING (printList, bubbleSortX and bubbleSortY) FUNCTIONS
void printList ( list L, int flag )
{
  list Temp;

     if( flag )
      Temp = L->nexty;
     else
      Temp = L->nextx;

     while( Temp )
    {
      printf( "(%d,%d) " , Temp->x , Temp->y );

         if( flag )
          Temp = Temp->nexty;
         else
          Temp = Temp->nextx;
    }   
}

void bubbleSortX ( list L )
{
  list Temp1 = L->nextx , Temp2;
  int i , j; 

     for( i = 1 ; i <= N - 1 ; i++ )
    {
      Temp1 = L->nextx;
      Temp2 = L;     

         for( j = 1 ; j <= N - i ; j++ )
        {
             if( Temp1->nextx->x < Temp1->x )
            {
              Temp2->nextx = Temp1->nextx;
              Temp1->nextx = Temp1->nextx->nextx;
              Temp2->nextx->nextx = Temp1;
              Temp2 = Temp2->nextx; 
            } 
             else
            {
              Temp2 = Temp1;
              Temp1 = Temp1->nextx;
            }       
        }
    }
}

void bubbleSortY ( list L )
{
  list Temp1 = L->nexty , Temp2;
  int i , j;

     for( i = 1 ; i <= N - 1 ; i++ )
    {
      Temp1 = L->nexty;
      Temp2 = L;

         for( j = 1 ; j <= N - i ; j++ )
        {
             if( Temp1->nexty->y < Temp1->y )
            {
              Temp2->nexty = Temp1->nexty;
              Temp1->nexty = Temp1->nexty->nexty;
              Temp2->nexty->nexty = Temp1; 
              Temp2 = Temp2->nexty;
            }     
             else
            {
              Temp2 = Temp1; 
              Temp1 = Temp1->nexty;
            }
        }
    }
}

int main ()
{
   list L;

   L = genRandList(N);
   printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);
   bubbleSortX(L);
   bubbleSortY(L);
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return(0);
}
