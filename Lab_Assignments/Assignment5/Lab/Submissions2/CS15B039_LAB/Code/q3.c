#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"List.h"

int main(){

	int T;
	scanf("%d", &T);
	
	int k;
	for(k=0;k<T;k++)
	{
		int N;
		scanf("%d", &N);
		int n, m;
		stack *st = stack_new();
		int i;
		int arr[N];
		int count = -1;
		int cur_count;
		int temp;
		stack *st1 = stack_new();
		for(i=0;i<N;i++){
			scanf("%d", &n);
			count++;
			arr[count]=-1;
			cur_count = count;
		
			if(stack_is_empty(st)){
				stack_push(st, n);
				stack_push(st1, i);
			}
			else{
				m = stack_pop(st);
				if(n>m){
					while(n>m){
						temp = stack_pop(st1);
						arr[temp]= n;
						//printf("%d\t", temp);
						if(!stack_is_empty(st)){
							m = stack_pop(st);
							}
						else 
							break;
						}
						if(m>=n)
							stack_push(st, m);
						stack_push(st, n);
						stack_push(st1, i);
				}
				else{
					stack_push(st, m);
					stack_push(st, n);
					//stack_push(st1, i-1);
					stack_push(st1, i);
				}
				}
		}
	
		for(i=0;i<N;i++)
			printf("%d ", arr[i]);
		printf("\n");
	}			
		return 0;
}
