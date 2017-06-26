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
   if(flag==0)
   {
   		node *temp;
   		temp=L;
   		if(temp!=NULL)
   		temp=temp->nextx;
   		while(temp!=NULL)
   		{
   			printf("(%d,%d) ",temp->x,temp->y);
   			temp=temp->nextx;
   		}
   }
   else
   {
   		node *temp;
   		temp=L;
   		if(temp!=NULL)
   		temp=temp->nexty;
   		while(temp!=NULL)
   		{
   			printf("(%d,%d) ",temp->x,temp->y);
   			temp=temp->nexty;
   		}
   }
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   node *temp;
   temp=L;
   if(temp==NULL)
   return ;
   if(temp->nextx==NULL)
   return;
   if(temp->nextx->nextx==NULL)
   return;
   int checker=0;
   while(checker==0)
   {
   		temp=L;
   		node *temp2;
   		temp2=temp->nextx;
   		checker=1;
   		while(temp2->nextx!=NULL)
   		{
   			if(temp2->x > temp2->nextx->x)
   			{
   				temp->nextx=temp2->nextx;
   				temp2->nextx=temp2->nextx->nextx;
   				temp->nextx->nextx=temp2;
   				checker=0;
   			}
   			else 
   				temp2=temp2->nextx;
   				temp=temp->nextx;
   		//	}
   		}
   }
 //return ;
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   node *temp;
   temp=L;
   if(temp==NULL)
   return ;
   if(temp->nexty==NULL)
   return;
   if(temp->nexty->nexty==NULL)
   return;
   int checker=0;
   while(checker==0)
   {
   		temp=L;
   		node *temp2;
   		temp2=temp->nexty;
   		checker=1;
   		while(temp2->nexty!=NULL)
   		{
   			if(temp2->y > temp2->nexty->y)
   			{
   				temp->nexty=temp2->nexty;
   				temp2->nexty=temp2->nexty->nexty;
   				temp->nexty->nexty=temp2;
   				checker=0;
   			}
   			else 
   				temp2=temp2->nexty;
   				temp=temp->nexty;
   		//	}
   		}
   }
   //return ;
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
