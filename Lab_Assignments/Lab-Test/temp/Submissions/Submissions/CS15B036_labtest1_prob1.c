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
    if(flag==0)
    {
        node* p;
        p=L;
        while(p->nextx!=NULL)
        {
            printf("(%d,%d) ",p->x,p->y);
            p=p->nextx;
            p=p->nexty;
        }
    }
    else
    {

        node* p;
        p=L;

        while(p->nexty!=NULL)
        {
            printf("(%d,%d) ",p->x,p->y);
            p=p->nextx;
            p=p->nexty;
        }

     }
        fflush(stdout);    
        
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   int i;
   node* r=L;
   node* p=(node*)malloc(sizeof(node));
   p=r->nextx;
   node* q=(node*)malloc(sizeof(node));
   q=p->nextx;
   node* t=L;
   int z=0;
    while(i<100-z)
   {
        t=t->nextx;
        
        i++;
   }
   
   
   while(z<100&&q!=t)
   {
   i=0;
   t=L;
   
    while(i<100-z-1)
   {
        t=t->nextx;
        
        i++;
   }
   
   
   node* temp;

   if(p->x > q->x)
   {
    temp=p;
    r->nextx=q;
    temp->nextx=q->nextx;
    q->nextx=temp;
   }
    r=r->nextx;
    q=q->nextx;
    p=p->nextx;
    z++;
  }

  fflush(stdout);
  
   
   
}

void bubbleSortY ( list L )
{
   // Write C-code Here
    node* r=L;
   node* p=r->nexty;
   node* q=p->nexty;
   node* t=L;
   int i,z=0;
   while(i<100-z)
   {
        t=t->nexty;
        i++;
   }
   while(z<100&&q!=t)
   {
   i=0;
   t=L;
    while(i<100-z-1)
   {
        t=t->nexty;
        i++;
   }
   node* temp;
   if(p->y > q->y)
   {
    temp=p;
    r->nexty=q;
    temp->nexty=q->nexty;
    q->nexty=temp;
    }
    r=r->nexty;
    q=q->nexty;
    p=p->nexty;
    z++;
  }
  fflush(stdout);
  
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
