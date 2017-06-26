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
        
   if(flag == WRT_X){     
        node * temp=L;
        if(temp->nextx==NULL) return;
        else{
                temp=temp->nextx;
                while(temp!=NULL){
                        printf("(%d,%d) ",temp->x,temp->y);
                        temp=temp->nextx;
                }     
                
   
        }
               
   }
   if(flag == WRT_Y){
        
        node * temp2=L;
        if(temp2->nexty==NULL) return;
        else{        
                temp2=temp2->nexty;
                while(temp2!=NULL){
                        printf("(%d,%d) ",temp2->x,temp2->y);
                        temp2=temp2->nexty;
                             
   
                }
        }   
        }
}        
void bubbleSortX ( list L )
{
   if(L->nextx==NULL) return;
   else if(L->nextx->nextx==NULL) return;
   else{
        node *temp1,*temp2,*temp3,*temp4,*temp5,*temp6;
        int x;
        int y;       
        temp4=L;
        temp6=L;
        int i=100;
        temp1=L->nextx;
        temp2=temp1->nextx;
        temp5=L;
        while(temp5->next!=NULL){
                temp5=temp5->nextx;
                if(temp1->data>=temp2->data){
                        temp6=temp1;
                        temp2=temp2->next;
                
                }
        }
        while(temp4->nextx!=NULL&&i--){
                                
        temp1=temp4;
        temp2=temp2->next;
        while(temp2!=NULL){
                if(temp2->data<temp1->data&&temp2->data!=x){
                        temp4->next=temp2;
                        x=temp2->data;           
                }
                temp3=temp4;
                temp4->next=temp1;
        }
        temp4=temp4->next;
             
}
        temp6->next=NULL;
}   

void bubbleSortY ( list L )
{
  if(L->nexty==NULL) return;
   else if(L->nexty->nexty==NULL) return;
   else{
        node *temp1,*temp2,*temp3,*temp4,*temp5,*temp6;
        int x;
        int y;       
        temp4=L;
        temp6=L;
        int i=100;
        temp1=L->nexty;
        temp2=temp1->nexty;
        temp5=L;
        while(temp5->next!=NULL){
                temp5=temp5->nexty;
                if(temp1->data>=temp2->data){
                        temp6=temp1;
                        temp2=temp2->next;
                
                }
        }
        while(temp4->nexty!=NULL&&i--){
                                
        temp1=temp4;
        temp2=temp2->next;
        while(temp2!=NULL){
                if(temp2->data<temp1->data&&temp2->data!=x){
                        temp4->nexty=temp2;
                        x=temp2->data;           
                }
                temp3=temp4;
                temp4->nexty=temp1;
        }
        temp4=temp4->nexty;
             
}
        temp6->nexty=NULL;
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
