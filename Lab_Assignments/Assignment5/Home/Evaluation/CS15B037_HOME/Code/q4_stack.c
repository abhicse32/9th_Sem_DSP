/*
 * On 18th September 2016
 * Written by Teratipally Srikar, CS15B037
 * This program is driver file
 * for testing the program
 * stack implemented using queue
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_using_queue.h"
#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	queue *queueptr=queue_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			stack_push(queueptr,data);
			stack_print(queueptr);

		}else if(!strcmp(temp,"size"))
			printf("%d",stack_size(queueptr));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",stack_is_empty(queueptr));
		else if(!strcmp(temp,"pop"))
			printf("%d",stack_pop(queueptr));
		printf("\n");
	}
}	