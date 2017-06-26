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
	
	if(flag==WRT_X)
	{	
		list np=L->nextx;
	  	while(np!=NULL)
		{
			printf("(%d,%d) ",np->x,np->y);
			np=np->nextx;	
		}
	}
	else
	{
		list np=L->nexty;
	  	while(np!=NULL)
		{
			printf("(%d,%d) ",np->x,np->y);
			np=np->nexty;	
		}
	}
	

}

void bubbleSortX ( list L )
{
	list np=L->nextx; 		//first node is dummy node
	int size=0;
	while(np!=NULL)
	{
		size++;
		np=np->nextx;
	}
	int i=0;
	if(L->nextx!=NULL)
	{
		for(i=0;i<size;i++)
		{
			np=L->nextx->nextx;
			list larger=L->nextx;		//to store the node of element which bubbles to the end
			int count=0;
			list prevOfprevnode=NULL;	//to store the node two places before np
			while(count<size-i-1)
			{
				list nextnode=np->nextx;	//to store next node of np
				if(np->x<larger->x)
				{
					if(count==0)
						L->nextx=np;
					if(count!=0&&prevOfprevnode!=NULL)
						prevOfprevnode->nextx=np;
					np->nextx=larger;
					prevOfprevnode=np;
					larger->nextx=nextnode;
				}
				else
				{
					prevOfprevnode=larger;
					larger=np;					
				}
				
				np=nextnode;
				count++;
			}
		}
	}
}

void bubbleSortY ( list L )
{
	list np=L->nexty; 		//first node is dummy node
	int size=0;
	while(np!=NULL)
	{
		size++;
		np=np->nexty;
	}
	int i=0;
	if(L->nexty!=NULL)
	{
		for(i=0;i<size;i++)
		{
			np=L->nexty->nexty;
			list larger=L->nexty;
			int count=0;
			list prevOfprevnode=NULL;
			while(count<size-i-1)
			{
				list nextnode=np->nexty;
				if(np->y<larger->y)
				{
					if(count==0)
						L->nexty=np;
					if(count!=0&&prevOfprevnode!=NULL)
						prevOfprevnode->nexty=np;
					np->nexty=larger;
					prevOfprevnode=np;
					larger->nexty=nextnode;
				}
				else
				{
					prevOfprevnode=larger;
					larger=np;
					
				}
				
				np=nextnode;
				count++;
			}
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
