/*
	Author:G.Kavitha
	Roll No.: CS15B057
	Date: 16/09/16
	Driver Program for stack_using_queue
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_using_queue.h"
#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	queue *st= stack_using_queue_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			stack_using_queue_push(st,data);
			stack_using_queue_print(st);

		}else if(!strcmp(temp,"size"))
			printf("%d",stack_using_queue_size(st));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",stack_using_queue_is_empty(st));
		else if(!strcmp(temp,"pop"))
			printf("%d",stack_using_queue_pop(st));
		printf("\n");
	}
}	
