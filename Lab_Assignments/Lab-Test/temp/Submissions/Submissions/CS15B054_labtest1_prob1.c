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
   node *n
   n = L
   if(flag == 0)
   { 
      while(n->nextx != NULL)
      {
          printf("(%d,%d)",n->nextx->x,n->nextx->y);
          n = n->nextx;
      }
   }
   else if(flag == 1)
   {
      while(n->nexty != NULL)
      {
          printf("(%d,%d)",n->nexty->x,n->nexty->y);
          n = n->nexty;
      }
   }
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   int a,b;
   node *n,*temp= (node *)malloc(sizeof(node));
   node *q = (node *)malloc(sizeof(node));
   n = L;
   q->nextx = NULL;
   q->nexty = NULL;
   q->x = 0,q->y = 0;
   while(n->nexty != NULL)
   {    
        q = n->nexty;
        while(n->nextx != NULL)
        { 
           temp = n;
           n = n->nextx;
           if(n->next->x > n->x)
           {
               a = n->nextx->x;
               b = n->nextx->y;
               n->nextx->x = n->x; 
               n->nextx->y = n->y;
               n->x = a;
               n->y = b;
           }
           n = temp;
           n = n->nextx;
        }
        n->nexty = n;
        n = n->nexty;  
   }
        
}

void bubbleSortY ( list L )
{
   // Write C-code Here
      int a,b;
   node *n,*temp= (node *)malloc(sizeof(node));
   node *q;
   n = L;
   q->nextx = NULL;
   q->nexty = NULL;
   q->x = 0,q->y = 0;
   while(n->nextx != NULL)
   {    
        q = n->nextx;
        while(n->nexty != NULL)
        { 
           temp = n;
           n = n->nextx;
           if(n->next->y > n->y)
           {
               a = n->nexty->x;
               b = n->nexty->y;
               n->nexty->x = n->x; 
               n->nexty->y = n->y;
               n->x = a;
               n->y = b;
           }
           n = temp;
           n = n->nexty;
        }
        n->nextx = q;
        n = n->next;
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
