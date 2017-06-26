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
{// Write C-code Here
	/* for temorary acessing*/
	node *cur;
    cur=L;
    /* for printing with respect ot x pointer*/
	if(flag==0)
	{
		cur=cur-> nextx;
		while(cur!=NULL)
		{
			printf("(%d,%d) ",cur->x,cur->y);
			cur=cur->nextx;
		}
		printf("\n");
	}
	/*for printing with respect to y pointer*/
		if(flag==1)
	{
		cur=cur-> nexty;
		while(cur!=NULL)
		{
			printf("(%d,%d) ",cur->x,cur->y);
			cur=cur->nexty;
		}
		printf("\n");
	}
	
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   /* for temorary acessing*/
	node *cur;
    cur=L;
    node *prev=L;
    node *end=NULL;
    cur=cur->nextx;
    
    while(end!=L->nextx)
    {
		while(cur->nextx!=end)
		{
			if(cur->nextx->x < cur->x)
			{
				prev->nextx=cur->nextx;
				cur->nextx=prev->nextx->nextx;
				prev->nextx->nextx=cur;
			}
			else
			{
			cur=cur->nextx;
			}
			prev=prev->nextx;
		}
		end=cur;
		cur=L->nextx;
		prev=L;
  	} 
}

void bubbleSortY ( list L )
{
   // Write C-code Here

   // Write C-code Here
   /* for temorary acessing*/
	node *cur;
    cur=L;
    node *prev=L;
    node *end=NULL;
    cur=cur->nexty;
    
    while(end!=L->nexty)
    {
		while(cur->nexty!=end)
		{
			if(cur->nexty->y < cur->y)
			{
				prev->nexty=cur->nexty;
				cur->nexty=prev->nexty->nexty;
				prev->nexty->nexty=cur;
			}
			else
			{
			cur=cur->nexty;
			}
			prev=prev->nexty;
		}
		end=cur;
		cur=L->nexty;
		prev=L;
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
