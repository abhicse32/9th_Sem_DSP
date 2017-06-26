//q1.c by Raghavan S CS15B034 Home Assignment 5
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#define BUFF_SIZE 20

int main(int* argc, char* argv[])
{
	char str[BUFF_SIZE];
	stack *st= stack_new();
	stack_a* st_a= stacka_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			stacka_push(st_a,data);
			stack_push(st,data);
			stack_print(st);
			printf(": ");
			stacka_print(st_a);

		}else if(!strcmp(temp,"size"))
			printf("%d : %d",stack_size(st),stacka_size(st_a));
		else if(!strcmp(temp,"is_full"))
			printf("%d",stacka_is_full(st_a));
		else if(!strcmp(temp,"is_empty"))
			printf("%d : %d",stack_is_empty(st),stacka_is_empty(st_a));
		else if(!strcmp(temp,"pop"))
			printf("%d : %d", stack_pop(st),stacka_pop(st_a));
		printf("\n");
	}
}
