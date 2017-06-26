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
   node *p;
   node *q;
   p = L->nextx;
   q = L->nexty;
   if(flag == WRT_X)
   {
      while(p != NULL)
      {
         printf("(%d,%d) ",(p->x),(p->y));
         p = p->nextx;
      }
   }
   else if(flag == WRT_Y)
   {
      while(q != NULL)
      {
         printf("(%d,%d) ",(q->x),(q->y));
         q = q->nextx;
      }
   }
   printf("\n");
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   int min;
   node *p;
   node *q;
   node *s;
   p = L;
   node *r;
   int i=0;
   int j=0;
   while(p!=NULL)
   {
      r = p;
      p = p->nextx;
      min = p->x;
      q = p;
      while(p!=NULL)
      {
         if((p->x) < min)
         {
            min = p->x;
            q = p;
         }
         j++;
         p = p->nextx;
      }
      p = r;
      s = p->nextx;
      p->nextx = q;
      q->nextx = s;
      p = p->nextx;
      i++;
   }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   int min;
   node *p;
   node *q;
   node *s;
   p = L;
   node *r;
   int i=0;
   int j=0;
   while(p!=NULL)
   {
      r = p;
      p = p->nexty;
      min = p->y;
      q = p;
      while(p!=NULL)
      {
         if((p->y) < min)
         {
            min = p->y;
            q = p;
         }
         j++;
         p = p->nexty;
      }
      p = r;
      s = p->nexty;
      p->nexty = q;
      q->nexty = s;
      p = p->nexty;
      i++;
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
