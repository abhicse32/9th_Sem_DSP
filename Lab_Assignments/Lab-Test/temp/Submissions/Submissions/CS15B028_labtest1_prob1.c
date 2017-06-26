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
      L=L->nextx;
      while(L!=NULL)
      {
         printf("(%d,%d) ",L->x,L->y);
         L=L->nextx;
      }
      printf("\n");
   }
   else if(flag==1)
   {
      L=L->nextx;
      while(L!=NULL)
      {
         printf("(%d,%d) ",L->x,L->y);
         L=L->nexty;
      }
      printf("\n");
   }
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   int n=0,i;
   list p;
   p=L;
   while(p!=NULL)
   {
      n++;
      p=p->nextx;
   }
   for(i=0;i<n-1;i++)
   {
      p=L;
      while(p->nextx!=NULL)
      {
         if((p->nextx!=NULL)&&p->x > (p->nextx)->x)
         {
            /*list t=p->nextx;
            list t1=(p->nextx)->nextx;
            (p->nextx)->nextx=p;
            p->nextx=t1;
            p=t;*/
            int t;
            t=p->x;
            p->x=(p->nextx)->x;
            (p->nextx)->x=t;
            t=p->y;
            p->y=(p->nextx)->y;
            (p->nextx)->y=t;           
         }            
         else p=p->nextx;
      }
   }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   int n=0,i;
   list p;
   p=L;
   while(p!=NULL)
   {
      n++;
      p=p->nexty;
   }
   for(i=0;i<n-1;i++)
   {
      p=L;
      while(p->nexty!=NULL)
      {
         if((p->nexty!=NULL)&&p->y > (p->nexty)->y)
         {
            int t;
            t=p->y;
            p->y=(p->nexty)->y;
            (p->nexty)->y=t;
            t=p->x;
            p->x=(p->nexty)->x;
            (p->nexty)->x=t;
         }            
         p=p->nexty;
      }
   }
}

int main ()
{
   list L;

   L = genRandList(N);
   printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);
   bubbleSortX(L); 
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   bubbleSortY(L);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return 0;
}
