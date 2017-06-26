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
   int i;
   curx = L;
   prex = L;
   for( i = 0 ; i < 100 ; i++)
   {
   		while( (curx -> nextx ) != NULL )
   		{
   			if( (curx -> x) > (curx -> nextx -> x) && (prex != curx) )
   			{
   				node* temp1 = (node *)malloc(sizeof(node));
   				node* temp2 = (node *)malloc(sizeof(node));
   				temp1 = curx -> nextx;
   				temp2 = curx -> nextx -> nextx;
   				temp1 -> nextx = curx;
   				prex -> nextx = temp1;
   				curx -> nextx = temp2;
   				prex = prex -> nextx;
   			}
   			else if( (prex == curx) && (curx -> x) > (curx -> nextx -> x))
   			{
   				node* temp;
   				temp = curx -> nextx -> nextx;
   				L = curx -> nextx;
   				L -> nextx = curx;
   				prex -> nextx = temp;
   			}
   			else
   			{
   				prex = curx;
   				curx = curx -> nextx;
   			}
   		}
   		curx = L;
   }
   return ;
   // Write C-code Here
}

void bubbleSortY ( list L )
{
   node* cury = (node *)malloc(sizeof(node));
   node* prey = (node *)malloc(sizeof(node));
   int i;
   cury = L;
   prey = L;
   for( i = 0 ; i < 100 ; i++)
   {
   		while( (cury -> nexty ) != NULL )
   		{
   			if( (cury -> y) > (cury -> nexty -> y) && (prey != cury) )
   			{
   				node* temp1 = (node *)malloc(sizeof(node));
   				node* temp2 = (node *)malloc(sizeof(node));
   				temp1 = cury -> nexty;
   				temp2 = cury -> nexty -> nexty;
   				temp1 -> nexty = cury;
   				prey -> nexty = temp1;
   				cury -> nexty = temp2;
   				prey = prey -> nexty;
   			}
   			else if( (prey == cury) && (cury -> y) > (cury -> nexty -> y))
   			{
   				node* temp;
   				temp = cury -> nexty -> nexty;
   				L = cury -> nexty;
   				L -> nexty = cury;
   				prey -> nexty = temp;
   			}
   			else
   			{
   				prey = cury;
   				cury = cury -> nexty;
   			}
   		}
   		cury = L;
   }
   return ;// Write C-code Here
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
