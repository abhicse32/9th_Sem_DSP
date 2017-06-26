#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	stack *st= stack_new(),*st2= stack_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"enqueue")){
			int data=atoi(strtok(NULL," "));
			stack_push(st,data);
			stack_print(st);

		}else if(!strcmp(temp,"size"))
			printf("%d",stack_size(st));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",stack_is_empty(st));
		else if(!strcmp(temp,"dequeue"))
			{

			while(stack_size(st)>1)
			stack_push(st2,stack_pop(st));
			printf("%d",stack_pop(st));
			while(!stack_is_empty(st2))
			stack_push(st,stack_pop(st2));

			}
		printf("\n");
	}
}
