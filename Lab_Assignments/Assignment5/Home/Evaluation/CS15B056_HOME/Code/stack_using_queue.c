//STACK USING QUEUE
//AUTHOR - SARTHAK PANDEY

#include <stdio.h>
#include "List.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>
int stack_pop(queue *q);
int stack_pop1(queue *q);
void stack_push(queue *q,int data);
bool stack_is_empty(queue* q);
void stack_print(queue* q);

#define BUFF_SIZE 20
int main(int* argc, char* argv[]){
	char str[BUFF_SIZE];
	queue *st= queue_new();
	while(fgets(str,BUFF_SIZE,stdin)!=NULL){
		str[strlen(str)-1]='\0';
		char* temp= strtok(str," ");
		if(!strcmp(temp,"push")){
			int data=atoi(strtok(NULL," "));
			stack_push(st,data);
			stack_print(st);

		}else if(!strcmp(temp,"size"))
			printf("%d",stack_size(st));
		else if(!strcmp(temp,"is_empty"))
			printf("%d",stack_is_empty(st));
		else if(!strcmp(temp,"pop"))
			printf("%d",stack_pop(st));
		printf("\n");
	}
}	

int stack_pop(queue *q)                           //HERE WE REMOVE THE LAST ELEMENT FRON QUEUE LIST BY USING A SENTINEL VALUE AND CALLINF FUNCTION RECURSIVELY
{
	enqueue(q,'#');
	return stack_pop1(q);
}
int stack_pop1(queue *q)
{
	if (q->front->head->data=='#')
		dequeue(q);
	else if (q->front->head->next->data=='#')
	{
		int i;
		i=dequeue(q);
		dequeue(q);
		return i;
	}
	else 
	{
		int j;
		j=dequeue(q);
		enqueue(q,j);
		return stack_pop1(q);
	}
}

void stack_push(queue *q,int data)                      //TO PUSH , WE PLAVE ELEMENT AT LAST
{
	enqueue(q,data);
}

int stack_size(queue *q)
{
	return queue_size(q);                            //RETURNS SIZE
}

bool stack_is_empty(queue* q)                            //CHECKS IF STACK IS EMPTY
{
	if (queue_size(q)==0)
		return true;
	else 
		return false;
}
void stack_print(queue* q)                               //PRINTS THE STACK
{
	if (stack_size(q)==0)
		;
	else
	{
		int i=stack_pop(q);
		printf ("%d ",i);
		stack_print(q);
		enqueue(q,i);
	}
}	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	


	
