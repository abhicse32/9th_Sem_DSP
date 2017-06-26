#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_a.h"
#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	stack* st_a= stack_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			stack_push(st_a,data);
			stack_print(st_a);

		}else if(!strcmp(temp,"size"))
			printf("%d",stack_size(st_a));
		else if(!strcmp(temp,"is_full"))
			printf("%d",stack_is_full(st_a));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",stack_is_empty(st_a));
		else if(!strcmp(temp,"pop"))
			printf("%d",stack_pop(st_a));
		printf("\n");
	}
}	