#include "stack.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char* postfix(char*);
char* postfix(char* exp){
	int len=0,i,j;
	while(exp[len]!='\0') len++;
	char* ans=(char*)malloc(sizeof(char)*(len+2));
	stack* s = stack_new();
	stack_push(s,(int)'#');
	i=0;j=0;
	while(i<len && stack_size(s)>1){
		if(isdigit(exp[i])){
			ans[j++]=exp[i];
			ans[j++]=' ';
		}
		else{
			if(exp[i]==')'){
				char c = stack_pop(s);
				while(c!=')' || c!='#'){
					ans[j++]=c;
					ans[j++]=' ';
					c = stack_pop(s);
				}
			}
			else if(exp[i]=='+' || exp[i]=='-'){
				char c = stack_pop(s);
				while(c=='*' || c=='/' || c=='+' || c=='-'){
					ans[j++]=c;
					ans[j++]=' ';
					c = stack_pop(s);
				}
				stack_push(s,c);
			}
			else if(exp[i]=='*' || exp[i]=='/'){
				char c = stack_pop(s);
				while(c=='*' || c=='/' || c=='^'){
					ans[j++]=c;
					ans[j++]=' ';
				}
				stack_push(s,c);
			}
			else if(exp[i]=='^'){
				char c = stack_pop(s);
				while(c!='('){
					ans[j++]=c;
					ans[j++]=' ';
				}
				stack_push(s,c);
			}
			else stack_push(s,exp[i]);
		}
		i+=2;
	}
	ans[j]='\0';
	return ans;

}


int main(void){
	char st[100];
	scanf("%s",st);
	char *ans;
	ans = postfix(st);
	printf("%s\n",ans);
	return 0;
}
