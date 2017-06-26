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
	int i, j;

	if(flag == 0)
	{
		node* a = L->nextx;

		for(i=0; i<N; i++)
		{
			printf("(%d,%d) ", a->x, a->y);
			if(a->nextx == NULL) break;
			a = a->nextx;
		}
	}

	else if(flag == 1)
	{
		node* b = L->nexty;

		for(j=0; j<N; j++)
		{
			printf("(%d,%d) ", b->x, b->y);
			if(b->nexty == NULL) break;
			b = b->nexty;
		}
	}

}

void bubbleSortX ( list L )
{
   // Write C-code Here
	node* a, *b;
	int i, j;


	for(i=N-1; i>0; i--)
	{
		a = L;
		j = 0;

		while(i != j)
			{
				if(a->nextx->x > a->nextx->nextx->x)
				{
					b = a->nextx;
					a->nextx = a->nextx->nextx;
					b->nextx = a->nextx->nextx;  
					a->nextx->nextx = b;
				}
			
				a = a->nextx;
				j++;
			}
	}
}

void bubbleSortY ( list L )
{
   // Write C-code Here
	node* a, *b;
	int i, j;

	for(i=N-1; i>0; i--)
	{
		a = L;
		j = 0;

		while(i != j)
			{
				if(a->nexty->y > a->nexty->nexty->y)
				{
					b = a->nexty;
					a->nexty = a->nexty->nexty;
					b->nexty = a->nexty->nexty;  
					a->nexty->nexty = b;
				}
			
				a = a->nexty;
				j++;
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
