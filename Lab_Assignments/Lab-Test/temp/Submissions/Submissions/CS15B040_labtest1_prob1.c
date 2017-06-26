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
	   	L=L->nextx;
	   	while(L!=NULL){
	   		printf("(%d,%d) ",L->x,L->y);
	   		L=L->nextx;
	   	}
}

void bubbleSortX ( list L )
{
   	node* head=(node*)malloc(sizeof(node));
   	node* temp=(node*)malloc(sizeof(node));
   	node* q=(node*)malloc(sizeof(node));
   	  	
   	for(q=L;q->nextx!=NULL;q=q->nextx){
   	
   		for(head=L;head->nexty!=NULL;head=head->nexty){
   			if(((head->nexty)->x)<((L->nextx)->x)){
   				temp->nextx=head->nextx;
   				temp->nexty=head->nexty;
   				head->nextx=q->nextx;
   				head->nexty=q->nexty;
   				q->nextx=temp->nextx;
   				q->nexty=temp->nexty;
   				
   			}
   				
   		}
   	}
}

void bubbleSortY ( list L )
{
   	node* head=(node*)malloc(sizeof(node));
   	node* temp=(node*)malloc(sizeof(node));
   	node* q=(node*)malloc(sizeof(node));
   	
   	for(q=L;q->nexty!=NULL;q=q->nexty){
   	
   		for(head=L;head->nextx!=NULL;head=head->nextx){
   			if(((head->nextx)->y)>((L->nexty)->y)){
   				temp->nextx=head->nextx;
   				temp->nexty=head->nexty;
   				head->nextx=q->nextx;
   				head->nexty=q->nexty;
   				q->nextx=temp->nextx;
   				q->nexty=temp->nexty;
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
