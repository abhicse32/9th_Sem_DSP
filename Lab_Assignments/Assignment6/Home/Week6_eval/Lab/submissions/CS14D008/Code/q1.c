#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_tree.h"
#include "stack.h"
#include <ctype.h>
#define size 1005

int precedence(char a) 				//we make a function which gives a precedence mapping for each operator
{
	if(a=='(')
		return 0;
	else if(a=='|'||a=='^'||a=='&')
		return 1;
	else if(a=='+'||a=='-')
		return 4;
	else if(a=='*'||a=='/'||a=='%')
		return 5;
	else
		return 6;
}

Node* maketree(char infix[size])
{
	int i,j;
	stack *operand=stack_new();
	stack *operator=stack_new();
	for(i=0,j=0;infix[i]!='\0';i++)
	{
		if(infix[i]==' ')					//if a space is the string from previous space till this is operand
		{
			int k;
			char *s=(char*)malloc((i-j)*sizeof(char));
			for(k=j;k<i;k++)
				s[k-j]=infix[k];
			s[k-j]='\0';
			Node* x=new_node(s);
			stack_push(operand,x);
			j=i+1;						//we set j to pos after space
		}
		else if(!isalnum(infix[i]))			//if s[i] is an operator
		{
			if(infix[i]=='-'&&isalnum(infix[i+1]))
				continue;
			if(precedence(infix[i])==6)		//if its a closing bracket
			{
				while(!stack_is_empty(operator))
				{
					Node* x=stack_pop(operator);			//we pop all operators till the opening bracket
					if(precedence(*(x->data))==0)
						break;
					else
					{
						Node* op2=stack_pop(operand);
						Node* op1=stack_pop(operand);
						x->left=op1;
						x->right=op2;
						stack_push(operand,x);	
					}
			}
				}
			else
			{
				while(!stack_is_empty(operator))		
				{
					Node* x=stack_pop(operator);			//if prec is greater than top element or it is opening bracket
					if(precedence(*(x->data))<precedence(infix[i])||precedence(infix[i])==0)		
					{
						
						char s[2];
						s[0]=infix[i];
						s[1]='\0';
						Node* y=new_node(s);
						stack_push(operator,x);
						stack_push(operator,y);
						break;
					}
					else					//if precedence>=top 
					{
						Node* op2=stack_pop(operand);
						Node* op1=stack_pop(operand);
						x->left=op1;
						x->right=op2;
						stack_push(operand,x);
					}
				}
				if(stack_is_empty(operator))
				{
					char s[2];
					s[0]=infix[i];
					s[1]='\0';
					Node* x=new_node(s);
					stack_push(operator,x);
				}
					
			}
			i++;			//we move i to next non space position(coz there wont be operand in i+1)
			j+=2;			//starting index of operator will be after 2 characters
		}
			
	}
	while(!stack_is_empty(operator))			//we pop all remaining operators
	{
			Node* x=stack_pop(operator);
			Node* op2=stack_pop(operand);
			Node* op1=stack_pop(operand);
			x->left=op1;
			x->right=op2;
			stack_push(operand,x);
	}

	return stack_pop(operand);
}

int main(int argc, char const *argv[])
{
	char infix[size];	
	fgets(infix,size-1,stdin);
	int len = strlen(infix);
	infix[len-1]=' ';
	infix[len]='\0';
	// call your function
	Node* root=maketree(infix);
	print_preorder(root);
	printf("\n");
	print_postorder(root);
	printf("\n");
	return 0;
}
