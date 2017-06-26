#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000
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
	if(flag == 0)
	{
		list temp = L->nextx ;
		while(temp!=NULL)
		{
			printf("(%d,%d) ",temp->x,temp->y);
			temp = temp ->nextx ;
		}		
	}
	else if(flag == 1)
	{
		list temp = L->nexty ;
		while(temp!=NULL)
		{
			printf("(%d,%d) ",temp->x,temp->y);
			temp = temp ->nexty ;
		}		
	}
	printf("\n");
}

void bubbleSortX ( list L )
{	
	if(L!=NULL && L->nextx !=NULL)
	{
		list temp = L,curr;
		int i;
		
		for(i=0;i<N;i++)	
		{	
					
			if(L->x > L->nextx->x)
			{
				temp = L->nextx ;
				L->nextx = L->nextx->nextx ;
				temp->nextx = L ;
				L = temp ;
			}
			else
			{
				temp = L;
			}
		
			while(temp->nextx->nextx != NULL)
			{
				if(temp->nextx->x >temp->nextx->nextx->x)
				{
					curr = temp->nextx ;
					temp->nextx = temp->nextx->nextx ;
					curr->nextx = temp->nextx->nextx ;
					temp->nextx->nextx = curr ;				
				}
				temp = temp->nextx ;
			}
		}
	}
	
}

void bubbleSortY ( list L )
{
	if(L!=NULL && L->nexty !=NULL)
	{
		list temp = L,curr;
		int i;
		
		for(i=0;i<N;i++)	
		{			
			//for comparing and moving list of head
			if(L->y> L->nexty->y)
			{
				temp = L->nexty ;
				L->nexty = L->nexty->nexty ;
				temp->nexty = L ;
				L = temp ;
			}
			else
			{
				temp = L;
			}
			//Do 1 pass and swap when inversion found		
			while(temp->nexty->nexty != NULL)
			{
				if(temp->nexty->y >temp->nexty->nexty->y)
				{
					curr = temp->nexty ;
					temp->nexty = temp->nexty->nexty ;
					curr->nexty = temp->nexty->nexty ;
					temp->nexty->nexty = curr ;				
				}
				temp = temp->nexty ;
			}
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
