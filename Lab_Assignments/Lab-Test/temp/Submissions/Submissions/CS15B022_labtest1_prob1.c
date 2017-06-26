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
   if(flag == WRT_X)
   {
        node *p;
        p = L->nextx;
        while(p != NULL)
        {
            printf("(%d,%d) ",p->x,p->y);
            p = p->nextx;
         }
    }
    else
    {
        node *q;
        q = L->nexty;
        while(q != NULL)
        {
            printf("(%d,%d) ",q->x,q->y);
            q = q->nexty;
        }
     }

}

void bubbleSortX ( list L )
{
    int size = 0;
    node *q;
    node *r;
    node *t;
    node *temp;
    int i = 0;
    int j = 0;
    node *p = L->nextx;
    while(p != NULL)
    {
        size = size + 1;
        p = p->nextx;
    }
    for(i = 0;i<size;i++)
    {
        q = L;
        r = L->nextx;
        t = r->nextx;
        while(t != NULL)
        {
            if(r->x <= t->x)
            {
                q = q->nextx;
                r = r->nextx;
                t = t->nextx;
            }
            else
            {
                r->nextx = t->nextx;
                t->nextx = r;
                q->nextx = t;
                temp = r;
                r = t;
                t = temp;
                q = q->nextx;
                r = r->nextx;
                t = t->nextx;
             }
        
       }     
                   
}
}

void bubbleSortY ( list L )
{
   int size = 0;
    node *q;
    node *r;
    node *t;
    node *temp;
    int i = 0;
    int j=0;
    node *p = L->nexty;
    while(p != NULL)
    {
        size = size + 1;
        p = p->nexty;
    }
    for(i = 0;i<size;i++)
    {
        q = L;
        r = L->nexty;
        t = r->nexty;
        while(t!= NULL)
        {
            if(r->y <= t->y)
            {
                q = q->nexty;
                r = r->nexty;
                t = t->nexty;
            }
            else
            {
                r->nexty = t->nexty;
                t->nexty = r;
                q->nexty = t;
                temp = r;
                r = t;
                t = temp;
                q = q->nexty;
                r = r->nexty;
                t = t->nexty;
             }
        
       }     
    
}
}

int main ()
{
   list L;

   L = genRandList(N);
   printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);fflush(stdout);
   bubbleSortX(L);
   bubbleSortY(L);
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return(0);
}
