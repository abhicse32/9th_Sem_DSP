/*  Program to sort a linked list with respect to both x and y fields simultaneously
	Author : Chandrashekhar D   Roll no. CS15B009  Date : 19 Sept 2016  */

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
   node *ptr;
   if (flag == 0)	// Print with respect to consecutive x coordinates
   {
   		ptr = L->nextx;
   		while (ptr != NULL)
   		{
   			printf("(%d,%d) ",ptr->x,ptr->y);
   			ptr = ptr->nextx;
   		}
   }
   else				// Print with respect to consecutive y coordinates
   {
   		ptr = L->nexty;
   		while (ptr != NULL)
   		{
   			printf("(%d,%d) ",ptr->x,ptr->y);
   			ptr = ptr->nexty;
   		}
   }
   printf("\n");
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   int i,j;
   node *ptr;
   node *temp;		// Declaring two counters and two pointers
   for (i = 0; i < N-1; i++)
   {
   		ptr = L;
   		for (j = 0; j < N-1-i; j++)
   		{
   			if (ptr->nextx->x > ptr->nextx->nextx->x)	// If two consecutive x coordinates are in descending order, swap the two node positions
   			{
   				temp = ptr->nextx;
   				ptr->nextx = ptr->nextx->nextx;
   				temp->nextx = ptr->nextx->nextx;
   				ptr->nextx->nextx = temp;
   			}
   			ptr = ptr->nextx;
   		}
   }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   int i,j;
   node *ptr;
   node *temp;		// Declaring two counters and two pointers
   for (i = 0; i < N-1; i++)
   {
   		ptr = L;
   		for (j = 0; j < N-1-i; j++)
   		{
   			if (ptr->nexty->y > ptr->nexty->nexty->y)	// If two consecutive y coordinates are in descending order, swap the two node positions
   			{
   				temp = ptr->nexty;
   				ptr->nexty = ptr->nexty->nexty;
   				temp->nexty = ptr->nexty->nexty;
   				ptr->nexty->nexty = temp;
   			}
   			ptr = ptr->nexty;
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
