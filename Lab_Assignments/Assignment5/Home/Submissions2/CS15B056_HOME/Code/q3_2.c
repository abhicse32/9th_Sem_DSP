//evaluates postscript expression
//author - Sarthak Pandey
//CS15B056

#include <stdio.h>
#include <stdlib.h>
#include "List.h"
#include "stack.h"
#include <string.h>

int main ()
{
	stack *stk;
	stk=stack_new();
	
	
	char a[1000];
	while(fgets(a,999,stdin)!=NULL)
	{
	int i,j=0,k=0;
	a[strlen(a)-1]='\0';
	char temp[1000][7];
	for(i=0;a[i]!='\0';i++)                                                                       //this loop converts the input string to smaller strings of either operator or digits
	{
	
		if (a[i]!=' ')
		{
			temp[k][j]=a[i];
			j++;
			if (a[i+1]=='\0')
			{
				temp[k][j]=='\0';
				k++;
			}
		}
		else if (a[i]==' ')
		{
			temp[k][j]='\0';
			j=0;
			k++;
		}
	}
	
	for (i=0;i<k;i++)          
	{
		if ((temp[i][0]>=48&&temp[i][0]<=57)||(temp[i][0]=='-'&&(temp[i][1]>=48&&temp[i][1]<=57)))        //If a number , then push in stack
		{
			int l=atoi(temp[i]);
			stack_push(stk,l);	
		}
		else
			{
				int t1,t2,t3;
				t1=stack_pop(stk);
				t2=stack_pop(stk);
				if (temp[i][0]=='+')
				{
					t3=t1+t2;
				}
				else if (temp[i][0]=='*')                                              //If an operator , then evaluate
					t3=t1*t2;
				else if (temp[i][0]=='-')
					t3=t2-t1;
				else if (temp[i][0]=='/')
					t3=t2/t1;
				else if (temp[i][0]=='&')
					t3=t1&t2;
				else if (temp[i][0]=='|')
					t3=t1|t2;
				else if (temp[i][0]=='%')
					t3=t2%t1;
				else if (temp[i][0]=='^')
					t3=t1^t2;
				stack_push(stk,t3);
			}
			
	}
	printf ("%d\n",stack_pop(stk));                                                                //prints the final answer
	}
	return 0;
}
					
