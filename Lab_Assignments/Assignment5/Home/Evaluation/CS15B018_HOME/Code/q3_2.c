//evaluating a postfix expression
#include<stdio.h> 
#include<stdlib.h>
#include<string.h>       
#include<ctype.h>
#include"List.h"
#include"stack.h"
 
int main()
{                        
 	
 	int j;
	for(j = 0; j < 10; j++)						//giving the no. of test cases
	{
        	char exp[100];
        	int x[100];	
		fgets(exp, 99, stdin);					//scanning elements into exp
		int len = strlen(exp);
		exp[len-1]='\0';
 		stack* st1 = stack_new();
 		stack* st2 = stack_new();
 		int x1, x2;
 		int i = 0;
 		while(exp[i] != '\0')					//knowing the ascii value of each variable
 		{
 			x[i] = exp[i] - '0';
 			i++;
 		}
 		
 		i = 0;
 		while(exp[i] != '\0')					//converting every element after '-' into negative numbers till space 
 		{
 			
 			if(exp[i] == '-' && exp[i+1] != ' ')
 			{
 				while(exp[i+1] != ' ')
 				{
 					x[i+1] = -1 * x[i+1];
 					i++;
 				}
 			}
 			i++;
 		}
 		
 		i = 0;
 		while(exp[i] != '\0')
 		{
 			int a, b, c, d;
 			if(exp[i] == ' ');				//ignoring if given a space or '-' followed by ' ' 
 			else if(exp[i] == '-' && exp[i+1] != ' ');
  			else if(isdigit(exp[i]))
  			{ 
  				stack_push(st2, x[i]);
  				while(exp[i + 1] != ' ')		//converting successive numbers as a single number 
  				{
  					stack_push(st2, x[i + 1]);
  					i++;
  				}
  				int k = 1;
  				while(stack_size(st2) != 1)
  				{
  					a = stack_pop(st2);
  					b = stack_pop(st2) * 10 * k;
  					c = a + b;
  					stack_push(st2, c);
  					k = k * 10;
  				}
  				d = stack_pop(st2);
  				stack_push(st1, d);
  			}
  			else
  			{	        
   				x2 = stack_pop(st1);					//popping two numbers operating the operands and pushing it again into stack
   				x1 = stack_pop(st1);
   				switch(exp[i])
   				{
   					case '+' : stack_push(st1, x1 + x2);	break;
   					case '-' : stack_push(st1, x1 - x2);	break;
   					case '*' : stack_push(st1, x1 * x2);	break;
   					case '/' : stack_push(st1, x1 / x2);	break;
   					case '&' : stack_push(st1, x1 & x2);	break;
   					case '^' : stack_push(st1, x1 ^ x2);	break;
   					case '|' : stack_push(st1, x1 | x2);	break;
   					case '%' : stack_push(st1, x1 % x2);	break;
   				}
  			}
  			fflush(stdout);
  			i++;
 		}		
 		printf("%d\n",stack_pop(st1));		//popping and printing the last element
 	}
}
