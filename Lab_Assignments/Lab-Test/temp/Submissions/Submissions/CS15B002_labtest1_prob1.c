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
	if( flag == 0)
	{
		node* c = L->nextx;
		while(c!=NULL)
		{
			printf("(%d,%d)\t",c->x,c->y);
			c = c->nextx;
		}
	}
	else if(flag == 1)
	{
		node* c = L->nexty;
		while(c!=NULL)
		{
			printf("(%d,%d)\t",c->x,c->y);
			c = c->nexty;
		}
	}
}

void bubbleSortX ( list L )
{
   // Write C-code Here
	int i,j;
	node* a = L->nextx;node* a1 = L->nextx;node* u =L;
	node* min = (node *)malloc(sizeof(node));node* d = L;
	while( a != NULL)
	{
		
		int p,q;
		node* b = a;min =a;
		p = a->x; q = b->x;
		while(b != NULL)
		{
			q = b->x;
			if(q<p) 
			{				
				min = b;
				p = q;
			} 
			b = b->nextx;
		}	
		node* a1=a;
		while(a1->nextx->nextx != min->nextx)
		a->nextx = min->nextx;
		d->nextx = min;
		min->nextx = a->nextx; 
		a = a->nextx;
		d = d->nextx;
	}
}	

void bubbleSortY ( list L )
{
 int i,j;
	node* a = L->nexty;node* a1 = L->nexty;node* u =L;
	node* min = (node *)malloc(sizeof(node));node* d = L;
	while( a != NULL)
	{
		
		int p,q;
		node* b = a;min =a;
		p = a->y; q = b->y;
		while(b != NULL)
		{
			q = b->y;
			if(q<p) 
			{				
				min = b;
				p = q;
			} 
			b = b->nexty;
		}	
		a->nexty = min->nexty;
		d->nexty = min;
		min->nexty = a->nexty; 
		a = a->nexty;
		d = d->nexty;
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
