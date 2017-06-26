/*
Program to implement double linked list with x,y coordinates and bubble sort the linked list
Name: Harshavardhan.P.K.
Roll No: CS15B061
Date Sept 19, 2016
*/
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
	//in case of print through nextx pointers
	if(flag == WRT_X){
		//initialise cur to first x node
		list cur = L->nextx;
		//Transverse the LL till t reaches the end
		while(cur){
			printf("(%d,%d) ",cur->x,cur->y);
			cur=cur->nextx;
		}
	}
	//in case of print through nextx pointers
	if(flag == WRT_Y){
		list cur=L->nexty;
		//Transverse the LL till t reaches the end
		while(cur){
			printf("(%d,%d) ",cur->x,cur->y);
			cur=cur->nexty;
		}
	}
}

void bubbleSortX ( list L )
{
   // Write C-code Here
	int i,j;
	for(i=0;i<N-1;i++){
/*
prev - it stores address of pointer before cur
cur - it points to current node
next - points to next node to cur
temp
*/
		list prev, cur, next,temp;
		prev=L;
		cur=L->nextx;
		next=L->nextx->nextx;
		for(j=0;j<N-i-1;j++){
			if(cur->x > next->x){
				prev->nextx=next;
				cur->nextx=next->nextx;
				next->nextx=cur;
				prev=next;
				next = cur->nextx;
			}
			else{
				prev=cur;
				cur=next;
				next=next->nextx;
			}
		}

	}

}

void bubbleSortY ( list L )
{
   // Write C-code Here

	int i,j;
	for(i=0;i<N-1;i++){
		list prev, cur, next,temp;
		prev=L;
		cur=L->nexty;
		next=L->nexty->nexty;
		for(j=0;j<N-i-1;j++){
			if(cur->y > next->y){
				prev->nexty=next;
				cur->nexty=next->nexty;
				next->nexty=cur;
				prev=next;
				next = cur->nexty;
			}
			else{
				prev=cur;
				cur=next;
				next=next->nexty;
			}
		}

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
