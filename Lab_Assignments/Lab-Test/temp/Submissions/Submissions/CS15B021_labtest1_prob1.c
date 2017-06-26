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
   // Write C-code Here
   node *p;
   if( flag == 0 ){
      p = L -> nextx;
   }
   else
      p = L -> nexty;
   while( p != NULL ){
      printf( "(%d,%d) ",(p -> x),(p -> y) );
      if( flag == 0 ){
         p = p -> nextx;
      }
      else
         p = p -> nexty;
   }
    printf("\n");  
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   int i, j;
   node *p, *q, *r, *temp;
   p = L -> nextx;
   q = p -> nextx;
   r = L -> nextx;
   int size = 0;
   while( r != NULL ){
      size++;
      r = r -> nextx;
   }
   for( i=0; i<size; i++ ){
      while( q != NULL ){
	if( (p -> x) > (q -> x) ){
	   temp = p;
	   p = q;
	   temp -> nextx = q -> nextx;
	   q -> nextx = temp;
	   p = p -> nextx;
	   q = p -> nextx;
	}
	else{
	   p = q;
	   q = q -> nextx;
	}
      }
   }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   // Write C-code Here
   int i, j;
   node *p, *q, *r, *temp;
   p = L -> nexty;
   q = p -> nexty;
   r = L -> nexty;
   int size = 0;
   while( r != NULL ){
      size++;
      r = r -> nexty;
   }
   for( i=0; i<size; i++ ){
      while( q != NULL ){
	if( (p -> y) > (q -> y) ){
	   temp = p;
	   p = q;
	   temp -> nexty = q -> nexty;
	   q -> nexty = temp;
	   p = p -> nexty;
	   q = p -> nexty;
	}
	else{
	   p = q;
	   q = q -> nexty;
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
