#include "queue.h"
#include "List.h"
#include "stack_using_queue.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	queue *st= queue_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			push(st,data);
		}else if(!strcmp(temp,"size"))
			size(st);
		else if(!strcmp(temp,"is_empty"))
			empty(st);
		else if(!strcmp(temp,"pop"))
			pop(st);
		printf("\n");
	}
}	
