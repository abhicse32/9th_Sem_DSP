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
      // q -> x = 1000 + rand() % 9000;
      // q -> y = 1000 + rand() % 9000;
      scanf("%d%d",&(q->x),&(q->y));
      q -> nextx = q -> nexty = NULL;
      p -> nextx = p -> nexty = q;
      p = q;
   }

   return L;
}

// COMPLETE THE FOLLOWING (printList, bubbleSortX and bubbleSortY) FUNCTIONS
void printList ( list L, int flag )
{
	list local_head=L;
	if(local_head!=NULL){
		if(flag==WRT_X){
			do{
				printf("(%d,%d) ",local_head->x,local_head->y);
				local_head=local_head->nextx;			
			}while(local_head!=NULL);
		}
		else{
			do{
				printf("(%d,%d) ",local_head->x,local_head->y);
				local_head=local_head->nexty;			
			}while(local_head!=NULL);
		}
	}
	printf("\n");
}

void bubbleSortX ( list L )
{
	list dummy_head=(list)malloc(sizeof(node));
	dummy_head->nextx=L;
	list temp_node=dummy_head->nextx;
	list min_node=(list)malloc(sizeof(node));
	while(temp_node!=NULL){
		min_node=temp_node; 	
		while(temp_node->nextx!=NULL){
			if(temp_node->x>temp_node->nextx->x)
				min_node=temp_node->nextx;
			temp_node=temp_node->nextx;
		}
		temp_node=temp_node->nextx;
	}
	
}

void bubbleSortY ( list L )
{
   // Write C-code Here
}

int main ()
{
   list L;
   int n;
   scanf("%d",&n);
   L = genRandList(n);
   printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);
   bubbleSortX(L);
   bubbleSortY(L);
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return(0);
}
