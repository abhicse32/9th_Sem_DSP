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
   node *p ;
   
   if(flag == 0){
	  p = L->nextx;
	   while(p != NULL ){
	   		printf("(%d,%d) ", p->x, p->y);	fflush(stdout);
	   		p = p->nextx;
	   }
   		printf("\n");
   }
   else if(flag == 1){
   		p = L->nexty;
   		while(p != NULL ){
	   		printf("(%d,%d) ", p->x, p->y);	fflush(stdout);
	   		p = p->nexty;
	    }
   		printf("\n");
   }
   return;
   // Write C-code Here
}

void bubbleSortX ( list L )
{
   node *p, *q, *r, *temp;
	if(L->nextx == NULL) return;										// When there are no inputs			
   	if(L->nextx->nextx == NULL) return;									// When there is only one input
   int i;
   for( i = 0; i < N; i++){ 											// Repeating it for 100 times (bubble sort)
   r = L;
   p = L->nextx;
   q = L->nextx->nextx;
   
   while(q != NULL ){
   		if( p->x > q->x ){
   			p->nextx = q->nextx;										// If next number is smaller swapping the 
   			r->nextx = q;												// positions of p and q
   			q->nextx = p;
   			temp = p;
   			p = q;
   			q = temp;			
   		}
   		p = p->nextx; 
   		q = q->nextx;
   		r = r->nextx;
   }
   }
   return;
   // Write C-code Here
}

void bubbleSortY ( list L )
{
   node *p, *q, *r, *temp;
	if(L->nexty == NULL) return;										// When there are no inputs
   	if(L->nexty->nexty == NULL) return;									// When there is only one input				
   
   int i;
   for( i = 0; i < N; i++){												//Repeating it for 100 times (bubble sort)	
	   r = L;
	   p = L->nexty;													 
	   q = L->nexty->nexty;
	   while(q != NULL ){
	   		if( p->y > q->y ){											// Swapping the nodes if next node's value is smaller
	   			r->nexty = q;
	   			p->nexty = q->nexty;
	   			q->nexty = p;			
	   			temp = p;
	   			p = q;
	   			q = temp;
	   		}
	   		p = p->nexty; 
	   		q = q->nexty;
	   		r = r->nexty;
	   }
   }
   return;
   // Write C-code Here
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
