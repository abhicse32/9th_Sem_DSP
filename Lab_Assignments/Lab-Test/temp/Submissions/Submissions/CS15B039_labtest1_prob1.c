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
   //Printing with respect to x
   if(flag==0)
   {
   	node *cur = (L->nextx);
   	while(cur!=NULL)
   	{
   		printf("(%d,%d) ", cur->x, cur->y);
   		cur = cur->nextx;
   	}
   }
   //Printintg with respect to y
   else 
   {
   	node *cur = (L->nexty);
   	while(cur!=NULL)
   	{
   		printf("(%d,%d) ", cur->x, cur->y);
   		cur = cur->nexty;
   	}
   }	
   printf("\n");
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   //Initializations 
   node *prev, *cur;
   int i, j;
   
   prev = L;
   cur = L->nextx;
   
   for(i=N-1;i>0;i--)
   {
   	for(j=0;j<i;j++)
   	{
   		if(cur->x > (cur->nextx)->x)
   		{
   			prev->nextx = (cur->nextx);
   			cur->nextx = (cur->nextx)->nextx;
   			(prev->nextx)->nextx = cur;
   			prev = prev->nextx;
   		}
   		else
   		{
   			cur = cur->nextx;
   			prev = prev->nextx;
   		}
   	}
   	cur = L->nextx;
   	prev = L;
   }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   //Initializations 
   node *prev, *cur;
   int i, j;
   
   prev = L;
   cur = L->nexty;
   
   for(i=N-1;i>0;i--)
   {
   	for(j=0;j<i;j++)
   	{
   		if(cur->y > (cur->nexty)->y)
   		{
   			prev->nexty = (cur->nexty);
   			cur->nexty = (cur->nexty)->nexty;
   			(prev->nexty)->nexty = cur;
   			prev = prev->nexty;
   		}
   		else
   		{
   			cur = cur->nexty;
   			prev = prev->nexty;
   		}
   	}
   	cur = L->nexty;
   	prev = L;
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
