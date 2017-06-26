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
   node* start;

   if(flag==0)
    {  start=L->nextx;
    }
   else if(flag==1)
    {  start=L->nexty;
    }
   else
    return;

   while(start!=NULL)
   { printf("(%d,%d) ",start->x,start->y);
     if(flag==0)
     start=start->nextx;
     else
     start=start->nexty;
   }  
}

void bubbleSortX ( list L )
{
   int i,j,size=0;
   node* start;
   node* start1;
   node* start2;
   node* start3;
   node* temp1;   node* temp2;   node* temp3;   node* temp4;
   
   start=L->nextx;
   while(start!=NULL)
   { size++;
     start=start->nextx;
   }

   for(i=1;i<=size-1;i++)
   {  start3=L;
      for(j=1;j<=size-i;j++)
       { 
         if(start3->nextx->x > start3->nextx->nextx->x)
          {  temp1=start3;
             temp2=start3->nextx;
             temp3=start3->nextx->nextx;
             temp4=start3->nextx->nextx->nextx;

             start3->nextx=temp3;
             start3->nextx->nextx=temp2;
             start3->nextx->nextx->nextx=temp4;
          }
         start3=start3->nextx;
       }
   }
}


void bubbleSortY ( list L )
{
   int i,j,size=0;
   node* start;
   node* start1;
   node* start2;
   node* start3;
   node* temp1;   node* temp2;   node* temp3;   node* temp4;

   start=L->nexty;
   while(start!=NULL)
   { size++;
     start=start->nexty;
   }

   for(i=1;i<=size-1;i++)
   {  start3=L;
      for(j=1;j<=size-i;j++)
       { 
         if(start3->nexty->y > start3->nexty->nexty->y)
          {  temp1=start3;
             temp2=start3->nexty;
             temp3=start3->nexty->nexty;
             temp4=start3->nexty->nexty->nexty;

             start3->nexty=temp3;
             start3->nexty->nexty=temp2;
             start3->nexty->nexty->nexty=temp4;
          }
         start3=start3->nexty;
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
   bubbleSortY(L);
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return(0);
}
