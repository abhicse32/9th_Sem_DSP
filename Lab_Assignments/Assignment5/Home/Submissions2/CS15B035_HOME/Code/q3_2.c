#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

bool isOperator(char c){
	switch(c){
		case '*':
		case '/':
		case '%':
		case '+':
		case '-':
		case '^':
		case '&':
		case '|':
		case '(':
		case ')':
		return true;
	}
	 return false;
}

void evaluate(){
	char c=getchar();
	stack* S=stack_new();
	int val=0;
	int i=0;
	int j=0;
	int k;
	int l=0;
	int m=0;
	int n=0;
	int a1;
	char g;
	while(c!='\n'){
		if(!isOperator(c)){
			val=0;
			m=0;
			while(c!=' '){
				m=1;
				val = 10*val+(c-'0');
				g=c;
				c=getchar();
				if(c=='\n'){
					j=1;
					break;
				}
			}
			if(j==1){
				stack_push(S,val);
				continue;
			}
			if(m==1) stack_push(S,val);
			//stack_print(S);
			//printf("\n");
			if(c==' '){
				g=c;
				c=getchar(); 
				continue;
			}
		}
		
		
		else{//stack_print(S);printf("\n");
			switch(c){
			
				case '+':{
					k=stack_pop(S)+stack_pop(S);
					stack_push(S,k);
					c=getchar();
					continue;
				}
				break;
				case '-':{
						c=getchar();
						//if(c=='\n') continue;
						if(c==' '||c=='\n'){
							k=stack_pop(S)-stack_pop(S);
							stack_push(S,-k);
							if(c=='\n') continue;
							c=getchar();
							continue;
						}
						else{
							val=0;
							n=0;
							while(c!=' '){
								n=1;
								val = 10*val+(c-'0');
								g=c;
								c=getchar();
								if(c=='\n'){
								l=1;
								break;
								}
							}
							if(l==1) continue;
							if(n==1) stack_push(S,-val);
							c=getchar();
							continue;	
						}
							
						
						
				}
				break;
				case '*':{
					k=stack_pop(S)*stack_pop(S);
					stack_push(S,k);
					c=getchar();
					continue;
				}
				break;
				case '/':{
					a1=stack_pop(S);
					k=stack_pop(S);
					k=k/a1;
					stack_push(S,k);
					c=getchar();
					continue;
				}
				break;
				case '|':{
					k=stack_pop(S)|stack_pop(S);
					stack_push(S,k);
					c=getchar();
					continue;
				}
				break;
				case '%':{
					a1=stack_pop(S);
					k=stack_pop(S);
					k=k%a1;
					stack_push(S,k);
					c=getchar();
					continue;
				}				
				case '^':{
					k=stack_pop(S)^stack_pop(S);
					stack_push(S,k);
					c=getchar();
					continue;
				}
				break;
				case '&':{
					k=stack_pop(S)&stack_pop(S);
					stack_push(S,k);
					c=getchar();
					continue;
				}
				break;
																				
				} 
		
		
		}
	}
	printf("%d\n",stack_pop(S));
}


int main(){
	int t=10;
	while(t--){
		evaluate();
	}
	return 0;
}

















