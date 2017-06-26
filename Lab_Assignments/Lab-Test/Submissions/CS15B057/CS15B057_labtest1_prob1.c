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
   // Write C-code Here
	if(L==NULL) return;	
	if(flag==WRT_X){
   		node* p=L;
		p=p->nextx;		
		while(p!=NULL){
			printf("(%d,%d) ",p->x,p->y);
			p=p->nextx;
		}
	}
	else{
		node* p=L;
		p=p->nexty;
		while(p!=NULL){
			printf("(%d,%d) ",p->x,p->y);
			p=p->nexty;
		}
	}
}

void bubbleSortX ( list L )
{
   // Write C-code Here
	if(L==NULL) return;
	node* p=L;
	node* q=L;
	p=p->nextx;
	q=q->nextx;
	long long int len=0;
	while(p!=NULL){
		len++;
		p=p->nextx;
	}
	long long int i,j;
	for(i=0;i<len;i++){
		q=L->nextx;
		node* temp=L;
		for(j=0;j<len-i-1;j++){
			if(q->nextx->x<q->x){
				if(j==0){
					node* save=q->nextx;
					q->nextx=q->nextx->nextx;
					save->nextx=q;
					L->nextx=save;
				}
				else{
					node* save=q->nextx;
					q->nextx=q->nextx->nextx;
					save->nextx=q;
					temp->nextx=save;
				}
				temp=temp->nextx;
			}
			else{
				q=q->nextx;
				temp=temp->nextx;
			}
		}
	}					
}

void bubbleSortY ( list L )
{
   // Write C-code Here
	if(L==NULL) return;
	node* p=L;
	node* q=L;
	p=p->nexty;
	q=q->nexty;
	long long int len=0;
	while(p!=NULL){
		len++;
		p=p->nexty;
	}
	long long int i,j;
	for(i=0;i<len;i++){
		q=L->nexty;
		node* temp=L;
		for(j=0;j<len-i-1;j++){
			if(q->nexty->y<q->y){
				if(j==0){
					node* save=q->nexty;
					q->nexty=q->nexty->nexty;
					save->nexty=q;
					L->nexty=save;
				}
				else{
					node* save=q->nexty;
					q->nexty=q->nexty->nexty;
					save->nexty=q;
					temp->nexty=save;					
				}
				temp=temp->nexty;
			}
			else{
				q=q->nexty;
				temp=temp->nexty;
			}
		}
	}					
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
