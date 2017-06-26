#include<stdio.h>
#include<string.h>
#include"stack.h"
#include"List.h"
int stack_top(stack* s)
{
	int top;
	top=stack_pop(s);
	stack_push(s,top);
	return top;
}
int check(char a,char b)
{
	if(a=='^')
	return 1;
	else if(a=='|')
	return 0;
	else if(a=='&')
	return 2;
	else if(a=='+')
	return 3;
	else if(a=='-' && b=='\0')
	return 4;
	else if(a=='*')
	return 5;
	else if(a=='/')
	return 6;
	else if(a=='%')
	return 7;
	return -1;
}
int main()
{
	char a[1000];
	stack *st;
	st=stack_new();
	while(fgets(a,1000,stdin)!=NULL)
	{	
		a[strlen(a)-1] ='\0';
		char *token;
		const char s[2]= " ";
		token = (char *)strtok(a, s);
		while( token != NULL ) 
   		{
   			int b;
   			int c,d;
   			d=stack_pop(st);
   			c=stack_pop(st);
   			switch(check(token[0],token[1]))
   			{
   				case 0:
   				stack_push(st,c|d);
   				break;
   				case 1:
   				stack_push(st,c^d);
   				break;
   				case 2:
   				stack_push(st,c&d);
   				break;
   				case 3:
   				stack_push(st,c+d);
   				break;
   				case 4:
   				stack_push(st,c-d);
   				break;
   				case 5:
   				stack_push(st,c*d);
   				break;
   				case 6:
   				stack_push(st,c/d);
   				break;
   				case 7:
   				stack_push(st,c%d);
   				break;
   				case -1:
   				stack_push(st,c);
   				stack_push(st,d);
   				b=atoi(token);
   				stack_push(st,b);
   				break;
   				default:
   				break;
   			}
    	  	token = (char *)strtok(NULL, s);
    	}	
    	//while(!stack_is_empty(st))
    		int b;
			b=stack_pop(st);
			printf("%d",b);
   	 	printf("\n");
    }
}
