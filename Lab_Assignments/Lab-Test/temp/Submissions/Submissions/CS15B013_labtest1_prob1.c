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
{  int x,y;
   // Write C-code Here
  if(flag==0)
  {
   list alongx=L->nextx;
   while(alongx!=NULL)
   {
    x=alongx->x;
    y=alongx->y;
    
    printf("(%d,%d) ",x,y);
    alongx=alongx->nextx;
   }
  }
  if(flag==1)
  {
   list alongy=L->nexty;
   while(alongy!=NULL)
   {
    x=alongy->x;
    y=alongy->y;
    
    printf("(%d,%d) ",x,y);
    alongy=alongy->nexty;
   }
  } 

}

void bubbleSortX ( list L )
{
   // Write C-code Here
 int a=0;
 list xl;
 list frontx;
 int tempx,tempy;
 xl=L->nextx;
 frontx=xl->nextx;
 while(1)
 {a=0;
 while(frontx!=NULL)
 {
  if((xl->x) > (frontx->x) )
  {
   tempx=xl->x;
   tempy=xl->y;

   xl->x=frontx->x;
   xl->y=frontx->y;

   frontx->x=tempx;
   frontx->y=tempy;
   a=1;
  }

  xl=frontx;
  frontx=frontx->nextx;
 }

 if(a==0)
  break;

 xl=L->nextx;
 frontx=xl->nextx;
 }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
 int cont;int end=0;
 list y=L;
 list temp;
 list xl;
 list frontx;
 xl=L->nextx;
 list tempnode;
 list yl=L->nexty;
 int i=0;
 frontx=xl;

/* while(y!=NULL)
 {
  temp=y->nexty;
  y->nexty=NULL;

  y=temp;
 }*/

 while(end==0)
 {
 while(frontx!=NULL)
 {yl=L;
  tempnode=frontx;
  if((tempnode->x) > (frontx->x) )
  {
   tempnode=frontx;   
  }

  frontx=frontx->nextx;
  while(yl!=NULL)
  {
   if(frontx==yl)
    { frontx=frontx->nextx;yl=L;}
   
   yl=yl->nexty;
  }
 }
  yl=L;
  
  while(yl->nexty!=NULL)
    yl=yl->nexty;

  yl->nexty =tempnode;
  tempnode->nexty=NULL;

   xl=L;
   frontx=L->nextx;
   yl=L;
  cont=0;
  while(xl!=NULL)
  {
   if(yl==NULL)
    { cont=1;end=1;break;}

   xl=xl->nextx;
   yl=yl->nexty;
  }
  
  if(cont==0)
   break;
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
