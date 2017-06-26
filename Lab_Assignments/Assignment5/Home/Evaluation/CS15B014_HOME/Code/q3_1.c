/*D TEJA VARDHAN REDDY CS15B014  18/9/16*/
/* INFIX TO POSTFIX*/
#include"stack.h"
#include<stdio.h>
#include<stdlib.h>
int main(){
	
	int p[256];
	p['(']=0;
	p['|']=1;
	p['^']=2;
	p['&']=3;
	p['-']=4;
	p['+']=4;
	p['%']=5;
	p['/']=5;
	p['*']=5;
	char ch;
	int ewh=10;
	while(ewh--){
		stack*st=stack_new();
		
		ch=getchar();
		
		while(ch!='\n'){
			if(('a'<=ch && ch<='z')||('0'<=ch && ch<='9')){
				printf("%c",ch);
				ch=getchar();
				
				while(ch!=' ' && ch!='\n'){
					
					printf("%c",ch);
					ch=getchar();

				}
				
				
					printf(" ");
			}
			else{
				switch(ch){
					case '(':stack_push(st,ch);break;
					case ')':{
						int h=stack_pop(st);
						while(h!='('){
							char k=h;
							printf("%c ",k);
							h=stack_pop(st);
						}
						break;
					}
					case'+':case'-':case'*':case'/':case'&':case'|':case'^':case'%':{
						if(stack_is_empty(st))
							stack_push(st,ch);
						else{
							int count =0;
							int h=stack_pop(st);
							while(p[ch]<=p[h]){
								char k=h;
								printf("%c ",k);
								
								if(stack_is_empty(st)){
									count =1;
									break;
								}
								h=stack_pop(st);
							}
							if(count==0)
								stack_push(st,h);
							stack_push(st,ch);
						}
					}break;
				}
				ch=getchar();
			}
			if(ch == '\n'){
				
			}
			if(ch!='\n'){

				ch=getchar();
			}
			else{
				//printf(  "%d",stack_size(st));
				while(!stack_is_empty(st)){

				int h=stack_pop(st);
				char k=h;
				printf("%c ",k);
			}
			printf("\n");
			}
			
		}
		
	}
}
