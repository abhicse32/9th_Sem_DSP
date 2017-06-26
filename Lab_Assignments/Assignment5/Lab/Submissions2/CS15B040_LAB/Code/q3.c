#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "List.h"


int main(void){

	int t;
	scanf("%d",&t);//no of testcases
	
	for(int i=0;i<t;i++){
		int n,i;
		scanf("%d",&n);
		int array[n];
		for(int j=0;j<n;j++){
			scanf("%d",&array[j]);//reading the elements of an array
		}
        	stack* sstack=stack_new();//creating a new stack
        	
		for(i=0;i<n-1;i++){
			if(array[i]<array[i+1]){
			
		        	array[i]=array[i+1];//if a[i]<a[i+1] keep a[i]=a[i+1]
		        	
			      	while(stack_is_empty(sstack)==0&&array[i+1]>array[stack_top(sstack)]){//if not empty and a[i+1]>top stack
			      	
					array[stack_top(sstack)]=array[i+1];
					stack_pop(sstack);
			        }
			  }
		  	else {
		  		stack_push(sstack,i);
		  	}
	        }
	        
	        array[n-1]=-1;//last element doesnt have any greater elements
	        while(stack_is_empty(sstack)==0){
			array[stack_top(sstack)]=-1;
			stack_pop(sstack);
	        }
	        
	        for(i=0;i<n;i++){
			printf("%d ",array[i]);
	        }
	       printf("\n");
	}
	return 0;  
}             	
