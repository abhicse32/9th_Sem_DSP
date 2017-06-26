/* Program that converts a postfix expression
	G.Pranav	CS15B015	18-9-2016	*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#include "List.h"
int main(){
	int xyz;
	for(xyz=0;xyz<10;xyz++){	//running the program 10 times
	int ans;
	stack *stackptr=stack_new();		//declaring a stack
	int num=0;
	char temp;
	int flag=0;
	temp=getchar();			//inputting the expression in the form of characters
	if(isdigit(temp)){		//checking whether the character is number or not
		while(isdigit(temp)){
			flag=1;
			int dum=temp-'0';		//converting the character into number
			num=num*10+dum;
			temp=getchar();
		}
	}
	else if(temp=='-'){		//if an operator is encounterd two elements are popped
									//result is evaluated and then pushed into the stack
		int dum2=0;
		temp=getchar();
		if(temp==' ') temp='-';		//distinguishing between unary and binary -
		else{
			while(isdigit(temp)){
				dum2=1;
				flag=1;
				int dum=temp-'0';
				num=num*10+dum;
				temp=getchar();
		}
		if(dum2==1) num=-1*num;
		}
	}
	while(1){
		if(flag==1){
			stack_push(stackptr,num);
		}
		else if((temp!=' ')&&(temp!='\0')&&(temp!='\n')){
			int op2=stack_pop(stackptr);
			int op1=stack_pop(stackptr);
			int res;
			if(temp=='+') res=op1+op2;
			else if(temp=='-') res=op1-op2;
			else if(temp=='*') res=op1*op2;
			else if(temp=='/') res=op1/op2;
			else if(temp=='|') res=op1|op2;
			else if(temp=='&') res=op1&op2;
			else if(temp=='^') res=op1^op2;
			else if(temp=='%') res=op1%op2;
			stack_push(stackptr,res);	
		}
		num=0;
		flag=0;
		temp=getchar();
		if(temp==' ') temp=getchar();
		if((temp=='\0')||(temp=='\n')) break;		//terminating the program when \n is encountered
		else if(isdigit(temp)){
			while(isdigit(temp)){
				flag=1;
				int dum=temp-'0';
				num=num*10+dum;
				temp=getchar();
			}
		}
		if(temp=='-'){
			int dum2=0;
			temp=getchar();
			if(temp==' ') temp='-';
			else{
				while(isdigit(temp)){
					dum2=1;
					flag=1;
					int dum=temp-'0';
					num=num*10+dum;
					temp=getchar();
			}
			if(dum2==1) num=-1*num;
			}
		}
	}
	ans=stack_pop(stackptr);
	printf("%d\n",ans);
}
	return 0;
}