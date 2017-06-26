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
   // Write C-code Here\
  if(L==NULL) return;
 
  node *cur=(flag==WRT_X? L->nextx: L->nexty);
  while(cur!=NULL){
    printf("(%d,%d) ",cur->x,cur->y);
    if(flag==WRT_X)
      cur=cur->nextx;
    else if(flag==WRT_Y)
      cur=cur->nexty;
  }
  printf("\n");
}

void bubbleSortX ( list L )
{
   // Write C-code Here
  node* tmp=NULL;
  node* l0=NULL;
  node* l1=L;
  node* l2=L->nextx;

  while(tmp!=L->nextx){
   
    while(l2!=tmp){
    
      if((l1->x)>(l2->x)){

	if(l0!=NULL) l0->nextx=l2;
	l1->nextx=l2->nextx;
	l2->nextx=l1;
	
	if(l0!=NULL)
	  l0=l0->nextx;
	else
	  l0=l2;
	l2=l1->nextx;

      }
      else if(l1->x<=l2->x){

	l0=l1;
       	l1=l1->nextx;
	l2=l2->nextx;
      }
    }
    tmp=l1;
    l0=NULL;
    l1=L;
    l2=l1->nextx;

  }
  
  
  
}

void bubbleSortY ( list L )
{
   // Write C-code Here
  node* tmp=NULL;
  node* l0=NULL;
  node* l1=L;
  node* l2=L->nexty;

  while(tmp!=L->nexty){

    while(l2!=tmp){
   
      if((l1->y)>(l2->y)){

	if(l0!=NULL) l0->nexty=l2;
	l1->nexty=l2->nexty;
	l2->nexty=l1;
	
	if(l0!=NULL)
	  l0=l0->nexty;
	else
	  l0=l2;
	l2=l1->nexty;

      }
      else if(l1->y<=l2->y){

	l0=l1;
       	l1=l1->nexty;
	l2=l2->nexty;
      }
    }
    tmp=l1;
    l0=NULL;
    l1=L;
    l2=l1->nexty;

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
