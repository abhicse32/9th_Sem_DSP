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
	node* p = L;   // create a temporary pointer p
   if(flag == 0)
   {
   	while(p != NULL)
   		{
   			printf("(%d,%d) ", p->x, p->y);
   			p = p -> nextx;
   		}
   }
   else if(flag == 1)
   {
   	while(p != NULL)
   		{
   			printf("(%d,%d) ", p->x, p->y);
   			p = p -> nexty;
   		}
   }
   printf("\n");
}

void bubbleSortX ( list L )
{
   int size = 0;
   node* p = L;
   
   while(p != NULL)
   { size++;  p = p-> nextx;}   // get the size of the list
  
   while(size > 3)              // n full traverses throughout the list
   { 								// with each traverse one element is put in the right spot
   		p=L;
   		while( p -> nextx -> nextx != NULL )
   		{
   			int a,b;
   			a= p -> nextx -> x;
   			b= p -> nextx -> nextx -> x;
   			
   			if(a > b)   // then swap. push larger elements to the right
   			{
   				node* temp = p -> nextx;
   				p -> nextx = p -> nextx -> nextx;
   				temp -> nextx = temp -> nextx -> nextx;
   				p -> nextx -> nextx = temp;	
   			}	
   			
   			p = p -> nextx;
   		}
   		size--;
   }
   
}

void bubbleSortY ( list L )
{
  int size = 0;
   node* p = L;
   while(p != NULL)
   { size++;  p = p-> nexty;}   // get the size of the list
   
   while(size > 0)              // n full traverses throughout the list
   { 						// with each traverse one element is put in the right spot
   		p=L;
   		while( p -> nexty -> nexty != NULL )
   		{
   			int a,b;
   			a= p -> nexty -> y;
   			b= p -> nexty -> nexty -> y;
   			
   			if(a > b)   // then swap. push larger elements to the right
   			{
   				node* temp = p -> nexty;
   				p -> nexty = p -> nexty -> nexty;
   				temp -> nexty = temp -> nexty -> nexty;
   				p -> nexty -> nexty = temp;	
   			}	
   			
   			p = p -> nexty;
   		}
   		size--;
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
