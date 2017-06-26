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
	node *tra;
	tra = L;
	if(flag == 0){
	tra = L->nextx;
		for( ; tra != NULL ; ){
			printf("(%d,%d) ",tra->x,tra->y);
			tra = tra->nextx;
		}
	}

	else{
		tra = L->nexty;
		for( ; tra != NULL ; ){
			printf("(%d,%d) ",tra->x,tra->y);
			tra = tra->nexty;
		}
	}
		printf("\n");
}

void bubbleSortX ( list L )
{
   // Write C-code Here
	list curr,prev;
	int i,j;
	for(j=1 ; j<N ; j++){
		prev=L;
		curr=L->nextx;
		if(curr==NULL){
			return;
		}
		for( i=j; i<N ; i++){	
			if(curr->x > (curr->nextx)->x ){
				prev->nextx = curr->nextx;
				curr->nextx = (prev->nextx)->nextx;
				(prev->nextx)->nextx = curr;
				prev = prev->nextx;	
			}
	
			else{
				prev = curr;
				curr = curr->nextx; 
			}
		}
	}
	return ;
}

void bubbleSortY ( list L )
{
   // Write C-code Here
	list curr,prev;
	int i,j;
	for(j=1 ; j<N ; j++){
		prev=L;
		curr=L->nexty;
		if(curr==NULL){
			return;
		}
		for( i=j; i<N ; i++){	
			if(curr->y > (curr->nexty)->y ){
				prev->nexty = curr->nexty;
				curr->nexty = (prev->nexty)->nexty;
				(prev->nexty)->nexty = curr;
				prev = prev->nexty;	
			}
	
			else{
				prev = curr;
				curr = curr->nexty; 
			}
		}
	}
	return ;

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
