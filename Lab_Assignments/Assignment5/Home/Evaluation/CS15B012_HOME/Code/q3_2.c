#include "stack.h"
#include "List.h"
#include <stdio.h>
#include <stdlib.h>

int oprend(char x,char z)
{
	/* these are the list of operends used in the program*/
	/* z is introduced to save the negative values*/
	if(z!='p')
	{
	if((x=='+'||x=='-'||x=='/'||x=='*'||x=='%'||x=='&'||x=='|'||x=='^')&&(z==' '))
	return 1;
	else
	return 0;
	}
	else
	{
	if(x=='+'||x=='-'||x=='/'||x=='*'||x=='%'||x=='&'||x=='|'||x=='^')
	return 1;
	else
	return 0;	
	
	}
}


int main()
{
int l;
for(l=0;l<10;l++)
{	char* str;
	int i;
	str=(char*)malloc(sizeof(char)*1000);
	stack* stk;
	stk=stack_new();
	/* storing the expression in the str*/
	scanf(" %[^\n]s",str);
	i=0;
	long int y;
	
	while(str[i]!='\0')
	{
	  /* here if we take care of end conditions*/
		char x,z;
		x=str[i];
		if(str[i+1]!='\0')
		{
		z=str[i+1];}
		else
		{
		 z='p';
		}
	
		if(oprend(x,z))
		{
			int b;
			b=(long int )stack_pop(stk);
			int a;
			a=(long int )stack_pop(stk);
						
			switch(x)
			{
				case '+':	y=a+b;
							stack_push(stk,y);
							break;
				case '*':	y=a*b;
							stack_push(stk,y);
							break;							
				case '/':	y=a/b;
							stack_push(stk,y);
							break;
				case '-':	y=a-b;
							stack_push(stk,y);
							break;
				case '%':	y=a%b;
							stack_push(stk,y);
							break;
				case '&':	y=a&b;
							stack_push(stk,y);
							break;
				case '|':	y=a|b;
							stack_push(stk,y);
							break;
				case '^':	y=a^b;
							stack_push(stk,y);
							break;
			}

			}
		else 
		
		{	int sum=0;
			int c=1;
			while(x!=' ')// Here we are taking each character at a time so we have a loop to take all digits
			{	if(x=='-')
				{c=0;
				i++;
				x=str[i];
				}
				else
				{
				sum=10*sum+(long int)x-48;
				i++;
				x=str[i];}
			}	
			if(sum!=0)
			if(c==0)	
			stack_push(stk,-sum);
			else
			stack_push(stk,sum);
	
		}
		i++;
		x=str[i];
	}
	printf("%ld\n",y);
	}
return 0;
}

