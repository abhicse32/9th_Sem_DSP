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
   	node *curr;
   	curr = L->nextx;
   	while(curr!=NULL){
   		printf("(%d,%d) ",curr->x,curr->y);
   		curr = curr->nextx;
   	}
   	printf("\n");
   	return;
   }
   else{
   	node *curr;
   	curr = L->nexty;
   	while(curr!=NULL){
   		printf("(%d,%d) ",curr->x,curr->y);
   		curr = curr->nexty;
   	}
   	printf("\n");
   	return;
   }
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   if(L->nextx == NULL) return;
   if(L->nextx->nextx==NULL) return;
   node * curr;
   node * prev;
   node * nxt;
   //initializing pointers
   curr=L->nextx;
   nxt=L->nextx->nextx;
   
   //finding size of linked list
   int size=0;
   while(curr!=NULL){
   	curr  =curr->nextx;
   	size++;
   }
   curr = L->nextx;
   
   int i=0,j=0;
   for(i=0;i<size;i++){
	curr=L->nextx;
   	nxt=L->nextx->nextx;
   	if(curr->x > nxt->x){
	   	curr ->nextx = nxt->nextx;
	   	nxt -> nextx = L -> nextx;
	   	L->nextx = nxt;
   		prev = L->nextx;
   		nxt = curr->nextx;
   	}
   	else{
   		prev=L->nextx;
   		nxt = nxt->nextx;
   		curr = curr->nextx;
   	}
	   for(j=1; j<size-i-1 ; j++){
	   	if(curr->x > nxt->x){
	   		//swapping x positions of curr and nxt
	   		curr-> nextx = nxt->nextx;
	   		nxt -> nextx = prev -> nextx;
	   		prev -> nextx = nxt;
	   	prev=prev->nextx;
	   	nxt = curr -> nextx;
	   	}else{
	   		prev=prev->nextx;
	   		curr=curr->nextx;
	   		nxt=nxt->nextx;
	   	}
	   }
   }
   return;
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   if(L->nexty == NULL) return;
   if(L->nexty->nexty==NULL) return;
   node * curr;
   node * prev;
   node * nxt;
   //initializing pointers
   curr=L->nexty;
   nxt=L->nexty->nexty;
   
   //finding size of linked list
   int size=0;
   while(curr!=NULL){
   	size++;
   	curr  =curr->nexty;
   }
   curr = L->nexty;
   
   int i=0,j=0;
   for(i=0;i<size;i++){
	curr=L->nexty;
   	nxt=L->nexty->nexty;
   	if(curr->y > nxt->y){
	   	curr ->nexty = nxt->nexty;
	   	nxt -> nexty = L -> nexty;
	   	L->nexty = nxt;
   		prev = L->nexty;
   		nxt = curr->nexty;
   	}
   	else{
   		prev=L->nexty;
   		nxt = nxt->nexty;
   		curr = curr->nexty;
   	}
	   for(j=1; j<size-i-1 ; j++){
	   	if(curr->y > nxt->y){
	   		//swapping y positions of curr and nxt
	   		curr-> nexty = nxt->nexty;
	   		nxt -> nexty = prev -> nexty;
	   		prev -> nexty = nxt;
	   	prev=prev->nexty;
	   	nxt = curr -> nexty;
	   	}
	   	else{
	   		prev=prev->nexty;
	   		curr=curr->nexty;
	   		nxt=nxt->nexty;
	   	}
	   }
   }
   return;
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
