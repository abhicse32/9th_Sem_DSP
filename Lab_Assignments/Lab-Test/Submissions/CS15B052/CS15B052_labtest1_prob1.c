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
   // Write C-code Here
   
   if(flag == WRT_X)
   {
        node* temp = L->nextx;
        while(temp != NULL)
        {
            printf("(%d,%d) ", temp->x, temp->y);
            temp = temp->nextx;
        }
        //printf("\n");
   }
   else
   {
        node* temp = L->nexty;
        while(temp != NULL)
        {
            printf("(%d,%d) ", temp->x, temp->y);
            temp = temp->nexty;
        }
        //printf("\n");
   }
}

void bubbleSortX ( list L )
{
   // Write C-code Here
    node* prev;
    node* cur;
    node* next;
    node* afternext;
   
    prev = L;
    cur = prev->nextx;
    next = cur->nextx;
    afternext = next->nextx;
   
    int i = 0;
    int size = 0;
   
    node* temp = L->nextx;
    while(temp!=NULL)
    {
        size++;
        temp = temp->nextx;
    }
   
    while(i < size)
    {   
        while(next != NULL)
        {
            if(cur->x > next->x)
            {
                prev->nextx = next;
                next->nextx = cur;
                cur->nextx = afternext;    
            }
            if(next == NULL || afternext == NULL)
            {
                break;
            }
            prev = prev->nextx;
            cur = prev->nextx;
            next = cur->nextx;
            afternext = next->nextx;
        }
        prev = L;
        cur = prev->nextx;
        next = cur->nextx;
        afternext = next->nextx;
        
        i++;
    }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   node* prev;
    node* cur;
    node* next;
    node* afternext;
   
    prev = L;
    cur = prev->nexty;
    next = cur->nexty;
    afternext = next->nexty;
   
    int i = 0;
    int size = 0;
   
    node* temp = L->nexty;
    while(temp!=NULL)
    {
        size++;
        temp = temp->nexty;
    }
   
    while(i < size)
    {   
        while(next != NULL)
        {
            if(cur->y > next->y)
            {
                prev->nexty = next;
                next->nexty = cur;
                cur->nexty = afternext;    
            }
            if(next == NULL || afternext == NULL)
            {
                break;
            }
            prev = prev->nexty;
            cur = prev->nexty;
            next = cur->nexty;
            afternext = next->nexty;
        }
        prev = L;
        cur = prev->nexty;
        next = cur->nexty;
        afternext = next->nexty;
        
        i++;
    }
}

int main ()
{
   list L;
   int n;
   scanf("%d",&n);
   L = genRandList(n);
   printf("\nInitial list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nInitial list with respect to y pointers:\n"); printList(L,WRT_Y);
   bubbleSortX(L);  
   bubbleSortY(L);
   printf("\nFinal list with respect to x pointers:\n"); printList(L,WRT_X);
   printf("\nFinal list with respect to y pointers:\n"); printList(L,WRT_Y);
   return(0);
}
