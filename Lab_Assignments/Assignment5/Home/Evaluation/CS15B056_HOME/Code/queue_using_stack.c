//QUEUE USING STACK
//AUTHOR - SARTAHK PANDEY

#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "List.h"
void enqueue (stack *q,int data);
int dequeue (stack *q);
int queue_size(stack *q);
bool queue_is_empty(stack* q);
void queue_print(stack* q);
void queue_print1(stack* q);

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

void enqueue (stack *q,int data)                 //TO ENQUEUE , WE PUSH TO STACK
{
	stack_push(q,data);
}

int dequeue (stack *q)                            //WHILE DEQUEUEING WE REMOVE LAST ELEMENT OF THE STACK LLIST RECURSIVELY
{
	if (stack_size(q)==0)
		;
	else if (stack_size(q)==1)
		return stack_pop(q);
	else 
	{
		int j,i=stack_pop(q);
		j=dequeue (q);
		stack_push(q,i);
		return j;
	}
}

int queue_size(stack *q)                   //RETURNS SIZE
{
	return stack_size(q);
}

bool queue_is_empty(stack* q)
{
	if (stack_size(q)==0)
		return true;
	else 
		return false;
}	

void queue_print1(stack* q)
{
	int j,i=dequeue(q);
	for (;i!='#';)
	{
		printf ("%d ",i);
		enqueue(q,i);
		i=dequeue(q);
	}
}	

void queue_print(stack *q)                       //PRINTS STACK USING SENTINEL '#'
{
	stack_push(q,'#');
	queue_print1(q);
}











