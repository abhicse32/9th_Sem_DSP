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
	int c = 0;	//counter to break line
	if(flag == 0)
	{
		node *temp = L;
		while(temp != NULL)
		{
			printf("(%d,%d) ",temp->x,temp->y);
			c++;
			if(c==6)
			{
				printf("\n");
				c = 0;
			}
			temp = temp->nextx;
		}
	}
	else if(flag == 1)
	{
		node *temp = L;
		while(temp != NULL)
		{
			printf("(%d,%d) ",temp->x,temp->y);
			c++;
			if(c==6)
			{
				printf("\n");
				c = 0;
			}
			temp = temp->nexty;
		}
	}
}

void bubbleSortX ( list L )
{
   // Write C-code Here
	node *temp,*temp1,*temp2;
	node *tempy;

	temp = L;
	//printf("%d ",temp->x);
	temp1 = L->nextx;
	//printf("%d ",temp1->x);
	temp2 = L->nextx->nextx;
	//printf("%d ",temp2->x);
	tempy = L;

	while(tempy!=NULL)
	{
		temp = L;
		temp1 = L->nextx;
		temp2 = L->nextx->nextx;

		while(temp1->nextx == NULL)
		{

			if(temp1->x > temp2->x)
			{
				temp = temp1->nextx;
				temp2->nextx = temp1;
			}
			temp1 = temp1->nextx;
			temp2 = temp2->nextx;
		}
	
		tempy = tempy->nexty;
	}
}

void bubbleSortY ( list L )
{
   // Write C-code Here
	node *temp,*temp1,*temp2;
	node *tempx;

	temp = L;
	//printf("%d ",temp->y);
	temp1 = L->nexty;
	//printf("%d ",temp1->y);
	temp2 = L->nexty->nexty;
	//printf("%d ",temp2->y);
	tempx = L;

	while(tempx!=NULL)
	{
		temp = L;
		temp1 = L->nexty;
		temp2 = L->nexty->nexty;

		while(temp1->nexty == NULL)
		{

			if(temp1->y > temp2->y)
			{
				temp = temp1->nexty;
				temp2->nexty = temp1;
			}
			temp1 = temp1->nexty;
			temp2 = temp2->nexty;
		}
	
		tempx = tempx->nextx;
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
