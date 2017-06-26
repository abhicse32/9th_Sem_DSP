#include "SparseMatrix.h"
#include "List.h"
#include <stdlib.h>
#include <stdio.h>

Matrix initialize(int a, int c){
	LList** lst=(LList**)malloc(sizeof(LList*)*a);
	int i;
	for(i=0;i<a;i++)
		lst[i]= llist_new();
	Matrix b;
	b.row_lst= lst; b.n_rows= a;
	b.n_cols=c;
	return b;
}

void add_rows(LList* row_a, LList* row_b, LList* dest){
	Node* temp1= row_a->head;
	Node* temp2= row_b->head;
	while(temp1 && temp2){
		if(temp1->col_ind == temp2->col_ind){
			llist_append(dest,temp1->col_ind, temp1->val + temp2->val);
			temp2= temp2->next;
			temp1= temp1->next;
		}else if(temp1->col_ind < temp2->col_ind){
			llist_append(dest,temp1->col_ind, temp1->val);
			temp1= temp1->next;
		}else{
			llist_append(dest,temp2->col_ind, temp2->val);
			temp2= temp2->next;
		}
	}
	while(temp1){
		llist_append(dest,temp1->col_ind,temp1->val);
		temp1= temp1->next;
	}
	while(temp2){
		llist_append(dest,temp2->col_ind, temp2->val);
		temp2= temp2->next;
	}
}

Matrix add(Matrix a, Matrix b){
	int rows= a.n_rows,i,j,k;
	Matrix res= initialize(rows,a.n_cols);
	for(i=0;i<rows;i++)
		add_rows(a.row_lst[i],b.row_lst[i],res.row_lst[i]);
	return res;
}

Matrix subtract(Matrix a, Matrix b){
	int size= b.n_rows,i;
	for(i=0;i<size;i++){
		Node* temp= b.row_lst[i]->head;
		while(temp){
			temp->val= -1*(temp->val);
			temp= temp->next;
		}
	}
	return add(a,b);
}

Matrix matrix_vect_multiply(Matrix a, Matrix b){
	int rows= a.n_rows;
	Matrix res= initialize(a.n_rows,1);
	int i,j,k;
	for(i=0;i < rows; i++){
		Node* temp= a.row_lst[i]->head;
		int sum=0;
		while(temp){
			if(b.row_lst[temp->col_ind]->head)
				sum+=(temp->val*(b.row_lst[temp->col_ind]->head->val));
			temp= temp->next;
		}
		llist_append(res.row_lst[i],i,sum);
	}
	return res;
}