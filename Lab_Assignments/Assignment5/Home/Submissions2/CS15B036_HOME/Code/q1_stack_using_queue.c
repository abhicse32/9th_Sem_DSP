#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_queue.h"


#define BUFF_SIZE 20
int main(int* argc, char* argv[]){

	char str[BUFF_SIZE];
	queue *Q= queue_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			enqueue(Q,data);
			queue_print(Q);

		}else if(!strcmp(temp,"size"))
			printf("%d",stack_size(Q));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",stack_is_empty(Q));
		else if(!strcmp(temp,"pop"))
			printf("%d",stack_pop(Q));
		printf("\n");
	}
}	
