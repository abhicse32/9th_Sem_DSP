/*
*On 19th September 2016
*Written by Teratipally Srikar,CS15B037
*This program manipulates 2 a
*sorts a linked list in 2 directions
*/

#include <stdio.h>      /*Including the required header files*/
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
void printList ( list L, int flag ) /*This function prints the linked list in given direction*/
{
   if(flag==0)
                {
                    node* current = L->nextx;
                    while(current!=NULL)        /*Current travles the whole linked list in a direction & rpints. If it hits a null then it will stop*/
                    {
                        printf("(%d,%d) ",current->x,current->y);
                        current = current->nextx;
                    }
                }

    else        {
                    node* current = L->nexty;
                    while(current!=NULL)        /*Current travles the whole linked list in a direction & rpints. If it hits a null then it will stop*/
                    {
                        printf("(%d,%d) ",current->x,current->y);
                        current = current->nexty;
                    }
                }
    printf("\n");
}

void bubbleSortX ( list L )     /*This function sorts a linked list in x-direction by using bubble sort algorithm*/
{
   // Write C-code Here
    
    int i;  /*Counter*/
    int j;  /*Counter*/

    for(i=1;i<N;i++)
    {
        node* current = L;
        for(j=0;j<(N-i);j++)
        {
            node* a = current;
            node* b = a->nextx;
            node* c = b->nextx;
            node* d = c->nextx;

            if((b->x)>(c->x))   {                   /*Since if it is larger then we have to swap it*/
                                    a->nextx = c;
                                    b->nextx = d;
                                    c->nextx = b;
                                }
            current = current->nextx;        
        }
    } 
                                                    
}

void bubbleSortY ( list L )     /*This function sorts a linked list in x-direction by using bubble sort algorithm*/
{
   // Write C-code Here
    int i;      /*Counter*/
    int j;      /*Counter*/

    for(i=1;i<N;i++)
    {
        node* current = L;
        for(j=0;j<(N-i);j++)
        {
            node* a = current;
            node* b = a->nexty;
            node* c = b->nexty;
            node* d = c->nexty;

            if((b->y)>(c->y))   {                   /*Since if it is larger then we have to swap it*/
                                    a->nexty = c;
                                    b->nexty = d;
                                    c->nexty = b;
                                }

            current = current->nexty;
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
