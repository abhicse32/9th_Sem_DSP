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

   L = (list)malloc(sizeof(node));
   L -> x = L -> y = 0;
   L -> nextx = L -> nexty = NULL;

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

void printList ( list L, int flag )
{
  	node* n1;
	node* n2;
	n1 = L;
	n2 = L;
	n1 = n1 -> nextx;
	n2 = n2 -> nexty;
	if(flag ==0)
	{	
  		while(n1 -> nextx != NULL)
  		{
    			printf( "(%d,%d) ",n1 -> x, n1 -> y);
			n1 = n1 -> nextx;
  		}
	}
	else
	{
  		while(n2 -> nexty != NULL)
  		{
    			printf( "(%d,%d) ",n2 -> x,n2 -> y);
			n2 = n2 -> nexty;
  		}
	}
}

void bubbleSortX ( list L )
{
	int temp;
	node* current;
	current = L ;
	while(current -> nextx -> nextx != NULL)
	{
		current = current -> nextx;
		while(current -> nextx != NULL)
		{
			if((current -> x) > ((current -> nextx) -> x))
			{
				temp = current -> x; 
				current -> x = current -> nextx -> x;
				current -> nextx -> x = temp;
			}
			current = current -> nextx;
		}
	}
}

void bubbleSortY ( list L )
{
   int temp;
	node* current;
	current = L;
	while(current -> nexty -> nexty != NULL)
	{
		current = current -> nexty;
		while(current -> nexty != NULL)
		{
			if((current -> y) > ((current -> nexty) -> y))
			{
				temp = current -> y;
				current -> y = current -> nexty -> y;
				current -> nexty -> y = temp;
			}
			current = current -> nexty;
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
