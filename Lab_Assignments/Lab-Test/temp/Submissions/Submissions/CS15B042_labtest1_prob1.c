#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
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
	node *p;
int i = 0;
	if(flag == 0){
		p = L -> nextx;
		while(p != NULL){
			printf("(%d,%d) ",p -> x,p -> y);
			p = p -> nextx;
		}	
	}
	if(flag == 1){
		p = L -> nexty;
		while(p != NULL){
			printf("(%d,%d) ",p -> x,p -> y);
			fflush(stdout);
			p = p -> nexty;
		}
	}
	return;
}

void bubbleSortX ( list L )
{
	node *p,*a,*b,*temp;
	int i,j;
	for(i = N;i > 0;i--){
		p = L;
		a = L -> nextx;
		b = L -> nextx -> nextx; 		
		for(j = 0;j < i - 1;j++){
			if(a -> x > b -> x){
				p -> nextx = b;
				a -> nextx = b -> nextx;
				b -> nextx = a;
				temp = b;
				b = a;
				a = b;	
			}
			p = p -> nextx;
			a = a -> nextx;
			b = b -> nextx;			
		}	
	}
}
  
void bubbleSortY ( list L )
{
   // Write C-code Here
	node *p,*a,*b,*temp;
	int i,j;
	for(i = N;i > 0;i--){
		p = L;
		a = L -> nexty;
		b = L -> nexty -> nexty; 		
		for(j = 0;j < i - 1;j++){
			if(a -> y > b -> y){
				p -> nexty = b;
				a -> nexty = b -> nexty;
				b -> nexty = a;
				temp = b;
				b = a;
				a = b;	
			}
			p = p -> nexty;
			a = a -> nexty;
			b = b -> nexty;			
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
