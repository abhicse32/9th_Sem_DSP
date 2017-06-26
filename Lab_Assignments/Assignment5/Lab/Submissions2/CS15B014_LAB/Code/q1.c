/*D TEJA VARDHAN REDDY CS15B014 16/9/16*/
/*to check for balanced sequence*/
#include"stack.h"
#include<stdio.h>
int main(){
	int t;
	scanf("%d",&t);
	char ch=getchar();
	while(t--){
		int ans=1;
		stack*s=stack_new();
		ch=getchar();
		while(ch!='\n'){
			//printf("%c",ch);
			if(ch=='{'||ch=='('||ch=='[')		// PUSH IF IT IS OPENING BRACKET
				stack_push(s,ch);
			else								// POP AND CHECK IF IT IS CORRESPONDING OPENING BRACKET FOR CLOSING BRACKET 
			{
				if(stack_is_empty(s))
				{	
					//printf("fsdd");
					ans=0;
					break;
				}
				
				if(ch=='}'&& stack_pop(s)=='{'){			
					ch=getchar();
					continue;
					
				}											//IF TRUE CONTINUE
				else if(ch==']'&& stack_pop(s)=='[')
				{
					ch=getchar();
					continue;
				}
				else if(ch==')'&& stack_pop(s)=='(')
				{
					ch=getchar();
					continue;
				}
				else										//ELSE BREAK
				{
					ans=0;
					
					break;
				}
			}
			ch=getchar();
		}
		if(ans==1)
		{
			if(stack_is_empty(s)==0)
				ans=0;
		}
		
		while(ch!='\n'){
			ch=getchar();
		}
		printf("%d\n",ans);
		
	}
}
