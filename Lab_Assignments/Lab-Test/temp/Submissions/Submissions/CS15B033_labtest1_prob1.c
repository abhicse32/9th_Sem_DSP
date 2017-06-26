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
   {
		node *n = L->nexty;
		while( n != NULL )
		{
			printf("(%d,%d)", n->x, n->y);
			n = n->nexty;
		}
	}
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   node *n2 = L;
   while( n2->nextx != NULL )
   {
   		node *n3 = n2->nextx;
		while( n3->nextx != NULL )
		{
			if( n2->nextx->x > n2->nextx->nextx->x )
			{
				list temp1x = n2->nextx->nextx;
				n2->nextx->nextx = n2->nextx->nextx->nextx;
				
				list temp1y = n2->nextx->nexty;
				n2->nextx->nexty = n2->nextx->nextx->nexty;
				//n2->nexty = temp1y;
				
				n2->nextx = temp1x;
				n2->nexty = temp1y;
				
				n2->nextx->nextx = n2->nextx->nexty = n3;
				
			}
			n3 = n3->nextx;
		}
		n2 = n2->nextx;
	}
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   node *n2 = L;
   while( n2->nexty != NULL )
   {
		node *n3 = n2->nexty;
		while( n3->nexty != NULL )
		{
			if( n2->nexty->y > n2->nexty->nexty->y )
			{
				list temp1x = n2->nexty->nextx;
				n2->nexty->nextx = n2->nexty->nexty->nextx;
				
				list temp1y = n2->nexty->nexty;
				n2->nexty->nexty = n2->nexty->nexty->nexty;
				//n2->nexty = temp1y;
				
				n2->nextx = temp1x;
				n2->nexty = temp1y;
				
				n2->nexty->nextx = n2->nexty->nexty = n3;}
		n3 = n3->nexty;
		}
		n2 = n2->nexty;
	}
}

int main ()
{
   list L;

   L = genRandList(N);
   printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);fflush(stdout);
   printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);fflush(stdout);
   bubbleSortX(L);
   bubbleSortY(L);
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return(0);
}
