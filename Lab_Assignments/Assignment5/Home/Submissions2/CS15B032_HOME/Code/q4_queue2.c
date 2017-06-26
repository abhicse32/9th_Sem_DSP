#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

#define BUFF_SIZE 20


int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	queue *q= queue_new(),*q2= queue_new(),*tempq;
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			enqueue(q,node_new(data));
			queue_print(q);

		}else if(!strcmp(temp,"size"))
			printf("%d",queue_size(q));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",queue_is_empty(q));
		else if(!strcmp(temp,"pop"))
			{
			while(queue_size(q)>1)
			enqueue(q2,dequeue(q));
			printf("%d",dequeue(q)->data);
			tempq=q2;
			q2=q;
			q=tempq;
			}
		printf("\n");
	}
}
