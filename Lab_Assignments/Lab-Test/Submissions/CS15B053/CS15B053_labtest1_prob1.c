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
  node *cur;
   cur = (list)malloc(sizeof(node));
   
   if(flag == 0)
   {
   	   cur = L->nextx;	   
	   while(cur!=NULL)
	   {
	   	printf("(%d,%d) ", cur->x, cur->y);
	   	cur = cur->nextx;
	   }
   }
   else if(flag == 1)
   {
   	   cur = L->nexty;	   
	   while(cur!=NULL)
	   {
	   	printf("(%d,%d) ", cur->x, cur->y);
	   	cur = cur->nexty;
	   }
   }
}

void bubbleSortX ( list L )
{
   node *prev, *cur, *next, *nextnext, *trav;
   cur = (list)malloc(sizeof(node));
   next = (list)malloc(sizeof(node));
   nextnext = (list)malloc(sizeof(node));
   trav = (list)malloc(sizeof(node));
   
   int i, j;
   for(j=1; j<=100; j++)
   {
   	prev = (list)malloc(sizeof(node));
   	prev ->nextx = L->nextx ;
   	cur = L->nextx;
   	next = cur->nextx;  	
  	nextnext = next->nextx;
  	
  	i = 0;
  	while(next!=NULL)
   	{
   		i++;
   		if(cur->x > next->x)
	   	{
	   		prev->nextx = next;
	   		cur->nextx = cur->nextx->nextx;
	   		next->nextx = cur;
	   		if(i == 1)
	   			L->nextx = next;
	   	}
	   	prev = prev->nextx;
	   	cur = prev->nextx;
	   	next =cur->nextx;
	   	if(next != NULL)
	   		nextnext = next->nextx;
	   	
	  }
   } 
}

void bubbleSortY ( list L )
{
   node *prev, *cur, *next, *nextnext, *trav;
   cur = (list)malloc(sizeof(node));
   next = (list)malloc(sizeof(node));
   nextnext = (list)malloc(sizeof(node));
   trav = (list)malloc(sizeof(node));
   
   int i, j;
   for(j=1; j<=100; j++)
   {
   	prev = (list)malloc(sizeof(node));
   	prev ->nexty = L->nexty ;
   	cur = L->nexty;
   	next = cur->nexty;  	
  	nextnext = next->nexty;
  	
  	i = 0;
  	while(next!=NULL)
   	{
   		i++;
   		if(cur->y > next->y)
	   	{
	   		prev->nexty = next;
	   		cur->nexty = cur->nexty->nexty;
	   		next->nexty = cur;
	   		if(i == 1)
	   			L->nexty = next;
	   	}
	   	prev = prev->nexty;
	   	cur = prev->nexty;
	   	next =cur->nexty;
	   	if(next != NULL)
	   		nextnext = next->nexty;
	   	
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
