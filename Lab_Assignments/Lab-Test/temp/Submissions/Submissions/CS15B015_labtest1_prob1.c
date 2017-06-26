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
   if(flag==0){             //print the points in the order of their nextx pointers
    node *currptr=L->nextx;
    while(currptr!=NULL){               //printing the contents of currptr and moving it to right till it becomes NULL
        printf("(%d,%d) ",currptr->x,currptr->y);
        currptr=currptr->nextx;
    }
    printf("\n");
   }
   else{                    //print the points in the order of their nextx pointers
        node *currptr=L->nexty;
        while(currptr!=NULL){           //printing the contents of currptr and moving it to right till it becomes NULL
            printf("(%d,%d) ",currptr->x,currptr->y);
            currptr=currptr->nexty;
        }
        printf("\n");
   }
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   
   int i,j;
   for(i=0;i<(N-1);i++){        //updating nextx such that the x coordinates are sorted
        node *prevptr=L;
        node *currptr=prevptr->nextx;
        node *nextptr=currptr->nextx;
        for(j=0;j<(N-1);j++){
            if((currptr->x)>(nextptr->x)){      //swaping the pointers in the required manner and updating them
                prevptr->nextx=nextptr;
                currptr->nextx=nextptr->nextx;
                nextptr->nextx=currptr;
                prevptr=nextptr;
                nextptr=currptr->nextx;
            }
            else{
                prevptr=currptr;            //updating pointers without disturbing the nodes
                currptr=nextptr;
                nextptr=nextptr->nextx;
            }
        } 
   }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   
   int i,j;
   for(i=0;i<(N-1);i++){            //updating nexty such that the x coordinates are sorted
        node *prevptr=L;
        node *currptr=prevptr->nexty;
        node *nextptr=currptr->nexty;
        for(j=0;j<(N-1);j++){
            if((currptr->y)>(nextptr->y)){      //swaping the pointers in the required manner and updating them
                prevptr->nexty=nextptr;
                currptr->nexty=nextptr->nexty;
                nextptr->nexty=currptr;
                prevptr=nextptr;
                nextptr=currptr->nexty;
            }
            else{                    //updating pointers without disturbing the nodes
                prevptr=currptr;
                currptr=nextptr;
                nextptr=nextptr->nexty;
            }
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
