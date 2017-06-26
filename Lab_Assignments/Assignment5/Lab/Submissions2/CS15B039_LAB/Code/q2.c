#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"List.h"
#include<string.h>
#define size 1000

int reversals(char *);

int main(){

	int T, i;
	scanf("%d", &T);
	int count = 0;
	char *str = (char *)malloc(sizeof(size +1));
	int rev[T];
	
	for(i=0;i<T;i++){
	scanf("%s", str);
	rev[i]=reversals(str);
	}
	
	for(i=0;i<T;i++)
		printf("%d\n", rev[i]);
	return 0;
}

int reversals(char *str){

	int count = 0;
	char c;
	int len = strlen(str);
	int i;
	stack * st = stack_new();
	
	if(len%2==1){
		return -1;
	}
	
	for(i=0;i<len;i++){
		c = str[i];
		if(c=='{')
			stack_push(st, 1);
		
		else{
			if(stack_is_empty(st)){
				count+=1;
				stack_push(st, 1);
			}
			else
				stack_pop(st);
		}
	}
	int rem_len = stack_size(st);
	count+=rem_len/2;
	return (count);
}
