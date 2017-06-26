/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
	Driver Program for queue_using_stack
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_using_stack.h"
#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	stack *que= queue_using_stack_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"enqueue")){
			int data=atoi(strtok(NULL," "));
			enqueue_using_stack(que,data);
			queue_using_stack_print(que);

		}else if(!strcmp(temp,"size"))
			printf("%d",queue_using_stack_size(que));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",queue_using_stack_is_empty(que));
		else if(!strcmp(temp,"dequeue"))
			printf("%d", dequeue_using_stack(que));
		printf("\n");
	}
}	
