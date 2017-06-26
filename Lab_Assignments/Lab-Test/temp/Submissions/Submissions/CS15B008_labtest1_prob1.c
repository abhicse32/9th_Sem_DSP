#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 32
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
   if(flag == 0)
   {
	L = L->nextx;
	while(L->nextx != NULL)
	{
		printf("(%d,%d) ",L->x,L->y);
		L = L->nextx;
	}
	printf("(%d,%d) ",L->x,L->y);
   }
   else if(flag == 1)
   {
	L = L->nexty;
    	while(L->nexty != NULL)
	{
		printf("(%d,%d) ",L->x,L->y);
		L = L->nexty;
	}
	printf("(%d,%d) ",L->x,L->y);
   }

}

void bubbleSortX ( list L )
{
   // Write C-code Here
int i,j;
       list L1 = L;
       for(i = 0;i <N;i++)
	{
            	for(j = i; j<N -3;j++)
		{
			if(L->x > ((L->nextx)->x))
			{
			        node* swap1 = (L->nextx)->nextx;
				node* swap2 = L;
				L = L->nextx;
        			L->nextx = swap2;
				(L->nextx)->nextx = swap1;
 					
			   
			}
                     // L = L->nextx;
                       
                        
		}
             L1 = L1->nextx;
             L = L1;
          
	} 
			   
}

void bubbleSortY ( list L )
{
   // Write C-code Here
        int i,j;
        list L1 = L;
	for(i = 0;i < N;i++)
	{
		for(j = i;j < N - 3;j++)
		{
			if(L->y > (L->nexty)->y)
			{
				node* swap1 = (L->nexty)->nexty;
				node* swap2 = L;
				L = L->nexty;
        			L->nexty = swap2;
				(L->nexty)->nexty = swap1;
 				
			}
                        //L = L->nexty;
                      
                        
		}
            L1 = L1->nexty;
            L = L1;
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
