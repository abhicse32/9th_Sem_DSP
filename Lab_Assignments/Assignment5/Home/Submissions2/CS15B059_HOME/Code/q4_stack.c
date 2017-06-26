#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_using_queue.h"
#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	queue *que= stack_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			stack_push(que,data);
			stack_print(que);

		}else if(!strcmp(temp,"size"))
			printf("%d",stack_size(que));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",stack_is_empty(que));
		else if(!strcmp(temp,"pop"))
			printf("%d",stack_pop(que));
		printf("\n");
	}
}
