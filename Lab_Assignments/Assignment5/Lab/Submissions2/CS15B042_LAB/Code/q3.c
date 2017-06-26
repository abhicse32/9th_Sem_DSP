/*Finds next greater element for each element in an array
Y BHARGAVA SAI CS15B042 16-09-16*/
#include <stdio.h>
#include "stack.h"

int main(){
	int T,i1,i2,index;
	scanf("%d",&T);			//stores no of testcases
	int n,top,current;
	for(i1 = 0;i1 < T;i1++){	//implements 'for' loop for multiple testcases
		scanf("%d",&n);
		int a[n],b[n];
		for(i2 = 0;i2 < n;i2++){
			scanf("%d",&a[i2]);
		}
		stack *s1 = stack_new();	//creates stack for storing elements 
		stack *s2 = stack_new();	//creates stack for storing corresponding indices
		//Finds next greater element for each element in an array in O(n) complexity
		stack_push(s1,a[0]);
		stack_push(s2,0);
		for(i2 = 1;i2 < n;i2++){
			current = a[i2];
			if(!stack_is_empty(s1)){
				top = stack_pop(s1);
				index = stack_pop(s2);
				while(top < current){
					b[index] = current;
					if(stack_is_empty(s1)){
						break;
					}
					top = stack_pop(s1);
					index = stack_pop(s2);			
				}				
				if(top >= current){
					stack_push(s1,top);
					stack_push(s2,index);
				}	
			}	
			stack_push(s1,current);
			stack_push(s2,i2);
		}
		//if stack is not empty then there is no element greater than them.so store -1 in them
		while(!stack_is_empty(s1)){
			top = stack_pop(s1);
			index = stack_pop(s2);
			b[index] = -1;
		}
		//prints the output array
		for(i2 = 0;i2 < n;i2++){
			printf("%d ",b[i2]);
		}	
		printf("\n");		
	}
	return 0;
}