#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_using_queue.h"
#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	queue *st= queue_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			enqueue(st,data);
			queue_print(st);

		}else if(!strcmp(temp,"size"))
			printf("%d",queue_size(st));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",queue_is_empty(st));
		else if(!strcmp(temp,"pop"))
			printf("%d",dequeue(st));
		printf("\n");
	}
}	 
