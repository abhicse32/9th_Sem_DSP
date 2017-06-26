#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#include<string.h>
#include "stack.h"

int Perform(char,int,int);
bool isoperator(char);
int eval(char*);
bool isadigit(char);
int eval(char exp[200])
{

	stack* S=(stack*)malloc(sizeof(stack));
	S=stack_new();
	
	for(int i=0;i<strlen(exp);i++)
	{
	   if(exp[i]==' ')
	   {
	      continue;
	   }
	else if(isoperator(exp[i]) && (exp[i+1]==' ') || isoperator(exp[i]) && i==strlen(exp)-2)
	{
	   int operand2=stack_pop(S);
	   int operand1=stack_pop(S);
			
	   int result=Perform(exp[i],operand1,operand2);
	   stack_push(S,result);
	}
	else if(isadigit(exp[i]) || (isoperator(exp[i]) && (isadigit(exp[i+1]))))
	{	
	   int operand=0;
	   if(isoperator(exp[i]) && isadigit(exp[i+1]))
	   {		
	      while((i<strlen(exp) && isadigit(exp[i+1])))
	      {
		 operand=operand*10+(exp[i+1]-'0');
		 i++;
	      }
	     stack_push(S,-1*operand);
           }
	else
	{		
	   while(i<strlen(exp) && isadigit(exp[i]))
	   {		
              operand=operand*10 + (exp[i]-'0');
	      i++;
	   }
	   i--;
	   stack_push(S,operand);
        }
	}
		
	}
	
    return stack_pop(S);
}
			
bool isoperator(char c){

	if(c=='+' || c=='-' || c=='*' || c=='/' || c=='|' || c=='&' || c=='^' || c=='%'){
	return true;
	}
	else{
		return false;
	}
}

bool isadigit(char c){
	if(c>='0'&& c<='9') return true;
	else return false;
}

int Perform(char operator,int operand1,int operand2){
	
	if(operator=='+') return operand1+operand2;
	else if(operator=='-') return operand1-operand2;
	else if(operator=='*') return operand1*operand2;
	else if(operator=='/') return operand1/operand2;
	else if(operator=='|') return operand1 | operand2;
	else if(operator=='&') return operand1 & operand2;
	else if(operator=='^') return operand1 ^ operand2;
	else if(operator=='%') return operand1 % operand2;
	else{
		return -1;
	}
}
int main()
{
   int t=10;
   while(t>=0)
   {		
      char s[200];
      fgets(s,200,stdin);
      int result=eval(s);
      printf("%d\n",result);
      t--;
   }
   return 0;
}

		
