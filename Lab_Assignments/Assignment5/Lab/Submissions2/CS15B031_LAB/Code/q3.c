//Author: Phalguna Rao Ch.
//Roll no.: CS15B031
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
#include"List.h"
#define SIZE 1001
int main(){
	int t;
	scanf("%d", &t);
	//char* exp = (char*) malloc(sizeof(char) * SIZE);
	while(t--){		
		int n;
		scanf("%d", &n);
		int* a = (int*) malloc(sizeof(int) * n);
		int i, val;
		stack* st = stack_new();
		for(i = 0; i < n; i++) scanf("%d", &a[i]);
		for(i = n-1; i >= 0; i--){				//run the array in reverse direction
			while(1){					//runs until some value to a[i] is re-assigned(i.e, the element greater than a[i])
				if(stack_is_empty(st) == true){		//pushes into stack and assigns a[i]
					stack_push(st, a[i]);
					a[i] = -1;
					break;
				}
				val = stack_pop(st);			//initializes val
				if(a[i] < val){				//push if condition satisfy
					stack_push(st, val);
					stack_push(st, a[i]);
					a[i] = val;
					break;
				}
				else{					//else do nothing
				}
			}
			//printf("%d ", a[i]);
		}
		for(i = 0; i < n; i++) printf("%d ", a[i]);		//printing output
		printf("\n");
	}
	return 0;
}			 
