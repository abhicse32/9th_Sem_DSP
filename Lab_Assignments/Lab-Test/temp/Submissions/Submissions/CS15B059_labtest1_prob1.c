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
	node * temp=L;	//temporary pointer
  	if(flag==0)	//print the x elements
 	{
  	while(temp->nextx!=NULL)
	{
		printf("(%d,%d) ",temp->x,temp->y);	//to print the node	
		temp=temp->nextx;	//making temp move to the next node
	} 
  	}
  	
  	else if(flag==1)	//print the y elements
 	{
  	while(temp->nexty!=NULL)
	{
		printf("(%d,%d) ",temp->x,temp->y);	//to print the node	
		temp=temp->nexty;	//making temp move to the next node
	} 
  	}	
}

//sorting with respect to x
void bubbleSortX ( list L )
{
	node * temp=L;	//declaring a temporary pointer
	node * nextptr;	//points to the next node
	node * prev=NULL;	//points to the prev node
	nextptr=temp->nextx;	
	int i;
  	for(i=0;i<100;i++)
  	{
  	temp=L;	//initialise the pointers
  	prev=NULL;		
  	nextptr=temp->nextx;		
  	
  		while(temp->nextx!=NULL)	//till we dont reach the end of the loop
  		{
  		
  			if(temp->x > nextptr->x)	//not in order
  			{
  				if(prev != NULL)
  				prev->nextx=nextptr;	//skipping the node
  				temp->nextx=nextptr->nextx;
  				nextptr->nextx=temp;
  				prev=nextptr;
  				nextptr=temp->nextx;	//the next node
  			}
  			else
  			{
  				prev=temp;
  				temp=nextptr;
  				nextptr=temp->nextx;
  			}
  		}
  	}
}

//sorting with respect to y
void bubbleSortY ( list L )
{
  	node * temp=L;	//declaring a temporary pointer
	node * nextptr;	//points to the next node
	node * prev=NULL;	//points to the prev node
	nextptr=temp->nexty;	
	int i;
  	for(i=0;i<100;i++)
  	{
  	temp=L;	//initialise the pointers
  	prev=NULL;		
  	nextptr=temp->nexty;		
  	
  		while(temp->nexty!=NULL)	//till we dont reach the end of the loop
  		{
  		
  			
  			if(temp->y > nextptr->y)	//not in order
  			{
  				if(prev != NULL)
  				prev->nexty=nextptr;	//skipping the node
  				temp->nexty=nextptr->nexty;
  				nextptr->nexty=temp;
  				prev=nextptr;
  				nextptr=temp->nexty;	//the next node
  			}
  			else
  			{
  				prev=temp;
  				temp=nextptr;
  				nextptr=temp->nexty;
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
