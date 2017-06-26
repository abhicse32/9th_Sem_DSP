#include<stdio.h>
#include"List.h"
#include"stack.h"




void main()
{
	char exp[100];
	scanf("%s",&exp[100]);
	stack* s;
	s=(stack*)malloc(sizeof(stack));

//float eval(char exp)
//{
   int x,y;
	float result;
    
    int i=0;
 while(exp[i]!='\0')
	{
        if (exp[i]!='+' || exp[i]!='-'|| exp[i]!='*' || exp[i]!='/' )
            {
		stack_push(s,exp[i]);
		i++;
	    } 
       
        else
        {	
            
		x= stack_pop(s);
            
 		y= stack_pop(s);
            if(exp[i] == '+')
		{
		result=y+x;
		stack_push(s, result); 
		}
            if(exp[i] == '-')
		{
		result=y-x;
		stack_push(s, result);
		}
             if(exp[i] == '*')
		{
		result=y*x;
		stack_push(s,result);
		}
             if(exp[i] == '/')
		 {
		result=y/x;
		stack_push(s,result); 
		} 
	i++;
        }

    
}

printf("%f",stack_pop(s));


}





