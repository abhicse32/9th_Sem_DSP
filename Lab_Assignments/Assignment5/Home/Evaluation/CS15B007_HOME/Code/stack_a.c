#include "stack_a.h"
#include <stdio.h>
#include <stdlib.h>
#define size 1000

stack* stack_new(){
	stack *new=(stack *)malloc(sizeof(stack));
	new->top=-1;
	new->arr=(int *)malloc(sizeof(int) * size);

	return new;
}

void stack_push(stack* s, int elm){
	if(s->top!=999){
		s->top++;
		s->arr[s->top]=elm;
	}
}

int stack_pop(stack* s){
	int a;
	if(s->top!=-1){
		a=s->arr[s->top];
		s->top--;
	}
	return a;
}

bool stack_is_empty(stack* s){
	if(s->top==-1){return true;}
	else return false;
}

bool stack_is_full(stack* s){
	if(s->top==999){
		return true;
	}
	else return false;
}

int stack_size(stack* s){
	return (s->top+1);
}

void stack_print(stack* s){
	int i;
	if(stack_is_empty(s)){return;}
	for(i=s->top ; i>=0 ; i--){
		printf("%d ",s->arr[i]);
	}
	return ;
}
