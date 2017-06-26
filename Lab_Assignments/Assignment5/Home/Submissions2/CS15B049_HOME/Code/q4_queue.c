#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_using_stack.h"
#include "stack.h"
#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	stack *que= stack_new();
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
