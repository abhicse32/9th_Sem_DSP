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

void printList ( list L, int flag )
{
   node *p;
   int cnt = 0;

   p = L;
   if (flag == WRT_X) {
      while (p -> nextx != NULL) {
         printf("(%4d,%4d) ", p -> nextx -> x, p -> nextx -> y);
         p = p -> nextx;
         if (++cnt == 6) { printf("\n"); cnt = 0; }
      }
   } else {
      while (p -> nexty != NULL) {
         printf("(%4d,%4d) ", p -> nexty -> x, p -> nexty -> y);
         p = p -> nexty;
         if (++cnt == 6) { printf("\n"); cnt = 0; }
      }
   }
   if (cnt) printf("\n");
}

void bubbleSortX ( list L )
{
   node *p, *q, *r, *lastpos;

   if (L -> nextx == NULL) return;  /* Empty list */

   lastpos = NULL;
   while (lastpos != L -> nextx -> nextx) {
      p = L;
      while (p -> nextx -> nextx != lastpos) {
         if (p -> nextx -> x > p -> nextx -> nextx -> x) {
            q = p -> nextx; r = q -> nextx;
            q -> nextx = r -> nextx;
            p -> nextx = r;
            r -> nextx = q;
         }
         p = p -> nextx;
      }
      lastpos = p -> nextx;
   }
}

void bubbleSortY ( list L )
{
   node *p, *q, *r, *lastpos;

   if (L -> nexty == NULL) return;  /* Empty list */

   lastpos = NULL;
   while (lastpos != L -> nexty -> nexty) {
      p = L;
      while (p -> nexty -> nexty != lastpos) {
         if (p -> nexty -> y > p -> nexty -> nexty -> y) {
            q = p -> nexty; r = q -> nexty;
            q -> nexty = r -> nexty;
            p -> nexty = r;
            r -> nexty = q;
         }
         p = p -> nexty;
      }
      lastpos = p -> nexty;
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
   exit(0);
}
