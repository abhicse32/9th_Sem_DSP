#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_a.h"
#define BUFF_SIZE 20
int main(int argc, char* argv[]){
	char str[BUFF_SIZE];
	queue* que_a= queue_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"enqueue")){
			int data=atoi(strtok(NULL," "));
			enqueue(que_a,data);
			queue_print(que_a);

		}else if(!strcmp(temp,"size"))
			printf("%d",queue_size(que_a));
		else if(!strcmp(temp,"is_full"))
			printf("%d",queue_is_full(que_a));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",queue_is_empty(que_a));
		else if(!strcmp(temp,"dequeue"))
			printf("%d",dequeue(que_a));
		printf("\n");
	}
}	