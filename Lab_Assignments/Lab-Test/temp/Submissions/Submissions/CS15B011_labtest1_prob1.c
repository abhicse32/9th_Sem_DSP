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
	node *n;
	n = (node *)malloc(sizeof(node));
	if(flag == 0)
	{
		n = L->nextx;
		while(n != NULL)
		{
			printf("(%d,%d) ",n->x,n->y);
			n = n->nextx;
		}
	}
	if(flag == 1)
	{
		n = L->nexty;
		while(n != NULL)
		{
			printf("(%d,%d) ",n->x,n->y);
			n = n->nexty;
		}
	}
}

void bubbleSortX ( list L )
{
   // Write C-code Here
	int len=0,i;
	node *n,*m;
	n = (node *)malloc(sizeof(node));
	m = (node *)malloc(sizeof(node));
	n = L ;
	while(n != NULL)
	{
		n = n->nextx;
		len++;
	}
	len--;
	n = L;
	for(i = 0; i < len; i++)
	{
		while(n->nextx->nextx != NULL)
		{
			if((n->nextx)->x > (n->nextx->nextx)->x)
			{
				m = n->nextx;
				n->nextx = m->nextx;
				m->nextx = n->nextx->nextx;
				n->nextx->nextx = m;
			}
			n = n->nextx;
		}
		n = L;
	}
	
}

void bubbleSortY ( list L )
{
   // Write C-code Here
	int len=0,i;
	node *n,*m;
	n = (node *)malloc(sizeof(node));
	m = (node *)malloc(sizeof(node));
	n = L ;
	while(n != NULL)
	{
		n = n->nexty;
		len++;
	}
	len--;
	n = L;
	for(i = 0; i < len; i++)
	{
		while(n->nexty->nexty != NULL)
		{
			if((n->nexty)->y > (n->nexty->nexty)->y)
			{
				m = n->nexty;
				n->nexty = m->nexty;
				m->nexty = n->nexty->nexty;
				n->nexty->nexty = m;
			}
			n = n->nexty;
		}
		n = L;
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
