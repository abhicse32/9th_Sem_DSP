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

if(flag==WRT_X)
	{	node* a;
		a=L;
		if(a->nextx->nextx!= NULL)
  		 while(a->nextx !=NULL )
 		 {	

			{
			 printf("(%d ,%d) ",a->x,a->y);
			 a=a->nextx;
			 a=a->nexty;
			}	 
		}
		
	}
if(flag==WRT_Y)
	{
		node* a;
		a=L;
		if(a->nexty->nexty!= NULL)
  		 while(a->nexty !=NULL )
 		 {	

			{
			 printf("(%d ,%d) ",a->x,a->y);
			 a=a->nextx;
			 a=a->nexty;
			}	 
		}


}



}


void bubbleSortX ( list L )
{
	int i;
	node* curr;
	node* target;
	node* currnext;
	node* dummy=NULL;
	curr->nextx=L->nextx;
	curr->nexty=L->nexty;
	currnext->nextx=curr->nextx;
	currnext->nexty=curr->nexty;
	target=L;
if(L!=NULL)	
	while(  currnext!= L)
	{
		curr->nextx=L->nextx;
	curr->nexty=L->nexty;
	currnext->nextx=curr->nextx;
	currnext->nexty=curr->nexty;
	target=L;
	while(currnext!=dummy)
		{if(currnext->x  <  curr->x)
				//swap
		{
			
				curr->nextx->nextx= currnext->nextx;
				curr->nexty->nexty= currnext->nexty;//
				currnext->nextx=target->nextx;
				currnext->nexty=target->nexty;
				target->nextx=currnext->nextx;
				target->nexty=currnext->nexty;
				
				
				
		
		}
				curr=curr->nextx;
				curr=curr->nexty;
				currnext=currnext->nextx;
				currnext=currnext->nexty;
				dummy=target->nextx;
				target=target->nextx;
				target=target->nexty;
				

		}
	}
	







   
}

void bubbleSortY ( list L )
{
   

	int i;
	node* curr;
	node* target;
	node* currnext;
	node* dummy=NULL;
	curr->nextx=L->nextx;
	curr->nexty=L->nexty;
	currnext->nextx=curr->nextx;
	currnext->nexty=curr->nexty;
	target=L;
	
	
if(L!=NULL)	
	while(  currnext!= L)
	{
		curr->nextx=L->nextx;
	curr->nexty=L->nexty;
	currnext->nextx=curr->nextx;
	currnext->nexty=curr->nexty;
	target=L;
	while(currnext!=dummy)
		{if(currnext->y  <  curr->y)
				//swap
		{
			
				curr->nextx->nextx= currnext->nextx;
				curr->nexty->nexty= currnext->nexty;//
				currnext->nextx=target->nextx;
				currnext->nexty=target->nexty;
				target->nextx=currnext->nextx;
				target->nexty=currnext->nexty;
				
				
				
		
		}
				curr=curr->nextx;
				curr=curr->nexty;
				currnext=currnext->nextx;
				currnext=currnext->nexty;
				dummy=target->nexty;
				target=target->nextx;
				target=target->nexty;
				

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
