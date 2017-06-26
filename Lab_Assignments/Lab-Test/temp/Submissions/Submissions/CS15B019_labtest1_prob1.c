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
    if(flag==0){
   node *a;
   a=L->nextx;
   
   while(a!=NULL){
   printf("(%d,%d)",a->x,a->y);
   a=a->nextx;
   
    }
   }
   
   if(flag==1){
   node *b;
   b=L->nexty;
   
   while(b!=NULL){
   printf("(%d,%d)",b->x,b->y);
   b=b->nexty;
   
    }
   } 



}

void bubbleSortX ( list L )
{
   // Write C-code Here
    node *a,*b,*d,*c;
   c=L->nextx;
   a=c->nextx;
   d=L;
   b=a->nextx;
   while(a->nextx!=NULL){
                         while(a->x > b->x){
                                               a=b->nextx;
                                               while(1){
                                                          if(d->nextx->x > b->x){
                                                          b=d->nextx;
                                                          d=b; 
                                                          break;  }
                                                          d=d->nextx;      
                                                        }
 						d=L->nextx;
                                             }
                          a=a->nextx;
                          b=b->nextx;                       

                        }
 
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   node *a,*b,*c,*d;
   c=L->nexty;
   a=c->nexty;
   d=L;
   b=a->nexty;
   while(a->nexty!=NULL){
                         while(a->y > b->y){
                                               a=b->nexty;
                                               while(1){
                                                          if(d->nexty-> y > b->y){
                                                          b=d->nexty;
                                                          d=b; 
                                                          break;  }
                                                          d=d->nexty;      
                                                        }
                                               d=L->nexty;
                                             }
                             a=a->nexty;
                             b=b->nexty;                     

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
