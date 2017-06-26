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
	node *p,*q;
			p=L->nextx;
			q=L->nexty;
			if(flag==WRT_X)
			{
				while(p!=NULL)
				{
					printf("(%d,%d) ",p->x,p->y);
					p=p->nextx;
				}
			}
			else if(flag==WRT_Y)
			{
				while(q!=NULL)
				{
					printf("(%d,%d) ",q->x,q->y);
					q=q->nexty;
				}
			}
}

void bubbleSortX ( list L )
{
	
	int i;
   // Write C-code Here
	for(i=N;i>=2;i--)
	{
   if(L->nextx!=NULL)
	{
		node *p,*q,*r;
			p=L;
			q=p->nextx;
			r=q->nextx;
		while(r!=NULL)
		{
			
			int x;
			x=(q->x)-(r->x);
			if(x>0)
			{
				p->nextx=r;
				q->nextx=r->nextx;
				r->nextx=q;

				p=p->nextx;			
				r=(r->nextx)->nextx;	
			} 
			else
			{
				p=p->nextx;
				q=q->nextx;
				r=r->nextx;
			}
			
			
		}
		
	}
	}
	
}

void bubbleSortY ( list L )
{
	
	int i;
   // Write C-code Here
	for(i=N;i>=2;i--)
	{
   if(L->nexty!=NULL)
	{
		node *p,*q,*r;
			p=L;
			q=p->nexty;
			r=q->nexty;
		while(r!=NULL)
		{
			
			int y;
			y=(q->y)-(r->y);
			if(y>0)
			{
				p->nexty=r;
				q->nexty=r->nexty;
				r->nexty=q;

				p=p->nexty;			
				r=(r->nexty)->nexty;	
			} 
			else
			{
				p=p->nexty;
				q=q->nexty;
				r=r->nexty;
			}
			
			
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
	printf("\n");
   return(0);
}
