#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
#include "List.h"

void main(){
	
	int n,i,j,T;
	
	scanf("%d",&T);
	
	for(j = 0; j < T; j++){
	
			scanf("%d",&n);
	
			int arr[n];
	
			stack* stk = stack_new();
	
			scanf("%d",&arr[0]);
			int max = arr[0];
			 
			for(i = 1; i < n; i++){
				scanf("%d",&arr[i]);
				if(arr[i] > max) max = arr[i];	
			}
	
			stack* stk_ind = stack_new();
			int b[n];
	
			stack_push(stk,arr[0]);
			stack_push(stk_ind,0);
	
			for(i = 1; i < n; i++){
	
				if(arr[i] <= stk->top->head->data){
					stack_push(stk, arr[i]);
					stack_push(stk_ind, i);
					continue;
				}
		
				while(1){
					b[stk_ind->top->head->data] = arr[i];
					stack_pop(stk);
					stack_pop(stk_ind);
					if(stack_is_empty(stk)){
						stack_push(stk,arr[i]);
						stack_push(stk_ind,i);
					  	break;
					  }	
					if(arr[i] <= stk->top->head->data){
						stack_push(stk,arr[i]);
						stack_push(stk_ind,i);
						break; 
					}
				}
				 
			}
			
			while(!stack_is_empty(stk)){
				b[stk_ind->top->head->data] = -1; 	
				stack_pop(stk);
				stack_pop(stk_ind);
			}	
			for(i = 0; i < n; i++) printf("%d ",b[i]);
			printf("\n");			
	}
}
