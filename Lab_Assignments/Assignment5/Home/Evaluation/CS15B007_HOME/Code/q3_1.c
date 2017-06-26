#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include <string.h>

int pref(char c);

int main(){

	int a;
	for( a=0; a<10 ; a++){
		char s1[100],s2[100];
		int i,j,k;
		stack *st = stack_new();
		scanf("%c",&s1[0]);
		for( i=1; s1[i-1]!='\n' ;i++ ){
			scanf("%c",&s1[i]);
		}
		for(j=0 ,k=0 ; j<i-1 ; j++){
			int w=pref(s1[j]);
			if(w == 5){
				s2[k]=s1[j];

				k++;
			}
			else if(stack_is_empty(st)){
				stack_push(st,s1[j]);
				j++;
			}	
			else{
				char up=stack_pop(st);
				int u=pref(up);
				int flag=1;
				while(u!=-1 && w<=u && w!=-1){
					if(up!='(' && up!=')'){
						s2[k]=up;	k++;
						s2[k]=' ';	k++;
					}
					if(!stack_is_empty(st)){
						up=stack_pop(st);
						u=pref(up);
					}
					else {
						stack_push(st,s1[j]);
						j++;
						flag=0;
						break;
					}
				}
				if(u==-1){
					if(w==0){j++;}
					else{
						stack_push(st,up);
						stack_push(st,s1[j]);
						j++;
					}	 
				}
				else if(flag==1){
					stack_push(st,up);
					stack_push(st,s1[j]);
					j++;
				}
			}
		}
		int flag=1;
		for(; !stack_is_empty(st) ;){
			char up=stack_pop(st);
			if(up!='(' && up!=')'){
				if(flag==1 && s2[k-1]!=' '){
					s2[k]=' ';	k++;	flag=0;
				}
				s2[k]=up;	k++;
				s2[k]=' ';	k++;
			}
		}
		s2[k]='\0';
		printf("%s\n",s2 );
	}
	return 0;
}


int pref(char ch){
	int k;
	switch(ch){
		case '+' :
		case '-' :k=4;	break;
		case '*' :
		case '/' :
		case '%' :k=6;	break;
		case '&' :k=3;	break;
		case '^' :k=2;	break;
		case '|' :k=1;	break;
		case ')' :k=0;	break;
		case '(' :k=-1;	break;
		default  :k=5;	break; 
	}
	return k;
}
