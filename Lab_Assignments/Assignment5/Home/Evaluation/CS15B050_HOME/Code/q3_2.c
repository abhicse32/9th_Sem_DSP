#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"List.h"
#include"stack.h"
#define size 1000

int is_operand(char ch)											//Checks if the given character is a digit
{
	if(ch>=48 && ch<=57) return 1;
	return 0;
}

int is_operator(char ch)										//Checks if the given character is an operator
{
	if(ch=='*' || ch=='/' || ch=='+' || ch=='-' || ch=='|' || ch=='%' || ch=='&' || ch=='^') return 1;
	return 0;
}

int Post_eval(char exp[])
{
	stack* stk;
	stk=stack_new();
	int i;
	int j;
	int num;
	int sum=0;
	for(i=0;exp[i]!='\0';i++)											//Loops till end of string
	{
		if(exp[i]!=' ' && exp[i]!='\n')
		{
			if(is_operator(exp[i]))										//Checks if the given character is an operator
			{
				if(exp[i]=='-')											
				{
					if(exp[i+1]!=' ' && exp[i+1]!='\n')					//Checks whether it is a negative number or just an operator
					{
						i++;
						while(exp[i]!=' ' && exp[i]!='\n')
						{	
							sum=sum*10 + (exp[i]-'0');					//As it is read character by character store its original value in 																			  sum by doing this operation
							i++;
						}
						num=sum * -1;									//As it is a negative number num=sum*(-1)
						stack_push(stk,num);							//Now push it in the stack
						sum=0;											//Update sum=0 for the next number
						continue;
					}
				}
				int val1=stack_pop(stk);								
				int val2=stack_pop(stk);
				switch(exp[i])											//Does each operation accordingly
				{
					case '+': stack_push(stk, val2 + val1); 
							  break;
					case '-': stack_push(stk, val2 - val1); 
							  break;
					case '*': stack_push(stk, val2 * val1); 
							  break;
					case '/': stack_push(stk, val2/val1);   
							  break;
					case '%': stack_push(stk, val2 % val1);   
							  break;
					case '&': stack_push(stk, val2 & val1);   
							  break;
					case '|': stack_push(stk, val2 | val1);   
							  break;
					case '^': stack_push(stk, val2 ^ val1);   
							  break;
				}
				i++;
			}
			else
			{
				while(exp[i]!=' ' && exp[i]!='\n')				//Checks if it is end of expression or exp[i]=' '
				{	
					sum=sum*10 + (exp[i]-'0');
					i++;
				}
				num=sum;										//Storing sum in num
				stack_push(stk,num);
			}
		}
		sum=0;
	}
	return stack_pop(stk);										//Final answer 
}

int main()
{
	char exp[size];
	while(fgets(exp,size,stdin)!=NULL)							//Takes input til EOF
	{
		int ans;
		ans=Post_eval(exp);
		printf("%d\n",ans);
	}
	return 0;
}
