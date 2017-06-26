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
      // q -> x = 1000 + rand() % 9000;
      // q -> y = 1000 + rand() % 9000;
      scanf("%d%d",&(q->x),&(q->y));
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
   
   if (flag==0)
   {
   	node *curr;
   	curr=L->nextx;
   	for (;curr!=NULL;curr=curr->nextx)
   	{
   		printf("(%d,%d) ",curr->x,curr->y);
   	}
   }
   else
   {
   	node *curr1;
   	curr1=L->nexty;
   	for (;curr1!=NULL;curr1=curr1->nexty)
   	{
   		printf("(%d,%d) ",curr1->x,curr1->y);
   	}
   }
   printf ("\n");
   	
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   int i;
   node *curr,*curr1;
   for(i=0;i<100;i++)
   {
   curr=L;
   curr1=curr->nextx;
   for (;curr1->nextx!=NULL;)
   {
   	if ((curr1->nextx->x)<curr1->x)
   	{
   		curr->nextx=curr1->nextx;
   		curr1->	nextx=curr->nextx->nextx;
   		curr->nextx->nextx=curr1;
   	}
   	curr=curr->nextx;
   	curr1=curr->nextx;
   }
   }	
   
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   int i;
   node *curr,*curr1;
   for (i=0;i<100;i++)
   {
   curr=L;
   curr1=curr->nexty;
   for (;curr1->nexty!=NULL;)
   {
   	if ((curr1->nexty->y)<curr1->y)
   	{
   		curr->nexty=curr1->nexty;
   		curr1->	nexty=curr->nexty->nexty;
   		curr->nexty->nexty=curr1;
   	}
   	curr=curr->nexty;
   	curr1=curr->nexty;
   }
   }
}

int main ()
{
   list L;
   int n;
   scanf("%d",&n);
   L = genRandList(n);
   printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);
   bubbleSortX(L);
   bubbleSortY(L);
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return(0);
}
