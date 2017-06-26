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

   if(flag == 0){
   		node *counter = L -> nextx;
   		while(counter != NULL){
   			printf("(%d,%d) ",counter -> x, counter -> y);
   			counter = counter -> nextx;
   		}
   		printf("\n");
   }
   
   else{
		node *counter = L -> nexty;
   		while(counter != NULL){
   			printf("(%d,%d) ",counter -> x, counter -> y);
   			counter = counter -> nexty;
   		}
   		printf("\n"); 		
   }
}

void bubbleSortX ( list L )
{
   // Write C-code Here   
   
   node *counter1, *counter2;
   
   counter1 = L->nextx;
   
   int i = 0;
   
   while(counter1 != NULL){
   
   		counter2 = L;
   		
   		while(counter2->nextx->nextx != NULL){
   			
   			if(counter2->nextx->x > counter2->nextx->nextx->x){
   				node *tempx, *tempy;
   				
   				tempx = counter2->nextx;
   				counter2->nextx = counter2->nextx->nextx;
   				tempx->nextx = counter2->nextx->nextx;
   				counter2->nextx->nextx = tempx;
   				
   			}
   			
   			counter2 = counter2->nextx;
   		}
   		
   		counter1 = counter1->nextx;
   }
      
}

void bubbleSortY ( list L )
{
   // Write C-code Here

   node *counter1, *counter2;
   
   counter1 = L->nexty;
   
   while(counter1 != NULL){
   
   		counter2 = L;
   		
   		while(counter2->nexty->nexty != NULL){
   			
   			if(counter2->nexty->y > counter2->nexty->nexty->y){
   				node *tempx, *tempy;
   				   				
   				tempy = counter2->nexty;
   				counter2->nexty = counter2->nexty->nexty;
   				tempy->nexty = counter2->nexty->nexty;
   				counter2->nexty->nexty = tempy;
   				
   			}
   			
   			counter2 = counter2->nexty;
   		}
   		
   		counter1 = counter1->nexty;
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
