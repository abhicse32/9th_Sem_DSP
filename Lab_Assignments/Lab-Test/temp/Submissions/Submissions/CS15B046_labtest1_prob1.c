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
   if(flag==0) //WRT_X
    {  list l1=L->nextx;
      while(l1!=NULL)
         {
            printf("(%d,%d) ",l1->x,l1->y);
            l1=l1->nextx;
         }
         printf("\n");
    }
    else //WRT_Y
    {
       list l1=L->nexty;
      while(l1!=NULL)
        {
            printf("(%d,%d) ",l1->x,l1->y);
            l1=l1->nexty;
         }
         printf("\n");

    }
}

void bubbleSortX ( list L )
{
   
   list l1=L->nextx;
   int i,j;
   
  node* front=(node *)malloc(sizeof(node));
  node* prev=(node *)malloc(sizeof(node));
  node* fwd=(node *)malloc(sizeof(node));
  front=L->nextx;
   for(i=0;i<N-1;i++)
   {


      for(j=0;j<N-i-1;j++)
      {
         
         if(l1->x > l1->nextx->x)
         {
            if(j==0)
               front=l1->nextx; //Store the new front node in case swap takes place
            
            fwd=l1->nextx->nextx; //Store the the next node in forward direction since the nextx link will be broken

            l1->nextx->nextx=l1;

            if(j!=0)
             prev->nextx=l1->nextx;

            prev=l1->nextx; // stores the node previous to the current node for next iteration
            l1->nextx=fwd;
            
         }
         else 
            {
               prev=l1; //previous for next iteration will be same as current
               l1=l1->nextx;
            }
      }
      
      L->nextx=front; //in case front node changes
      l1=L->nextx;
   }

   // Write C-code Here
}

void bubbleSortY ( list L )
{
  
   int i;
   
   int j;

   list l1=L->nexty;

  node* front=(node *)malloc(sizeof(node));
  node* prev=(node *)malloc(sizeof(node));
  node* fwd=(node *)malloc(sizeof(node));
  front=L->nexty;

   for(i=0;i<N-1;i++)
   {


      for(j=0;j<N-i-1;j++)
      {
         if(l1->y > l1->nexty->y)
         {
            if(j==0)
               front=l1->nexty; //Store the new front node in case swap takes place
            
            fwd=l1->nexty->nexty; //Store the the next node in forward direction since the nexty link will be broken

            l1->nexty->nexty=l1;

            if(j!=0)
               prev->nexty=l1->nexty;

            prev=l1->nexty; // stores the node previous to the current node for next iteration

            l1->nexty=fwd;
            
         }
         else
            {
               prev=l1; //previous for next iteration will be same as current
               l1=l1->nexty;
            }
      }
     
      L->nexty=front; //in case front node changes
      l1=L->nexty;
   }

   // Write C-code Here
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
