#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
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
	node* temp;
	if(L->nextx == NULL){
	}
	else{
		if(flag == 0){
			temp = L->nextx;
			while(1){
				if(temp->nextx == NULL){
					printf("(%d, %d) ", temp->x, temp->y);
					break;
				}
				printf("(%d, %d) ", temp->x, temp->y);
				temp = temp->nextx;
			}
		}
		else{
			//printf("hi\n");
			temp = L->nexty;
			while(1){
				//printf("hi ");
				if(temp->nexty == NULL){
					printf("(%d, %d) ", temp->x, temp->y);
					break;
				}
				printf("(%d, %d) ", temp->x, temp->y);
				temp = temp->nexty;
			}
		}
	}
	fflush(stdout);
}			

void bubbleSortX ( list L )
{
   // Write C-code Here
	int size = 0;
	node* temp = L;
	while(1){
		if(temp->nextx == NULL){
			break;
		}
		size++;
		temp = temp->nextx;
	}
	//printf("%d\n", size);
	//printf("hi\n");
	if(L->nextx == NULL){
	}
	else{
		if(L->nextx->nextx == NULL){
		}
		else{
			//printf("hi\n");
			node* temp1 = L->nextx;
			node* temp2 = L->nextx->nextx;
			node* temp = NULL;
			
			while(size--){
				temp1 = L->nextx;
				temp2 = L->nextx->nextx;
			//	printf("%d %d\n", temp1->x, temp2->x);
			//	printf("hi\n");
				while(1){
					//printf("hi\n");
					if(temp1->x <= temp2->x){
						//printf("%d %d\n", temp1->x, temp2->x);
						if(temp2->nextx == NULL) break;
						else{
							temp1 = temp1->nextx;
							temp2 = temp2->nextx;
						}
					}
					else{
						if(temp2->nextx != NULL){
							temp = temp1;
						//	printf("%d %d\n", temp1->x, temp2->x);
							temp1->nextx = temp2->nextx;
						//	printf("%d %d\n", temp1->x, temp2->x);
							temp2->nextx = temp1;
						//	printf("%d %d\n", temp1->x, temp2->x);
							temp1 = temp2;
						//	printf("%d %d\n", temp1->x, temp2->x);
							temp2 = temp;
						//	printf("%d %d\n", temp1->x, temp2->x);
							//temp2 = temp2->nextx;	
							temp1 = temp1->nextx;
							temp2 = temp2->nextx;
		
						}
						else{
							temp = temp1;
							temp1->nextx == NULL;
							temp2->nextx = temp1;
							temp1 = temp2;
							temp2 = temp;
						//	printf("%d %d\n", temp1->x, temp2->x);
							break;
						}
					}					
				}
				//temp1 = L->nextx;
				//temp2 = L->nextx->nextx;
			}
		}
	}
}

void bubbleSortY ( list L )
{
   // Write C-code Here
	int size = 0;
	node* temp = L;
	while(1){
		if(temp->nexty == NULL){
			break;
		}
		size++;
		temp = temp->nexty;
	}
		
	if(L->nexty == NULL){
	}
	else{
		if(L->nexty->nexty == NULL){
		}
		else{
			node* temp1 = L->nexty;
			node* temp2 = L->nexty->nexty;
			node* temp = NULL;
			
			while(size--){
				while(1){
					if(temp1->y <= temp2->y){
						if(temp2->nexty == NULL) break;
						else{
							temp1 = temp1->nexty;
							temp2 = temp2->nexty;
						}
					}
					else{
						if(temp2->nexty != NULL){
							temp = temp1;
							temp1->nexty = temp2->nexty;
							temp2->nexty = temp1;
							temp1 = temp2;
							temp2 = temp;
							//temp2 = temp2->nexty;	
							temp1 = temp1->nexty;
							temp2 = temp2->nexty;
		
						}
						else{
							temp = temp1;
							temp1->nexty == NULL;
							temp2->nexty = temp1;
							temp1 = temp2;
							temp2 = temp;
							break;
						}
					}					
				}
				temp1 = L->nexty;
				temp2 = L->nexty->nexty;
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
