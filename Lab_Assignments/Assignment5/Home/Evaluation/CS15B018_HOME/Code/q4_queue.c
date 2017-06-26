//driver function for queue_using stack.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue_using_stack.h"
#define BUFF_SIZE 20
int main(int* argc, char* argv[])
{
	char str[BUFF_SIZE];
	stack *stackptr= stack_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL)
	{
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"enqueue"))
		{
			int data=atoi(strtok(NULL," "));
			enqueue(stackptr,data);
			stack_print(stackptr);

		}
		else if(!strcmp(temp,"size"))
			printf("%d",queue_size(stackptr));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",queue_is_empty(stackptr));
		else if(!strcmp(temp,"dequeue"))
			printf("%d", dequeue(stackptr));
		printf("\n");
	}
}	
