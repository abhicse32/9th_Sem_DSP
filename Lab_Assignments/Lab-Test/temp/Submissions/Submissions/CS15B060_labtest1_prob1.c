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
{ node *i,*j;
  // Write C-code Here
  if(flag==0)
  { for(i=L->nextx;i!=NULL;i=i->nextx)
    printf("(%d,%d) ",i->x,i->y);
    }
    
    else if(flag==1)
  { for(i=L->nexty;i!=NULL;i=i->nexty)
    printf("(%d,%d) ",i->x,i->y);
    }
  
  
  
  
  
  
  
}

void bubbleSortX ( list L )
{  int count=0;
   // Write C-code Here
   node *head=L;
  node *i,*j;
  for(i=L->nextx;i!=NULL;i=i->nextx)
  count++;
 // printf("%d",count);
  int t,l,k=0;
   int *a=(int*)malloc(count*sizeof(int));
   for(i=L->nextx;i!=NULL;i=i->nextx)
 {  a[k]=i->x;k++;}
  // printf("\n");
 
    /*for(k=0;k<100;k++)
         printf("%d ",a[k]);*/
  /*  for(k=0;k<99;k++)
    { 
      for(l=0;l<99-k;l++)
      { if(a[l]>a[l+1])
        {t=a[l];
         a[l+1]=a[l];
         a[l+1]=t;
         }
         }
         }*/
         for(k=1;k<100;k++)
         {t=a[k];
          for(l=k-1;l>=0&&t<a[l];l--)
           a[l+1]=a[l];
            a[l+1]=t;
            }
         
         /*printf("\n");
         for(k=0;k<100;k++)
         printf("%d ",a[k]);*/
         
         
         
          j=L;
         node*cur;
         for(k=0;k<count;k++)
         { 
           for(cur=L->nexty;cur!=NULL;cur=cur->nexty)
           { if(cur->x==a[k])
              {j->nextx=cur;
                j=cur;}
               
              }
             // j->nextx=NULL;
              
              
              }
              j->nextx=NULL;
         
         
         
         
         
         
   
}

void bubbleSortY ( list L )
{
   // Write C-code Here
   int count=0;
   // Write C-code Here
   node *head=L;
  node *i,*j;
  for(i=L->nexty;i!=NULL;i=i->nexty)
  count++;
  //printf("%d",count);
  int t,l,k=0;
   int *a=(int*)malloc(count*sizeof(int));
   for(i=L->nexty;i!=NULL;i=i->nexty)
 {  a[k]=i->y;k++;}
   //printf("\n");
 
   // for(k=0;k<100;k++)
      //   printf("%d ",a[k]);
  /*  for(k=0;k<99;k++)
    { 
      for(l=0;l<99-k;l++)
      { if(a[l]>a[l+1])
        {t=a[l];
         a[l+1]=a[l];
         a[l+1]=t;
         }
         }
         }*/
         for(k=1;k<100;k++)
         {t=a[k];
          for(l=k-1;l>=0&&t<a[l];l--)
           a[l+1]=a[l];
            a[l+1]=t;
            }
         
      //   printf("\n");
        // for(k=0;k<100;k++)
        // printf("%d ",a[k]);
         
         
         
          j=L;
         node*cur;
         for(k=0;k<count;k++)
         { 
           for(cur=L->nextx;cur!=NULL;cur=cur->nextx)
           { if(cur->y==a[k])
              {j->nexty=cur;
                j=cur;}
               
              }
             // j->nextx=NULL;
              
              
              }
              j->nexty=NULL;
         
   
   
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
