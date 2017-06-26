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
    int i;
    node *p = L;
   
   if(flag==0){
       for(i=0;p->nextx!=NULL;i++){
         printf("%d%d",p->x,p->y);
         p = p->nextx;
    }
}
   else {
        for(i=0;p->nexty!=NULL;i++){
         printf("%d%d",p->x,p->y);
         p = p->nexty;
    }
}            

void bubbleSortX ( list L )
{
  int i=0;
  int count=0;
  node *p = L;
   for(i=0;p->nextx!=NULL;i++){
    count ++;
    p = p->nextx;
 }
  int k = count;
 for(i=0;i<count;i++){
      node *s = L;
     node *q = L;
     while((s->nextx)->nextx != NULL){
        if((q->x)>((q->nextx)->x)){
           s = q->nextx;
           s-nextx = q;
   }
    q = q->next;


           
        

void bubbleSortY ( list L )
{
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
