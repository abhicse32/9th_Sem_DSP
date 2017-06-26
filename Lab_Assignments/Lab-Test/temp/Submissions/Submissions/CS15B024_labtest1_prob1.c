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
   if(flag==0)
   {
   	int p=0;
   	while(L->nextx!=NULL)
   	{
		printf("(%d,%d)",&L->nextx,&L->nexty);
		L->nextx=L->nextx->nextx;
	}
   }
if(flag==1)
{
	int q=0;
	while(L->nexty!=NULL)
	{
			printf("(%d,%d)",&L->nextx,&L->nexty);
			L->nexty=L->nexty->nexty;
	}
			
	
  
 } 
   
}

void bubbleSortX ( list L )
{
   // Write C-code Here
   {
   	int c1=0;
   	int i;
   	int m=0;
   	while(L->nextx!=NULL)
   	{
  		c1++;
  		L->nextx=L->nextx->nextx;
  	}
  	int a[c1];
  	m=0;
  	for(i=0;i<c1 && L->nextx!=NULL;i++)
  	{
  		a[i]=x;
  		m++;
  	}
  	int j=0;
  	int k=0;
  	int temp;
  	for(j=0;j<c1-2;j++)
  	{
  		for(k=0;k<c1-1-j;k++)
  		{
  				if(a[k]>a[k+1])
  				{
  					temp=a[k];
  					a[k]=a[k+1];
  					a[k+1]=temp;
  				}
  		}
  	}
  	x=0;
  	i=0;
  	while(L->nextx!=NULL)
  	{
  		L->nextx=a[i];
  		i++;
  		x++;
  	}
  }
			
}   

void bubbleSortY ( list L )
{
   // Write C-code Here
   int c2=0;
   int i;
  int  y=0;
   while(L->nexty!=NULL)
   {
   	c2++;
   	y++;
   }
   int b[c2];
   y=0;
   for(i=0;i<c2 && L->nexty!=NULL;i++)
   {
   	b[y]=L->nexty;
   	y++;
   }
   	
   int j=0;
   int k=0;
   int temp;
   for(j=0;j<c2-2;j++)
   {
   	for(k=0;k<c2-j-1;k++)
   	{
   		if(b[k]>b[k+1])
   		{
   		temp=b[k];
   		b[k]=b[k+1];
   		b[k+1]=temp;
   		}
   	}
   }
   y=0;
   i=0;
   while(L->nexty!=NULL)
   {
   	L->nexty=b[i];
   	i++;
   	y++;
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
