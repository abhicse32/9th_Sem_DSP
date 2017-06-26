#include<stdio.h>
#include"stack.h"
#include<string.h>

int main()
{
	int t;
	int i;
	//Take no. of testcases
	scanf("%d",&t);
	
	for(i=0;i<t;i++)
	{
		int j; 
		//Initialize stack
		stack *S = stack_new() ;
		char exp[10000] ;
		scanf("%s",exp); //Take Input
		
		int exp_l = strlen(exp) ;		
		int flag = 1 ; //flag =1 indicates balanced expression
		for(j=0;j<exp_l;j++) //Traverse expression
		{
			if(exp[j] == '{' || exp[j] == '[' || exp[j] == '(') //If opening bracket encountered --> push
				stack_push(S,(int)exp[j]) ;
			else if(stack_is_empty(S) == false) //If closing bracket encountered with opening bracket of same type on stack top --> pop opening bracket
			{
				if( (exp[j] == '}' && S->top->head->data == (int)'{') ||(exp[j] == ')' && S->top->head->data == (int)'(') ||(exp[j] == ']' && S->top->head->data == (int)'[') )
				{
					int x = stack_pop(S) ;
				}
			}		
			else //Exit --> as expression is invalid
			{
				flag = 0 ;
				break ;
			}	
		}
		//Check whether stack is not empty
		if(flag != 0 && stack_is_empty(S) == false)
		{
			flag = 0;	
		}
		//Print flag
		printf("%d\n",flag);
	}
}
