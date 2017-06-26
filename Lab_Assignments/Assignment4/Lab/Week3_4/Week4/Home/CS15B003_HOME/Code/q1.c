#include<stdio.h>
#include<stdlib.h>
#include "List.h"
#include "SparseMatrix.h"

int main(){

	int option;
	
	scanf("%d",&option);
	
	while(option != -1){
	
		switch(option){
		
			case 1 : {
			
				int m, n,i,j;
				scanf("%d %d",&m,&n);
			
				Matrix matrix1;
				Matrix matrix2;
				
				matrix1.n_rows = m;
				matrix2.n_rows = m;
				
				matrix1.row_lst = (LList**)malloc(m*sizeof(LList*));
				
				for(i = 0; i < m; i++){
					*(matrix1.row_lst + i) = (LList*)malloc(sizeof(LList));
					(*(matrix1.row_lst + i))->head = NULL;
				}

				matrix2.row_lst = (LList**)malloc(m*sizeof(LList*));
					
				for(i = 0; i < m; i++){
					*(matrix2.row_lst + i) = (LList*)malloc(sizeof(LList));
					(*(matrix2.row_lst + i))->head = NULL;
				}
								
				LList** row1 = matrix1.row_lst ;
				LList** row2 = matrix2.row_lst ;
				
				for(i = 0; i < m; i++){					
				
					for(j = 0; j < n; j++){
							
						int val;
						scanf("%d",&val);
						if(val != 0) llist_append(*(row1+i),j,val);
					}
				}
				
				for(i = 0; i < m; i++){					
					
					for(j = 0; j < n; j++){
						int val;
						scanf("%d",&val);
						if(val != 0) llist_append(*(row2+i),j,val);
					}
				}
				
				Matrix result = add(matrix1, matrix2, n);
				
				for(i = 0; i < m; i++){
				
					if((*(result.row_lst + i))->head == NULL){
						printf("0\n");
						continue;
					}					
					
					llist_print(*(result.row_lst + i));
				}
				
				free(matrix1.row_lst);
				free(matrix2.row_lst);	
				
				break;			
			}
			
			case 2 : {
			
				int m, n,i,j;
				scanf("%d %d",&m,&n);
			
				Matrix matrix1;
				Matrix matrix2;
				
				matrix1.n_rows = m;
				matrix2.n_rows = m;
				
				matrix1.row_lst = (LList**)malloc(m*sizeof(LList*));
				
				for(i = 0; i < m; i++){
					*(matrix1.row_lst + i) = (LList*)malloc(sizeof(LList));
					(*(matrix1.row_lst + i))->head = NULL;
				}

				matrix2.row_lst = (LList**)malloc(m*sizeof(LList*));
					
				for(i = 0; i < m; i++){
					*(matrix2.row_lst + i) = (LList*)malloc(sizeof(LList));
					(*(matrix2.row_lst + i))->head = NULL;
				}
								
				LList** row1 = matrix1.row_lst ;
				LList** row2 = matrix2.row_lst ;
				
				for(i = 0; i < m; i++){					
				
					for(j = 0; j < n; j++){
							
						int val;
						scanf("%d",&val);
						if(val != 0) llist_append(*(row1+i),j,val);
					}
				}
				
				for(i = 0; i < m; i++){					
					
					for(j = 0; j < n; j++){
						int val;
						scanf("%d",&val);
						if(val != 0) llist_append(*(row2+i),j,val);
					}
				}
				
				Matrix result = subtract(matrix1, matrix2, n);
				
				for(i = 0; i < m; i++){
				
					if((*(result.row_lst + i))->head == NULL){
						printf("0\n");
						continue;
					}					
					
					llist_print(*(result.row_lst + i));
				}
				
				free(matrix1.row_lst);
				free(matrix2.row_lst);	
				
				break;
			}
			
			case 3 : {
			
				int m, n,i,j;
				scanf("%d %d",&m,&n);
			
				Matrix matrix;
				Matrix vector;
				
				matrix.n_rows = m;
				vector.n_rows = n;
				
				matrix.row_lst = (LList**)malloc(m*sizeof(LList*));
				
				for(i = 0; i < m; i++){
					*(matrix.row_lst + i) = (LList*)malloc(sizeof(LList));
					(*(matrix.row_lst + i))->head = NULL;
				}

				vector.row_lst = (LList**)malloc(n*sizeof(LList*));
					
				for(i = 0; i < n; i++){
					*(vector.row_lst + i) = (LList*)malloc(sizeof(LList));
					(*(vector.row_lst + i))->head = NULL;
				}
								
				for(i = 0; i < m; i++){					
				
					for(j = 0; j < n; j++){
							
						int val;
						scanf("%d",&val);
						if(val != 0) llist_append(*(matrix.row_lst+i),j,val);
					}
				}
				
					
				for(j = 0; j < n; j++){
					int val;
					scanf("%d",&val);
					if(val != 0) llist_append(*(vector.row_lst+j),0,val);
					}
				
				Matrix result = matrix_vect_multiply(matrix, vector);
				
				for(i = 0; i < m; i++) {
					
					if((*(result.row_lst + i))->head == NULL){
						printf("0\n");
						continue;
					}
					llist_print(*(result.row_lst + i));
				}	
				
				free(matrix.row_lst);
				free(vector.row_lst);	
				
				break;
		}
		
		}
		scanf("%d",&option);
	}
	
	
	return 0;

}
