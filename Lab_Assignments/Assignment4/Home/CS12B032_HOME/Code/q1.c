#include <stdio.h>
#include "List.h"
#include "SparseMatrix.h"
#include <stdlib.h>
void take_input(Matrix a, int m, int n){
	int i,j,temp;
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&temp);
			if(temp)
				llist_append(a.row_lst[i],j,temp);
		}
	}
}

int main(){
	int m,n,i,j,temp;
	int option;
	scanf("%d",&option);
	while(option!=-1){
		scanf("%d%d",&m,&n);
		Matrix a,b,res;
		a= initialize(m,n);
		take_input(a,m,n);
		switch(option){
			case 1: 
				b= initialize(m,n);
				take_input(b,m,n);
				res= add(a,b);
				break;
			case 2:
				b= initialize(m,n);
				take_input(b,m,n);
				res=subtract(a,b);
				break;
			case 3:
				b= initialize(n,1);
				take_input(b,n,1);
				res= matrix_vect_multiply(a,b);
				break;
			default: break;
		}
		for(i=0;i<m;i++){
			if(res.row_lst[i]->head){
				llist_print(res.row_lst[i]);
				printf("\n");
			}
		}
		scanf("%d",&option);
	}
}