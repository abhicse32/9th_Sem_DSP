#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void nextLarger(int *arr,int n);		//function to find the next greatest number for each number in arr
void print(int *a,int n);				//takes pointer to an array as input and prints the array

int main(){
	int t;
	scanf("%d",&t);
	int x;
	for(x=0; x<t ;x++){					//loop for t testcases
		int n,k;
		scanf("%d",&n);
		int *arr=(int *)malloc(sizeof(int) * n);
		for(k=0 ; k<n ; k++){
			scanf("%d",&arr[k]);
		}
		nextLarger(arr,n);
		free(arr);
	}
	return 0;
}

void print(int *a,int n){
	int k;
	for(k=0 ; k<n ; k++){				//printing the array of next greatest numbers
			printf("%d ",a[k]);
		}
	printf("\n");
}

void nextLarger(int *arr,int n){
	stack *st=stack_new();				//stack for array elements
	stack *index=stack_new();			//stack for indices
	int *res=(int *)malloc(sizeof(int) * n);
	stack_push(st,arr[0]);
	stack_push(index,0);
	int up;
	int a,b,i;
	for(i=1;i<n ; i++){
		up=arr[i];
		for( ; !stack_is_empty(st) ; ){
			a=stack_pop(st);			//if stack is not empty and popped element >next element in array 
			if(a>=up){					//push it back into stack
				stack_push(st,a);
				break;
			}
			else{					
				b=stack_pop(index);		//else it is the next greatest element for up so store it at corresponding address
				res[b]=up;
			}
		}
		stack_push(index,i);
		stack_push(st,up);
	}
	for(;!stack_is_empty(index) ; ){	//assigning the unalloted to -1
		b=stack_pop(index);
		res[b]=-1;
	}
	print(res,n);						//printing res array
	free(res);
}