#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

int calc(int p,int q,int op1 ,int op2);
int pref(char ch);


int main(){
	int a;
	for(a=0 ; a<10 ; a++){
		char *str=(char *)malloc(sizeof(char) * 10);
		int j,pin,q=0;
			
		stack *st=stack_new();
		char p='0',p1;
		for( ; p!='\n' ; ){

			p=getchar();
			if(p=='\n' || p==' '){break;}
			pin=pref(p);
			//printf("%da %c\n",pin,p);
			if(pin==2){
				p1=getchar();
				if(p1==' '){
					int op2=stack_pop(st);
					int op1=stack_pop(st);
					q=calc(q,pin,op1,op2);
					stack_push(st,q);	
					p=p1;
				}
				else{
					str[0]=p;
					p=p1;
					for(j=1 ; p!='\n' && p!=' ' ; j++){
						str[j]=p;
						p=getchar();
					}
					str[j]='\0';
					int y=atoi(str);
					stack_push(st,y);	
				}
			}
			else if(pin==0){
				for(j=0 ; p!='\n' && p!=' ' ; j++){
					str[j]=p;
					p=getchar();
				}
				str[j]='\0';
				int y=atoi(str);
				stack_push(st,y);
			}
			else{
				int op2=stack_pop(st);
				int op1=stack_pop(st);
				q=calc(q,pin,op1,op2);
				stack_push(st,q);
				p=getchar();
			}
		}
		printf("%d\n",stack_pop(st));
		fflush(stdout);
	}
	return 0;
}

int calc(int p,int q,int op1 ,int op2){

	switch(q){
		case 1 :p=op1+op2;	break;
		case 2 :p=op1-op2;	break;
		case 3 :p=op1*op2;	break;
		case 4 :p=op1/op2;	break;
		case 5 :p=op1%op2;	break;
		case 6 :p=op1&op2;	break;
		case 7 :p=op1^op2;	break;
		case 8 :p=op1|op2;	break;
	}
	return p;
}

int pref(char ch){
	int k;
	switch(ch){
		case '+' :k=1;	break;
		case '-' :k=2;	break;
		case '*' :k=3;	break;
		case '/' :k=4;	break;
		case '%' :k=5;	break;
		case '&' :k=6;	break;
		case '^' :k=7;	break;
		case '|' :k=8;	break;
		default  :k=0;	break; 
	}
	return k;
}