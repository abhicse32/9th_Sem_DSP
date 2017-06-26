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
if(L==NULL||L->nextx==NULL)
	return;
if(flag==0)
{
	list l=L->nextx;
	while(l!=NULL)
	{
		printf("(%d,%d) ",l->x,l->y);
		l=l->nextx;
	}
}	
if(flag==1)
{
	list l=L->nexty;
	while(l!=NULL)
	{
		printf("(%d,%d) ",l->x,l->y);
		l=l->nexty;
	}
}	
printf("\n");
	// Write C-code Here
}

void bubbleSortX ( list L )
{
	if(L==NULL||L->nextx==NULL)
		return;
	int count=0,i;
	list l=L->nextx,m,n;
	while(l!=NULL)
	{
		count++;
		l=l->nextx;
	}
	while(count>1)
	{
	l=L;
	i=0;	
	m=l->nextx;
	n=m->nextx;
	while(n!=NULL&&i<count-1)
	{
		if((m->x)>(n->x))
		{
			l->nextx=n;
			m->nextx=n->nextx;
			n->nextx=m;

		}
		l=l->nextx;
		m=l->nextx;
		n=m->nextx;	
		i++;			
	}
	count--;
	}  // Write C-code Here
}

void bubbleSortY ( list L )
{
 if(L==NULL||L->nexty==NULL)
		return;
	int count=0,i;
	list l=L->nexty,m,n;
	while(l!=NULL)
	{
		count++;
		l=l->nexty;
	}
	while(count>1)
	{
	l=L;
	i=0;	
	m=l->nexty;
	n=m->nexty;
	while(n!=NULL&&i<count-1)
	{
		if((m->y)>(n->y))
		{
			l->nexty=n;
			m->nexty=n->nexty;
			n->nexty=m;

		}
		l=l->nexty;
		m=l->nexty;
		n=m->nexty;	
		i++;			
	}
	count--;
	}    
// Write C-code Here
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
