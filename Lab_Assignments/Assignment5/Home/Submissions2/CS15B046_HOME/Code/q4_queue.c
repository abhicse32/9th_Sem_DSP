/*	Driver function for queue_using_stack.c
	Author:CS15B046 Jahnvi Patel
	Date:September 15th, 2016
*/
#include "queue_using_stack.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define BUFF_SIZE 20

int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	stack *que= queue_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"enqueue")){
			int data=atoi(strtok(NULL," "));
			enqueue(que,data);
			queue_print(que);

		}else if(!strcmp(temp,"size"))
			printf("%d",queue_size(que));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",queue_is_empty(que));
		else if(!strcmp(temp,"dequeue"))
			printf("%d", dequeue(que));
		printf("\n");
	}
}
