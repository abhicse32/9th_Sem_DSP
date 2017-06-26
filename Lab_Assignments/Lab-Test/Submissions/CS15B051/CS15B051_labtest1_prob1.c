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
   node *p,*q;
  int i;
  p=L;
  if(flag==0)
  {
   q=p->nextx;
   while(q->nextx!=NULL)
   {
     printf("(%d,%d) ",q->x,q->y);
     q=q->nextx;
   }
    printf("(%d,%d)",q->x,q->y);
     fflush(stdout);
  }
  if(flag==1)
  {
   q=p->nexty;
   while(q->nexty!=NULL)
   {
     printf("(%d,%d) ",q->x,q->y);
     q=q->nexty;
   }
    printf("(%d,%d)",q->x,q->y);
    fflush(stdout);
  } 
 fflush(stdout);       // Write C-code Here
}

void bubbleSortX ( list L )
{
  node *p,*q,*r,*s;
   p=L;
   int i;
   if(p->nextx!=NULL)
   {
     int a,b,temp;
     s=p->nextx;
     while(s!=NULL)
     {
     while(p->nextx!=NULL)
     {
        q= p->nextx;
        q->x=a;
        q->nextx->x=b;
        if(a>b)
        {
          r=q->nextx;
          q->nextx=q->nextx->nextx;
          r->nextx=q;         
        }
       p->nextx=p->nextx->nextx;
     }
        s=s->nextx;
     }
   } // Write C-code Here
}

void bubbleSortY ( list L )
{
  
    node *p,*q,*r,*s;
   p=L;
   int i;
   if(p->nexty!=NULL)
   {
     int a,b,temp;
     s=p->nexty;
     while(s!=NULL)
     {
     while(p->nexty!=NULL)
     {
        q=p->nexty;
        q->y=a;
        q->nexty->y=b;
        if(a>b)
        {
          r=q->nexty;
          q->nexty=q->nexty->nexty;
          r->nexty=q;         
        }
       p->nexty=p->nexty->nexty;
     }
        s=s->nexty;
     }
   } // Write C-code Here
}

int main ()
{
   list L;
   int n;
   scanf("%d",&n);
   L = genRandList(n);
   printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);
    printf("hello");
   bubbleSortX(L);
   printf("hello");
   bubbleSortY(L);
    printf("hello");
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return(0);
}
