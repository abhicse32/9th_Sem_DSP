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
node* A;

if(flag==0)
for(A=L->nextx;A!=NULL;A=A->nextx)
printf("(%d,%d) ",A->x,A->y);

else	
for(A=L->nexty;A!=NULL;A=A->nexty)
printf("(%d,%d) ",A->x,A->y);	

printf("\n");
	
}

void bubbleSortX ( list L )
{
   // Write C-code Here
list A,B;
node* temp;

for(B=L;(B->nextx->nextx)!=NULL;B=B->nextx)
	for(A=L;(A->nextx->nextx)!=NULL;A=A->nextx)
	{
		if(A->nextx->x>A->nextx->nextx->x)
		{
		temp=A->nextx->nextx->nextx;
		A->nextx->nextx->nextx=A->nextx;
		A->nextx=A->nextx->nextx;
		A->nextx->nextx->nextx=temp;
		}
	}

}

void bubbleSortY ( list L )
{
   // Write C-code Here
list A,B;
node* temp;

for(B=L;(B->nexty->nexty)!=NULL;B=B->nexty)
	for(A=L;(A->nexty->nexty)!=NULL;A=A->nexty)
	{
		if((A->nexty->y)>(A->nexty->nexty->y))
		{
		temp=A->nexty->nexty->nexty;
		A->nexty->nexty->nexty=A->nexty;
		A->nexty=A->nexty->nexty;
		A->nexty->nexty->nexty=temp;
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
