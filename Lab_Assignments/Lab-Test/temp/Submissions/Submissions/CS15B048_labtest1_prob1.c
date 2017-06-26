#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
//#define N 3
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
   if(flag == 0){
	 // Wrt X
	 // To avoid printing dummy node
	 list temp = L->nextx;
	 while(temp != NULL){
	   printf("(%d,%d) ", temp->x, temp->y);
	   temp = temp->nextx;
	 }
   }
   else {
	 // Wrt y
	 list temp = L->nexty;
	 while(temp != NULL){
	   printf("(%d,%d) ", temp->x, temp->y);
	   temp = temp->nexty;
	 }
   }
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   list p1 = (node*) malloc(sizeof(node));
   list p2, prev;
   int i, flag = 0;

   for(i = 0; i < N && p1 != NULL; i++){
	 // Each time starting from 1st node
	 p1 = L->nextx;
	 // Holds position of previous element while exchanging
	 prev = L;
	 p2 = p1;
	 while(p2 != NULL){
	   flag = 0;
	   if(p2->nextx != NULL){
		 // Condition for swapping
		 if(p2->x > p2->nextx->x){
		   // Code to swap the pointers
		   // prev --> p2 --> p2->nextx --> p2->nextx->nextx(temp)
		   list temp = p2->nextx->nextx;
		   prev->nextx = p2->nextx;
		   p2->nextx->nextx = p2;
		   p2->nextx = temp;
		   flag = 1;
		 }
	   }
	   // If swapping did not occur, then p2 should be manually changed 
	   if(flag == 0)
		 p2 = p2->nextx;
	   // Else p2 is moved to next position and needs to be compared again so p2 value is as such
	   if(prev-> nextx == NULL)
		 break;
	   prev = prev->nextx;
	 }
   }
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   list p1 = (node*) malloc(sizeof(node));
   list p2, prev;
   int i, flag = 0;
   for(i = 0; i < N && p1 != NULL; i++){
	 p1 = L->nexty;
	 prev = L;
	 p2 = p1;
	 while(p2 != NULL){
	   flag = 0;
	   if(p2->nexty != NULL){
		 if(p2->y > p2->nexty->y){
		   // Code to swap the pointers
		   // prev --> p2 --> p2->nexty --> p2->nexty->nexty(temp)
		   list temp = p2->nexty->nexty;
		   prev->nexty = p2->nexty;
		   p2->nexty->nexty = p2;
		   p2->nexty = temp;
		   flag = 1;
		 }
	   }
	   if(flag == 0)
		 p2 = p2->nexty;
	   if(prev-> nexty == NULL)
		 break;
	   prev = prev->nexty;
	 }
	 //p1 = p1->nexty;
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
