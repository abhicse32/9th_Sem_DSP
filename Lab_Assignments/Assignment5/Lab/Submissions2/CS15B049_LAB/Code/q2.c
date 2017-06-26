
/*
* Lab assignment 5 q2
* cs15b049 lokesh koshale

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include "stack.h"

//if not match push
int Match(stack* s,char curr); 

//if s1 close s2 then true
bool Closed(char s1,char s2);


int main()
{
	//test cases	
	int t;
	scanf("%d",&t);

	//iterarting for t times
	while(t>0)
	{
		char str[1000];		//array to store in put
		scanf("%s",str);

		stack *s = stack_new();		//new stack
		

		//if the no of element is odd no matching
		if(strlen(str)%2==1)
		{
			printf("-1\n");	
		}
		else
		{
			int i=0;	//counter 
	
			//iterating till last element and removing the brackets which are already closed 
			while(str[i]!='\0')
			{
				int flag = Match(s,str[i]);	//checking match with str[i] and pop of s
				
				if(flag==0)	//if not match
				{
					stack_push(s,(int)str[i]);	//push str[i]
				}
					
				i++;	//increment counter
			}//end while


			int size = stack_size(s);  //no of barckets un matched
			int n=0;	//no of open brackets
		
			//from last if there is open bracket increment till no element or no open brackets
			while(stack_is_empty(s)==false&& (char)stack_pop(s)=='{')		
			{
				n++;
			}		
			
			//
			int ans = (size/2)+(n%2) ;

			printf("%d\n",ans);			
			
		}//end else	

		t--;  

	}//end while

}//end main

//to find the match bw curr and s
int Match(stack* s,char curr)
{
	if(stack_size(s)==0)
	{
		return 0;	

	}
	else
	{
		
		char a1 = (char)stack_pop(s);	//poping from stack

		if( Closed(a1,curr)==false )	//if pop and curr do not close eachother
		{
			stack_push(s,(int)a1);	//push poped element
			return 0;		//flag to push curr
		}
		else
		{
			return 1;	//there is a match	
		}
	}//end if else
}//end Match

//to check if s1 closes s2
bool Closed(char s1,char s2)
{
	//if s1 and s2 closes return true
	
	if(s1=='{'&&s2=='}')
	{
		return true;
	}
	else
	{
		return false; //else false
	}
}//end fn

