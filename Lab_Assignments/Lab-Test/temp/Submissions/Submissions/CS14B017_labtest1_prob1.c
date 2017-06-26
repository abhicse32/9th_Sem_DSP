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
	node *p;
	p=L;
	int i;
	if(flag==0){
		for(1;(p->nextx)!=NULL;){
			p=p->nextx;
			printf("(%d,%d) ",p->x,p->y);
		}
	}
	else{
		for(1;p->nexty!=NULL;){
			p=p->nexty;
			printf("(%d,%d) ",p->x,p->y);
		}
	}


}

void bubbleSortX ( list L )
{
   // Write C-code Here
	node *p,*q,*r,*s;
	int i,j;
	for(i=0;i<N;i++){
		p=L->nextx;
		r=L;
		for(j=1;j<N;j++){
			q=r;
//			p=p->nextx;
			r=p->nextx;
			if((p->x)>((p->nextx)->x)){
				q->nextx=r;
				s=(r->nextx);
				r->nextx=p;
				p->nextx=s;
			}
			else{
				r=p;
				p=p->nextx;
				
			}
		}
	}
}

void bubbleSortY ( list L )
{
   // Write C-code Here
	node *p,*q,*r,*s;
	int i,j;
	for(i=0;i<N;i++){
		p=L->nexty;
		r=L;
		for(j=1;j<N;j++){
			q=r;
//			p=p->nextx;
			r=p->nexty;
			if((p->y)>((p->nexty)->y)){
				q->nexty=r;
				s=(r->nexty);
				r->nexty=p;
				p->nexty=s;
			}
			else{
				r=p;
				p=p->nexty;
				
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
