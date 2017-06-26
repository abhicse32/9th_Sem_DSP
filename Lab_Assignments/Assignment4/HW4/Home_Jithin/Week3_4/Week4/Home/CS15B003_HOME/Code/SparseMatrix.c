#include "SparseMatrix.h"
#include<stdio.h>
#include<stdlib.h>
#include "List.h"

Matrix add(Matrix matrix1, Matrix matrix2, int n){			//Adding two matrices	

	int i,j;
	
	Matrix* result = (Matrix*)malloc(sizeof(Matrix));		//Allocating space for resultant matrix in the heap
	
	result->row_lst = (LList**)malloc(sizeof(LList*)*(matrix1.n_rows));
				
				for(i = 0; i < matrix1.n_rows; i++){

					*(result->row_lst + i) = (LList*)malloc(sizeof(LList));
					(*(result->row_lst + i))->head = NULL;
				}

	for(i = 0; i < matrix1.n_rows; i++){				//If kth place of both the matrices are non zero they are added
											//Else only the non zero element is appended to the result matrix
		int p = 0;
		int q = 0;
			
		for(j = 0; j < n; j++){
		
				if((p < llist_size(*(matrix1.row_lst + i)))&&(q < llist_size(*(matrix2.row_lst + i)))){
					if((j == (llist_get(*(matrix1.row_lst + i),p))->col_ind)&&((llist_get(*(matrix1.row_lst + i),p))->col_ind == (llist_get(*(matrix2.row_lst + i),q))->col_ind)){
						llist_append(*(result->row_lst + i),j,llist_get(*(matrix1.row_lst + i),p)->val + llist_get(*(matrix2.row_lst + i),q)->val);
						p++; q++;
						continue ;
					}
				}
				
				if(p < llist_size(*(matrix1.row_lst + i))){			
					if(j == (llist_get(*(matrix1.row_lst + i),p))->col_ind){
						llist_append(*(result->row_lst + i),j,llist_get(*(matrix1.row_lst + i),p)->val);
						p++;
						continue ;
					}
				}
			
				if(q < llist_size(*(matrix2.row_lst + i))){
					if(j == (llist_get(*(matrix2.row_lst + i),q))->col_ind){
						llist_append(*(result->row_lst + i),j,llist_get(*(matrix2.row_lst + i),q)->val);
						q++;
					}
				}	
		
		}	
	
	}

	return *(result);
}

Matrix subtract(Matrix matrix1, Matrix matrix2, int n){		//Subtracts the matrices mattrix1 - matrix2

	int i,j;
	
	Matrix* result = (Matrix*)malloc(sizeof(Matrix));		//Allocates space for the matrix elents in the heap
	
	result->row_lst = (LList**)malloc(sizeof(LList*)*(matrix1.n_rows));
				
				for(i = 0; i < matrix1.n_rows; i++){

					*(result->row_lst + i) = (LList*)malloc(sizeof(LList));
					(*(result->row_lst + i))->head = NULL;
				}

	for(i = 0; i < matrix1.n_rows; i++){				//If kth place of both the matrices are non zero they are subtracted
											//Else only the non zero element is appended to the result matrix accordingly
		int p = 0;
		int q = 0;
			
		for(j = 0; j < n; j++){
		
				if((p < llist_size(*(matrix1.row_lst + i)))&&(q < llist_size(*(matrix2.row_lst + i)))){
					if((j == (llist_get(*(matrix1.row_lst + i),p))->col_ind)&&((llist_get(*(matrix1.row_lst + i),p))->col_ind == (llist_get(*(matrix2.row_lst + i),q))->col_ind)){
						llist_append(*(result->row_lst + i),j,llist_get(*(matrix1.row_lst + i),p)->val - llist_get(*(matrix2.row_lst + i),q)->val);
						p++; q++;
						continue ;
					}
				}
				
				if(p < llist_size(*(matrix1.row_lst + i))){			
					if(j == (llist_get(*(matrix1.row_lst + i),p))->col_ind){
						llist_append(*(result->row_lst + i),j,llist_get(*(matrix1.row_lst + i),p)->val);
						p++;
						continue ;
					}
				}
			
				if(q < llist_size(*(matrix2.row_lst + i))){
					if(j == (llist_get(*(matrix2.row_lst + i),q))->col_ind){
						llist_append(*(result->row_lst + i),j,-llist_get(*(matrix2.row_lst + i),q)->val);
						q++;
					}
				}	
		
		}	
	
	}

	return *(result);
}

Matrix matrix_vect_multiply(Matrix mat, Matrix vect){				//Multiplies an mxn matrix with an nx1 vector 
	
	int i,k;
	
	Matrix* result = (Matrix*)malloc(sizeof(Matrix));			//A;;ocates memory for the resultant matrix in the heap
	
	result->row_lst = (LList**)malloc(sizeof(LList*)*(mat.n_rows));
				
				for(i = 0; i < mat.n_rows; i++){

					*(result->row_lst + i) = (LList*)malloc(sizeof(LList));
					(*(result->row_lst + i))->head = NULL;
				}
				
				
	
	for(i = 0; i < mat.n_rows; i++){
	
		int sum = 0;
		int p = 0;
		
		if((*(mat.row_lst + i))->head == NULL) continue;		//When all the elements of a row are 0 you dont need to multipily
		
		for(k = 0; k < vect.n_rows; k++){
				
				if(llist_get(*(mat.row_lst + i),p) != NULL){	//Sees that the last element is not reached yet
				
					if(k == (llist_get(*(mat.row_lst + i),p))->col_ind){	//Condition to check if the kth element in the row is non zero
						
						if((*(vect.row_lst + k))->head != NULL)		//Condition to check if the kth row elemnt is zero
						sum = sum + ((llist_get(*(mat.row_lst + i),p))->val)*((llist_get(*(vect.row_lst + k),0))->val);
						p++;	
					}
					
				}	

		}
		
		llist_append(*(result->row_lst + i),0,sum);	//Appends elements of the resultant matrix
	}
	
	return *(result);
	
}
