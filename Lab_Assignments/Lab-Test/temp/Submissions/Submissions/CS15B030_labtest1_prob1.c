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
       while(L->nextx != NULL){
        L = L->nextx;
        printf("(%d,%d) ", L->x, L->y);
       }
   }
   else {
       while(L->nexty != NULL){
        L = L->nexty;
        printf("(%d,%d) ", L->x, L->y);
       }  
   }
   printf("\n");
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   list L1 = L;
   int ct = N - 1;
   while(ct > 0){
       int i = 0;
       while(i < ct ){
        if(L1->nextx->x > L1->nextx->nextx->x){
            list T = L1->nextx;
            L1->nextx = L1->nextx->nextx;
            T->nextx = L1->nextx->nextx;
            L1->nextx->nextx = T;
        }
        L1 = L1->nextx;
        i++;
        
       }
       ct--;
       L1 = L;
   }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   list L1 = L;
   int ct = N - 1;
   while(ct > 0){
       int i = 0;
       while(i < ct ){
        if(L1->nexty->y > L1->nexty->nexty->y){
            list T = L1->nexty;
            L1->nexty = L1->nexty->nexty;
            T->nexty = L1->nexty->nexty;
            L1->nexty->nexty = T;
        }
        L1 = L1->nexty;
        i++;
       }
       ct--;
       L1 = L;
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
