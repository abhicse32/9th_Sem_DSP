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
void printList ( list L, int flag )		// Write C-code Here
{
	node *temp;	//temp is a temporary pointer to node
	if(flag == 0)	//If flag==0, then print with respect to x pointers
	{
		temp = L->nextx;
		while(temp!=NULL)
		{
			printf("(%d,%d) ",temp->x,temp->y);
			temp=temp->nextx;
		}
	}	
	
	else		//else print with respect to y pointers
	{
		temp = L->nexty;
		while(temp!=NULL)
		{
			printf("(%d,%d) ",temp->x,temp->y);
			temp=temp->nexty;
		}
	}
		
	printf("\n");
   return;
	
}

void bubbleSortX ( list L )		// Write C-code Here
{
   node *temp1,*temp2,*temp3;
   int length=0;
   int i,j;		//Loop variables for bubble sort
   temp1 = L->nextx;
   while(temp1!=NULL)	//Getting the length of the list
   {
   		length++;
   		temp1=temp1->nextx;
   }
   
   if( length==1)
   {
   	return;
   }
   
   temp1 = L;
   temp2 = L->nextx;
   temp3 = temp2->nextx;
   
   for(i=0;i<length;++i)
   {
   
   	temp1 = L;
   	temp2 = L->nextx;
   	temp3 = temp2->nextx;
   	
   	for(j=0;j<length-i-1;++j)	//check
   	{	
   		if(temp2->x > temp3->x)
   		{
   			temp1->nextx = temp3;	//If not in order, then swap the x pointers
   			temp2->nextx = temp3->nextx;
   			temp3->nextx = temp2;
   			
   			temp1 = temp3;	//Reassigning the pointers
   			temp3 = temp2->nextx;
   		}
   		else
   		{
   			temp1 = temp1->nextx;
   			temp2 = temp2->nextx;
   			temp3 = temp3->nextx;
   		}
   	}
   
   }
   
   
   return;
   
   	
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   node *temp1,*temp2,*temp3;
   int length=0;
   int i,j;		//Loop variables for bubble sort
   temp1=L->nexty;
   while(temp1!=NULL)	//Getting the length of the list
   {
   		length++;
   		temp1=temp1->nexty;
   }
   
   if( length==1)
   {
   	return;
   }
   temp1 = L;
   temp2 = L->nexty;
   temp3 = temp2->nexty;
   
   for(i=0;i<length;++i)
   {
   
   	temp1 = L;
   	temp2 = L->nexty;
   	temp3 = temp2->nexty;
   	
   	for(j=0;j<length-i-1;++j)	//check
   	{	
   		
   		if(temp2->y > temp3->y)
   		{
   			temp1->nexty = temp3;	//If not in order, then swap the x pointers
   			temp2->nexty = temp3->nexty;
   			temp3->nexty = temp2;
   			
   			temp1 = temp3;	//Reassigning the pointers
   			temp3 = temp2->nexty;
   		}
   		else
   		{
   			temp1 = temp1->nexty;
   			temp2 = temp2->nexty;
   			temp3 = temp3->nexty;
   		}
   	}
   
   }
   
   return;

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
