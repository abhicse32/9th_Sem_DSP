/* Evaluating postfix
Vishal Mohanty
Date = 18-09-2016*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"stack.h"
//#include"stack.c"
//#include"List.c"
#define size 1000

int operator( char * );
int PostEvaluate(char *);

int main(){
	int i;
	for(i=0;i<10;i++){
		char *s = (char *)malloc(size*sizeof(char));
		fgets(s, 100, stdin);
		int len = strlen(s);
		int ans;
		s[len-1] = '\0';
		ans = PostEvaluate(s);
		printf("%d\n", ans);

	}
			return 0;
}

int PostEvaluate(char * s){

	stack * st = stack_new();
	char *t;
	int a, b;
	
	t = strtok(s, " ");	
	while(t!=NULL){
		if(!operator(t))
			stack_push(st, atoi(t));
		else{
			a = stack_pop(st);
			b = stack_pop(st);
			stack_push(st, perform(b, a, t));
		}
		t = strtok(NULL, " ");
	}
	return (stack_pop(st));
}

int perform(int a, int b, char * t){
	
	if(strcmp(t, "+")==0){
		return (a+b);
		}
	else if(strcmp(t, "-")==0)
		return (a-b);
	else if(strcmp(t, "*")==0)
		return (a*b);
	else if(strcmp(t, "/")==0)
		return (a/b);
	else if(strcmp(t, "|")==0)
		return (a|b);
	else if(strcmp(t, "&")==0)
		return (a&b);
	else if(strcmp(t, "%")==0)
		return (a%b);
	else if(strcmp(t, "^")==0)
		return (a^b);
}

int operator ( char * c ){

	if(strcmp(c,"(")==0 || strcmp(c, "+")==0 || strcmp(c,"-")==0 || strcmp(c,"*")==0 || strcmp(c,"/")==0 || strcmp(c,")")==0 || strcmp(c, "&")==0 || strcmp(c, "|")==0 || strcmp(c, "%")==0 || strcmp(c, "^")==0){
		//printf("%dop", 1);
		return 1;
		}
	else{
		//printf("%dop", 0);
		return 0;
	}
}	
