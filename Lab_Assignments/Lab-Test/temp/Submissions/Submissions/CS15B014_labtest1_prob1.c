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
   node*next;
   
   if(flag==0){
   	next=L->nextx;
   	while(next!=NULL){
   		printf("(%d,%d) ",next->x,next->y);
   		
   		
   		next=next->nextx;
   	}
   	
   }
   else{
   	next=L->nexty;
   	while(next!=NULL){
   		printf("(%d,%d) ",next->x,next->y);
   		
   		
   		next=next->nexty;
   	}
   }
   
   printf("\n");
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   node*next;
   int count = 0;
   next=L->nextx;
   while(next!=NULL)
   {
   	count++;
   	next=next->nextx;
   }
   node*next0=L;
   node*temp;
   int i=0;
   next=L->nextx;
   if(next==NULL)
   	return;
   node*next1=next->nextx;
   for(i=0;i<=count+1;i++){
   	 node*next0=L;
	   node*temp;
	   next=L->nextx;
	   node*next1=next->nextx;
   	while(next1!=NULL){
   		if(next->x>next1->x)
   		{
   			temp=next;
   			next0->nextx=next1;
   			next->nextx=next1->nextx;
   			next1->nextx=temp;
   		}
   		next0=next0->nextx;
   		next=next0->nextx;
   		next1=next->nextx;
   	}
   }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
    node*next;
   int count = 0;
   next=L->nexty;
   while(next!=NULL)
   {
   	count++;
   	next=next->nexty;
   }
   node*next0=L;
   node*temp;
   int i=0;
   next=L->nexty;
   if(next==NULL)
   	return;
   node*next1=next->nexty;
   for(i=0;i<=count+1;i++){
   	 node*next0=L;
	   node*temp;
	   next=L->nexty;
	   node*next1=next->nexty;
   	while(next1!=NULL){
   		if(next->y>next1->y)
   		{
   			temp=next;
   			next0->nexty=next1;
   			next->nexty=next1->nexty;
   			next1->nexty=temp;
   		}
   		next0=next0->nexty;
   		next=next0->nexty;
   		next1=next->nexty;
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
