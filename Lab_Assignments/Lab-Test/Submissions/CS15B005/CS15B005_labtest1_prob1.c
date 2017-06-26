#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int N;
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
      //q -> x = 1000 + rand() % 9000;
      //q -> y = 1000 + rand() % 9000;
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
   node* curx = (node *)malloc(sizeof(node));
   node* cury = (node *)malloc(sizeof(node));
   
   if(flag == 0)
   {
   		curx = L -> nextx ;
   		while ((curx) != NULL)
   		{
   			printf("(%d,%d) ", curx -> x , curx->y );
   			curx = curx -> nextx;
   		}
   		printf("\n");
   		printf("\n");
   		return ;
   }
   // Write C-code Here
   if(flag == 1)
   {
   		cury = L -> nexty ;
   		while ((cury) != NULL)
   		{
   			printf("(%d,%d) ", cury -> x, cury -> y);
   			cury = cury -> nexty ;
   		}
   		printf("\n");
   		printf("\n");
   		return ;
   }
}

void bubbleSortX ( list L )
{
   node* curx = (node *)malloc(sizeof(node));
   node* prex = (node *)malloc(sizeof(node));
   int i, j = 0;
   curx = L;
   prex = L;
   for( i = 0 ; i < N ; i++)
   {
   		while( (N-1-i) !=j )
   		{
   			if( (curx -> nextx -> x) > (curx -> nextx -> nextx -> x))
   			{
   				//node* temp1 = (node *)malloc(sizeof(node));
   				//node* temp2 = (node *)malloc(sizeof(node));
   				prex = curx -> nextx;
   				curx -> nextx = curx -> nextx -> nextx;
   				prex -> nextx = curx -> nextx -> nextx;
   				curx -> nextx -> nextx = prex;
   			}
   			curx = curx -> nextx;
   			j++;
   		}
   		curx = L;
   		j = 0;
   }
   return ;
   // Write C-code Here
}

void bubbleSortY ( list L )
{
   node* cury = (node *)malloc(sizeof(node));
   node* prey = (node *)malloc(sizeof(node));
   int i, j = 0;
   cury = L;
   prey = L;
   for( i = 0 ; i < N ; i++)
   {
   		while( (N-1-i) !=j )
   		{
   			if( (cury -> nexty -> y) > (cury -> nexty -> nexty -> y))
   			{
   				//node* temp1 = (node *)malloc(sizeof(node));
   				//node* temp2 = (node *)malloc(sizeof(node));
   				prey = cury -> nexty;
   				cury -> nexty = cury -> nexty -> nexty;
   				prey -> nexty = cury -> nexty -> nexty;
   				cury -> nexty -> nexty = prey;
   			}
   			cury = cury -> nexty;
   			j++;
   		}
   		cury = L;
   		j = 0;
   }
   return ;
   // Write C-code Here
}

int main ()
{
   list L;
	scanf("%d",&N);
   L = genRandList(N);
   printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);
   bubbleSortX(L);
   bubbleSortY(L);
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return(0);
}
