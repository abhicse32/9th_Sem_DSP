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
   if(flag == 0)
   {
      node *p = (list)malloc(sizeof(node));
      p = L;
      while(p != NULL)
      {
         printf("(%d,%d) ",p->x,p->y);
         p = p->nextx;
      }
      printf("\n");
   }
   if(flag == 1)
   {
      node *p = (list)malloc(sizeof(node));
      p = L;
      while(p != NULL)
      {
         printf("(%d,%d) ",p->x,p->y);
         p = p->nexty;
      }
      printf("\n");
   }
}

void bubbleSortX ( list L )
{
   // Write C-code Here
      int i;
      node *p = (list)malloc(sizeof(node));
      i=0;
      p=L;
      while(i<N)
      {
         int j=0;
         while(j<(N-i))
         {
               if(p->nextx != NULL){
                 if((p->x) > ((p->nextx)->x))
                 {
                      node *t = (node *)malloc(sizeof(node));
         
                      t->x = (p->nextx)->x;
                      t->y = (p->nextx)->y;
                     p->nextx = (p->nextx)->nextx;
                     t->nextx = p;
                     p=t;
                }
            }
             j++;
         }
        i++;
      }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
      int i,s;
      s=0;
      node *p = (list)malloc(sizeof(node));
      p = L;
      while(p != NULL)
      {
         s++;
         p = p->nexty;
      }
      i=0;
           p=L;
      while(i<s)
      {
         int j=0;
         while(j < (s-i))
         {
               
               if(p->nexty != NULL){
                 if((p->y) > ((p->nexty)->y))
                 {
                      node *t = (list)malloc(sizeof(node));
                      t->x = (p->nexty)->x;
                      t->y = (p->nexty)->y;
                     p->nexty = (p->nexty)->nexty;
                     t->nexty = p;
                     p=t;
                }
                       p = p->nexty;}
             j++;
         }
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
